#pragma once

#include <string>

namespace cube
{
	class Vector3
	{
	public:
		// The class has three variables x, y and z 
		double x;
		double y;
		double z;

		// Constructor 1
		Vector3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		// Constructor 2
		Vector3(double x1, double y1, double z1)
		{ // To allow other values for X, Y and Z to be declared
			x = x1;
			y = y1;
			z = z1;
		}

		// Constructor 3
		Vector3(Vector3 &V)
		{  // To allow other values for X, Y and Z to be declared
			x = V.x;
			y = V.y;
			z = V.z;
		}

		double Length()
		{  // A method to return the length of the vector
			return (double)sqrt(x * x + y * y + z * z);
		}
		double LengthSquared()
		{  // A method to return the length squared of the vector
			return (x * x + y * y + z * z);
		}

		void Normalise()
		{  // A method to reduce the length of the vector to 1.0 
			// keeping the direction the same
			if (Length() > 0.0)
			{  // Check for divide by zero
				double magnit = Length();
				x /= magnit;
				y /= magnit;
				z /= magnit;
			}
		}

		Vector3 operator +(Vector3 V)
		{  // An overloaded operator + to return the sum of 2 vectors
			return { x + V.x, y + V.y, z + V.z };
		}

		Vector3 operator -(Vector3 V)
		{ // An overloaded operator - to return the difference of 2 vectors
			 return { x - V.x, y - V.y, z - V.z };
		}

		// An overloaded operator - to return the negation of a single vector
		Vector3 operator -()
		{
			 return { -x, -y, -z };
		}

		double operator *(Vector3 V)
		{// An overloaded operator * to return the scalar product of 2 vectors
			return (x * V.x + y * V.y + z * V.z);
		}

		Vector3 operator *(double k)
		{// An overloaded operator * to return the product of a scalar by a vector
			return { x * (float)k, y * (float)k, z * (float)k };
		}

		Vector3 operator *(float k)
		{// An overloaded operator * to return the product of a scalar by a vector
			return { x * k, y * k, z * k };
		}

		Vector3 operator *(int k)
		{// An overloaded operator * to return the product of a scalar by a vector
			return { x * k, y * k, z * k };
		}

		Vector3 operator ^(Vector3 V2)
		{// An overloaded operator ^ to return the vector product of 2 vectors
			return { y * V2.z - z * V2.y, z * V2.x - x * V2.z, x * V2.y - y * V2.x };
		}

		std::string toString()
		{
			return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
		}

	};
}

