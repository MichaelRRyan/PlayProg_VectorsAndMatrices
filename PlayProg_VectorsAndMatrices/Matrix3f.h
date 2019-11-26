#ifndef MATRIX3F_H
#define MATRIX3F_H

#include <iostream>
#include "Vector3f.h"

const float PI{ 3.14159265359f };

namespace cube
{
	class Matrix3f
	{
	public:
		// Constructor 1 create a zero matrix
		Matrix3f();
		Matrix3f(Vector3f Row1, Vector3f Row2, Vector3f Row3);
		Matrix3f(float _A11, float _A12, float _A13,
			float _A21, float _A22, float _A23,
			float _A31, float _A32, float _A33);

		Vector3f operator *(Vector3f V1);

		//Vector3f operator *(Vector3f V1, Matrix3f M1)
		//{// An overloaded operator * to return the  product of the matrix by a vector
		//	return { M1.A11 * V1.x + M1.A21 * V1.y + M1.A31 * V1.z,
		//		M1.A12 * V1.x + M1.A22 * V1.y + M1.A32 * V1.z,
		//		M1.A13 * V1.x + M1.A23 * V1.y + M1.A33 * V1.z };
		//}

		Matrix3f Transpose(Matrix3f M1);
		
		Matrix3f operator +(Matrix3f M);
		Matrix3f operator -(Matrix3f M);
		Matrix3f operator *(float x);
		Matrix3f operator *(Matrix3f M);
		

		static float Determinant(Matrix3f M1);
		Vector3f Row(int i);
		Vector3f Column(int i);
		
		static Matrix3f Inverse(Matrix3f M1);
		static Matrix3f Rotation(int _angle);
		static Matrix3f Translate(float dx, float dy);
		static Matrix3f Scale(float dx, float dy);

		Matrix3f operator -();

		static Matrix3f RotationX(float _angle);
		static Matrix3f RotationY(float _angle);
		static Matrix3f RotationZ(float _angle);

		static Matrix3f Scale3D(float dx);

	private:
		// The class has nine variables, 3 rows and 3 columns
		float A11;
		float A12;
		float A13;
		float A21;
		float A22;
		float A23;
		float A31;
		float A32;
		float A33;
	};
}


#endif // !MATRIX3F_H