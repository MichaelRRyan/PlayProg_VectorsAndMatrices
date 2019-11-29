#ifndef QUATERNION_H
#define QUATERNION_H

#include <string>
#include "Vector3f.h"

const float PI{ 3.14159265359f };

namespace cube
{
	class Quaternion
	{
	private:
		float x, y, z, w;

	public:
		Quaternion();

		Quaternion(float _w, float _x, float _y, float _z);

		Quaternion(float _w, Vector3f v);

		std::string toString();

		double modulus();
		
		Quaternion normalise();

		Quaternion conjugate();

		void fromAxisAngle(Vector3f axis, float angleRadian);

		Quaternion multiply(Quaternion _q);

		Quaternion copy();

		Vector3f rotate(Vector3f pt, int _angle);

		Quaternion operator +(Quaternion t_q);
		
		Quaternion operator -();
		
		Quaternion operator -(Quaternion t_q);
		
		Quaternion operator *(double s);
		
		Quaternion operator *(float s);
		
		Quaternion operator *(int s);

		Quaternion operator *(Quaternion t_q);
	};
}

#endif // !QUATERNION_H