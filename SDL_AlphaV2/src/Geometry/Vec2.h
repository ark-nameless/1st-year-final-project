#pragma once 

#include <math.h>
#include <iostream>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f


namespace STAR
{
	namespace GEOMETRY
	{

		struct Vector2
		{
			float x;
			float y;

			Vector2(float _x = 0.0f, float _y = 0.0f)
				: x(_x), y(_y){}

			float MagnitudeSqr(){
				return (float)x * x + y * y;
			}

			float Magnitude(){
				return (float)sqrt(x*x + y*y);
			}

			Vector2 Normalize(){
				float mag = Magnitude();

				return Vector2(x / mag, y / mag);
			}

			Vector2& operator+=(const Vector2 &rhs){
				x += rhs.x;
				y += rhs.y;

				return *this;
			}
			Vector2& operator-=(const Vector2 &rhs){
				x -= rhs.x;
				y -= rhs.y;

				return *this;
			}
			Vector2 &operator-(){
				this->x = (x<0)?x:-x;
				this->y = (y<0)?y:-y;
				return *this;
			}
			Vector2 &operator+(){
				this->x = (x < 0)? x * -1 : x;
				this->y = (y < 0)? y * -1: y;
				return *this;
			}

			bool operator==(const Vector2 &vec){
				if (x == vec.x && y == vec.y)
					return true;
				return false;
			}

			friend std::ostream &operator<<(std::ostream &os, Vector2 &vec)
			{
				os << "X: " << vec.x << ", Y: " << vec.y << ", Magnitude: " << vec.MagnitudeSqr() << "\n";
				return os;
			}
			friend bool operator==(const Vector2 &rhs, const Vector2 &lhs)
			{
				if (rhs.x == lhs.x && rhs.y == rhs.y)
					return true;
				return false;
			}
		};

		inline Vector2 operator+ (const Vector2 &lhs, const Vector2 &rhs)
		{
			return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
		}
		inline Vector2 operator- (const Vector2 &lhs, const Vector2 &rhs)
		{
			return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
		}
		inline Vector2 operator*(const Vector2 &lhs, const float &rhs)
		{
			return Vector2(lhs.x * rhs, lhs.y * rhs);
		}

		inline Vector2 RotateVector(Vector2 &vec, float angle)
		{
			float radangle = (float)(angle*DEG_TO_RAD);

			return Vector2((float)(vec.x * cos(radangle) - vec.y * sin(radangle)),
				(float)(vec.x * sin(radangle) + vec.y * cos(radangle)));
		}

		const Vector2 VEC2_ZERO = { 0.0f, 0.0f };
		const Vector2 VEC2_ONE = { 1.0f, 1.0f };
		const Vector2 VEC2_UP = { 0.0f, 1.0f };
		const Vector2 VEC2_RIGHT = { 1.0f, 0.0f };


	}
}