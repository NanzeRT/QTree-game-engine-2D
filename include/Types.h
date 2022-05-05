#pragma once
#include <cmath>
#include <iostream>

struct Vector2Int
{
    int x, y;
    operator bool() const { return !(x == 0 && y == 0); }
    Vector2Int operator+(const Vector2Int &other) const { return {x + other.x, y + other.y}; }
    Vector2Int operator-(const Vector2Int &other) const { return {x - other.x, y - other.y}; }
    Vector2Int operator*(const int &k) const { return {x * k, y * k}; }
    Vector2Int operator/(const int &k) const { return {x / k, y / k}; }
    Vector2Int operator*(const float &k) const { return {(int)(x * k), (int)(y * k)}; }
    Vector2Int operator/(const float &k) const { return {(int)(x / k), (int)(y / k)}; }
    friend float abs(const Vector2Int &a) { return std::sqrt(a.x * a.x + a.y * a.y); }
    friend std::ostream &operator<<(std::ostream &st, const Vector2Int &a) { return st << '(' << a.x << ", " << a.y << ')'; }
};
