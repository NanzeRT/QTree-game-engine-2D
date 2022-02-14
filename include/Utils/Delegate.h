#pragma once
#include <functional>
#include <algorithm>
#include <utility>
#include <vector>

namespace utils
{
    namespace detail
    {

        template <typename R, typename... Args>
        struct multifunction_traits
        {
            typedef R return_type;
        };

        template <typename R, typename Arg>
        struct multifunction_traits<R, Arg>
        {
            typedef R return_type;
            typedef Arg argument_type;
        };

        template <typename R, typename Arg1, typename Arg2>
        struct multifunction_traits<R, Arg1, Arg2>
        {
            typedef R return_type;
            typedef Arg1 first_argument_type;
            typedef Arg2 second_argument_type;
        };

        template <typename R, typename... Args>
        struct call_helper
        {
            template <typename... Ts>
            static R call(
                std::vector<std::function<R(Args...)>> const &listeners,
                Ts &&...args)
            {
                R ret;
                for (auto listener : listeners)
                {
                    ret = listener(std::forward<Ts>(args)...);
                }
                return ret;
            }
        };

        template <typename... Args>
        struct call_helper<void, Args...>
        {
            template <typename... Ts>
            static void call(
                std::vector<std::function<void(Args...)>> const &listeners,
                Ts &&...args)
            {
                for (auto listener : listeners)
                {
                    listener(std::forward<Ts>(args)...);
                }
            }
        };

    } // namespace detail

    template <typename R, typename... Args>
    class Delegate;

    template <typename R, typename... Args>
    class Delegate<R(Args...)> : public detail::multifunction_traits<R, Args...>
    {
    public:
        // Uniquely identifies a listener in this Delegate.
        // This is an opaque type, meaning it can only be created and accessed
        // from within this class. The outside world can only store them.
        class handle
        {
            friend class Delegate;
            handle(std::size_t id) noexcept : id(static_cast<unsigned>(id)) {}

            // We assume that numeric_limits<unsigned>::max() handles are enough.
            unsigned id;

        public:
            handle() {}
        };

        Delegate() = default;
        Delegate(Delegate const &) = default;
        Delegate(Delegate &&) = default;
        Delegate &operator=(Delegate const &) = default;
        Delegate &operator=(Delegate &&) = default;
        ~Delegate() = default;

        template <typename F>
        handle operator+=(F listener)
        {
            return add(listener);
        }

        template <typename F>
        handle add(F listener)
        {
            listeners.push_back(listener);
            handle_lookup.push_back(upper_id);
            return handle{upper_id++};
        }

        void operator-=(handle handle)
        {
            remove(handle);
        }

        void remove(handle handle)
        {
            auto i = std::lower_bound(handle_lookup.begin(), handle_lookup.end(), handle.id) - handle_lookup.begin();

            if (i >= handle_lookup.size() || handle_lookup[i] != handle.id)
                return;

            listeners.erase(listeners.begin() + i);
            handle_lookup.erase(handle_lookup.begin() + i);
        }

        template <typename... Ts>
        R operator()(Ts &&...args) const
        {
            return detail::call_helper<R, Args...>::call(listeners, std::forward<Ts>(args)...);
        }

    private:
        std::vector<std::function<R(Args...)>> listeners;
        std::vector<std::size_t> handle_lookup;
        std::size_t upper_id = 0;
    };
}
