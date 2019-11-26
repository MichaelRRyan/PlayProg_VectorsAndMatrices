#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <string>

namespace cube
{
	class Vector3f
	{
	public:
		// The class has three variables x, y and z 
		float x;
		float y;
		float z;

		// Constructor 1
		Vector3f();

		// Constructor 2
		Vector3f(float x1, float y1, float z1);

		//// Constructor 3
		//Vector3(Vector3 &V);

		float Length();
		float LengthSquared();
		void Normalise();
		
		Vector3f operator +(Vector3f V);
		Vector3f operator -(Vector3f V);
		Vector3f operator -(); // An overloaded operator - to return the negation of a single vector
		float operator *(Vector3f V);
		Vector3f operator *(double k);
		Vector3f operator *(float k);
		Vector3f operator *(int k);
		Vector3f operator ^(Vector3f V2);

		std::string toString();
	};
}

#endif // !VECTOR3F_H