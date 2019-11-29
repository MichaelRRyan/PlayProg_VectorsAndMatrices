#pragma once

#include <string>
#include <iostream>

namespace cube
{
	class Vector2f
	{
	public:
		// The class has two variables x and y
		float x;
		float y;

		// Constructor 1
		Vector2f();

		// Constructor 2
		Vector2f(float t_x, float t_y);

		//// Constructor 3
		//Vector3(Vector3 &V);

		float Length();
		float LengthSquared();
		void Normalise();

		Vector2f operator +(Vector2f V);
		Vector2f operator -(Vector2f V);
		Vector2f operator -(); // An overloaded operator - to return the negation of a single vector
		float operator *(Vector2f V); // Dot product of a vector
		Vector2f operator *(double k);
		Vector2f operator *(float k);
		Vector2f operator *(int k);

		std::string toString();
	};
}
