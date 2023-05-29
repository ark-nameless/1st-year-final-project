#pragma once 

#include <iostream>

namespace STAR
{
	namespace GEOMETRY
	{
		struct Size
		{
			float w, h;

			Size(float _w = 0, float _h = 0) : w(_w), h(_h){}
			~Size(){}

			Size& operator+=(const Size &rhs){
				w += rhs.w;
				h += rhs.h;

				return *this;
			}
			Size& operator-=(const Size &rhs){
				w -= rhs.w;
				h -= rhs.h;

				return *this;
			}

			friend std::ostream &operator<<(std::ostream &os, Size &size)
			{
				os << "Width: " << size.w << ", Height: " << size.h << "\n";
				return os;
			}
			friend bool operator==(const Size &rhs, const Size &lhs)
			{
				if (rhs.w == lhs.w && rhs.h == rhs.h)
					return true;
				return false;
			}
		};

		inline Size operator+ (const Size &lhs, const Size &rhs)
		{
			return Size(lhs.w + rhs.w, lhs.h + rhs.h);
		}
		inline Size operator- (const Size &lhs, const Size &rhs)
		{
			return Size(lhs.w - rhs.w, lhs.h - rhs.h);
		}
		inline Size operator*(const Size &lhs, const float &factor)
		{
			return Size(lhs.w * factor, lhs.h * factor);
		}

		const Size SIZE_ZERO = { 0.0f, 0.0f };
	}
}

