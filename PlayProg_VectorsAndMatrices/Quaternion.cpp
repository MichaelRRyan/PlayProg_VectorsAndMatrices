#include "Quaternion.h"

using namespace cube;

cube::Quaternion::Quaternion()
{
	w = 0; x = 0; y = 0; z = 0;
}

cube::Quaternion::Quaternion(float _w, float _x, float _y, float _z)
{
	w = _w; x = _x; y = _y; z = _z;
}

cube::Quaternion::Quaternion(float _w, Vector3f v)
{
	w = _w; x = v.x; y = v.y; z = v.z;
}

float cube::Quaternion::getW() const
{
	return w;
}

float cube::Quaternion::getX() const
{
	return x;
}

float cube::Quaternion::getY() const
{
	return y;
}

float cube::Quaternion::getZ() const
{
	return z;
}

std::string cube::Quaternion::toString()
{
	return "(" + std::to_string(w) + "," + std::to_string(x) + "i," + std::to_string(y) + "j," + std::to_string(z) + "k)";
}

float cube::Quaternion::modulus()
{
	return sqrtf(w * w + x * x + y * y + z * z);
}

Quaternion cube::Quaternion::normalise()
{
	float m = w * w + x * x + y * y + z * z;
	if (m > 0.001f)
	{
		m = sqrtf(m);
		return Quaternion(w / m, x / m, y / m, z / m);
	}
	else
	{
		return Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
	}
}

Quaternion cube::Quaternion::conjugate()
{
	return Quaternion(w, -x, -y, -z);
}

void cube::Quaternion::fromAxisAngle(Vector3f axis, float angleRadian)
{
	float m = axis.Length();
	if (m > 0.0001f)
	{
		float ca = cosf(angleRadian / 2.0f);
		float sa = sinf(angleRadian / 2.0f);
		x = axis.x / m * sa;
		y = axis.y / m * sa;
		z = axis.z / m * sa;
		w = ca;
	}
	else
	{
		w = 1.0f; x = 0.0f; y = 0.0f; z = 0.0f;
	}
}

Quaternion cube::Quaternion::multiply(Quaternion _q)
{
	float nw = _q.w * w - _q.x * x - _q.y * y - _q.z * z;
	float nx = _q.w * x + _q.x * w + _q.y * z - _q.z * y;
	float ny = _q.w * y + _q.y * w + _q.z * x - _q.x * z;
	float nz = _q.w * z + _q.z * w + _q.x * y - _q.y * x;
	return Quaternion(nw, nx, ny, nz);
}

Quaternion cube::Quaternion::copy()
{
	return Quaternion(x, y, z, w);
}

Vector3f cube::Quaternion::rotate(Vector3f pt, int _angle)
{
	Quaternion axis, rotate;
	axis = normalise();
	float angleRad = PI / 180.0f * _angle;
	rotate = Quaternion(cosf(angleRad / 2.0f), sinf(angleRad / 2.0f) * axis.x, sinf(angleRad / 2.0f) * axis.y, sinf(angleRad / 2.0f) * axis.z);
	Quaternion conjugate = rotate.conjugate();
	Quaternion qNode = Quaternion(0.0f, pt.x, pt.y, pt.z);
	qNode = rotate * qNode * conjugate;
	return Vector3f(qNode.x, qNode.y, qNode.z);
}

Quaternion cube::Quaternion::operator+(Quaternion t_q)
{
	return Quaternion(w + t_q.w, x + t_q.x, y + t_q.y, z + t_q.z);
}

Quaternion cube::Quaternion::operator-()
{
	return Quaternion(-w, -x, -y, -z);
}

Quaternion cube::Quaternion::operator-(Quaternion t_q)
{
	return Quaternion(w - t_q.w, x - t_q.x, y - t_q.y, z - t_q.z);
}

Quaternion cube::Quaternion::operator*(double s)
{
	return Quaternion(w * static_cast<float>(s), x * static_cast<float>(s), y * static_cast<float>(s), z * static_cast<float>(s));
}

Quaternion cube::Quaternion::operator*(float s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion cube::Quaternion::operator*(int s)
{
	return Quaternion(w * static_cast<float>(s), x * static_cast<float>(s), y * static_cast<float>(s), z * static_cast<float>(s));
}

Quaternion cube::operator*(double s, Quaternion q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion cube::operator*(float s, Quaternion q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion cube::operator*(int s, Quaternion q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}


Quaternion cube::Quaternion::operator*(Quaternion t_q)
{
	float nw = w * t_q.w - x * t_q.x - y * t_q.y - z * t_q.z;
	float nx = w * t_q.x + x * t_q.w + y * t_q.z - z * t_q.y;
	float ny = w * t_q.y + y * t_q.w + z * t_q.x - x * t_q.z;
	float nz = w * t_q.z + z * t_q.w + x * t_q.y - y * t_q.x;
	return Quaternion(nw, nx, ny, nz);
}