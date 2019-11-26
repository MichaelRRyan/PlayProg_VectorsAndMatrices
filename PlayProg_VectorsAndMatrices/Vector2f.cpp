#include "Vector2f.h"

Vector2f::Vector2f() :
	x{ 0.0f },
	y{ 0.0f }
{
}

Vector2f::Vector2f(float t_x, float t_y) :
	x{ t_x },
	y{ t_y }
{
}

float Vector2f::Length()
{
	return sqrtf((x * x) + (y * y));
}

float Vector2f::LengthSquared()
{
	return (x * x) + (y * y);
}

void Vector2f::Normalise()
{
	float magnitude = Length();
	if (magnitude > 0.0f)
	{
		x = x / magnitude;
		y = y / magnitude;
	}
	else
	{
		std::cout << "ERROR: Attempting to normalise a zero vector" << std::endl;
	}
}

Vector2f Vector2f::operator+(Vector2f V)
{
	return { x + V.x, y + V.y };
}

Vector2f Vector2f::operator-(Vector2f V)
{
	return { x - V.x, y - V.y };
}

Vector2f Vector2f::operator-()
{
	return { -x, -y };
}

float Vector2f::operator*(Vector2f V)
{
	return { x * V.x + y * V.y };
}

Vector2f Vector2f::operator*(double k)
{
	return { x * static_cast<float>(k), y * static_cast<float>(k) };
}

Vector2f Vector2f::operator*(float k)
{
	return { x * k, y * k };
}

Vector2f Vector2f::operator*(int k)
{
	return { x * static_cast<float>(k), y * static_cast<float>(k) };
}

std::string Vector2f::toString()
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
