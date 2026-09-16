#pragma once

#include <raylib.h>


inline Vector2 operator+(const Vector2& a, const Vector2& b){
    return {a.x + b.x, a.y + b.y};
}


inline Vector2 operator-(const Vector2& a, const Vector2& b){
    return {a.x - b.x, a.y - b.y};
}

inline Vector2 operator*(const Vector2& a, const float& b){
    return {a.x*b, a.y*b};
}

inline Vector2 operator*(const float& b, const Vector2& a){
    return {a.x*b, a.y*b};
}

inline Vector2& operator+=(Vector2& a, const Vector2& b){
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline Vector2& operator-=(Vector2& a, const Vector2& b){
    a.x -= b.x;
    a.y -= b.y;
    return a;
}