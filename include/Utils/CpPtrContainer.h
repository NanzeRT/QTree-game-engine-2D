#pragma once
#include <vector>
#include "Utils/cp_ptr.h"
#include "initializer_list"

#include <iostream>

namespace utils
{
    template<typename T>
    struct ptr_wrap
    {
        ptr_wrap(const T &obj)
            : val(obj.Clone())
        {
        }

        T *Get() { return val; }

    private:
        T *val;
    };

    template <typename T>
    class CpPtrContainer
    {
    public:
        CpPtrContainer() {}
        CpPtrContainer(const CpPtrContainer<T> &elements_)
        {
            Construct(elements_);
        }
        CpPtrContainer(const std::vector<std::unique_ptr<T>> &elements_)
        {
            Construct(elements_);
        }
        CpPtrContainer(const std::initializer_list<std::unique_ptr<T>> &elements_)
        {
            Construct(elements_);
        }
        CpPtrContainer(std::initializer_list<ptr_wrap<T>> &elements_)
        {
            Construct(elements_);
        }

        CpPtrContainer(CpPtrContainer&&) = default;

        const std::vector<std::unique_ptr<T>> &GetAll() { return elements; }

        T *Add()
        {
            T *b = elements.emplace_back(new T()).get();
            OnAdd(b);
            return b;
        }
        T *Add(const std::unique_ptr<T> &a)
        {
            T *b = elements.emplace_back(a->Clone()).get();
            OnAdd(b);
            return b;
        }
        T *Add(ptr_wrap<T> a)
        {
            T *b = elements.emplace_back(a.Get()).get();
            OnAdd(b);
            return b;
        }
        T *Add(const T &a)
        {
            T *c = a.Clone();
            T *b = elements.emplace_back(c).get();
            OnAdd(b);
            return b;
        }

        // can be optimized with boost::multi_index_container

        void Remove(T *a)
        {
            bool f = 1;
            for (int i = 0; i < elements.size(); ++i)
            {
                if (a == elements[i].get())
                {
                    elements.erase(elements.begin() + i);
                    --i;
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                f = 0;
            }
            // for (auto it = elements.begin(); it < elements.end(); ++it)
            // {
            //     if (a == it->get())
            //     {
            //         elements.erase(it);
            //         break;
            //     }
            // }
        }

        CpPtrContainer &operator=(const CpPtrContainer<T> &c)
        {
            Construct(c);
            return *this;
        }

        std::vector<std::unique_ptr<T>>::iterator begin() { return elements.begin(); }
        std::vector<std::unique_ptr<T>>::iterator end() { return elements.end(); }
        virtual ~CpPtrContainer() {}

    protected:
        std::vector<std::unique_ptr<T>> elements;
        virtual void OnAdd(T *a) = 0;

        void Construct(const CpPtrContainer<T> &elements_)
        {
            for (const auto &e : elements_.elements)
                Add(e);
        }
        void Construct(const std::vector<std::unique_ptr<T>> &elements_)
        {
            for (const auto &e : elements_)
                Add(e);
        }
        void Construct(const std::initializer_list<std::unique_ptr<T>> &elements_)
        {
            for (const auto &e : elements_)
                Add(e);
        }
        void Construct(std::initializer_list<ptr_wrap<T>> &elements_)
        {
            for (auto &e : elements_)
                Add(e);
        }

        void AddAll()
        {
            for (auto &b : elements)
                OnAdd(b.get());
        }
    };
}