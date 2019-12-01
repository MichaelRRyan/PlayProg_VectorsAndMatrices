/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 25/11/19
/// </summary>

#include <iostream>
#include "Vector2f.h"
#include "Vector3f.h"

void vector2Tests(); // Vector2 tests
void vector2CheckValid(cube::Vector2f t_vector2, float t_idealX, float t_idealY, std::string t_testName); // Prints out whether or not the components of t_vector2 match the ideal x and y
void vector2CheckValid(float t_value, float t_idealValue, std::string t_testName); // Prints out whether or not t_value matches the ideal value

void vector3Tests(); // Vector2 tests
void vector3CheckValid(cube::Vector3f t_vector2, float t_idealX, float t_idealY, float t_idealZ, std::string t_testName); // Prints out whether or not the components of t_vector3 match the ideal x, y and z
void vector3CheckValid(float t_value, float t_idealValue, std::string t_testName); // Prints out whether or not t_value matches the ideal value

//////////////////////////////////////////////////////////////////////////////////////
int main()
{
	// Run the tests
	vector2Tests();
	system("pause");
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////
void vector2Tests()
{
	// Create a zero vector
	cube::Vector2f vector2;
	vector2CheckValid(vector2, 0.0f, 0.0f, "zero constructer");
	
	// Create a vector with given values
	cube::Vector2f vector2Two{ 2.0f, 1.0f };
	vector2CheckValid(vector2Two, 2.0f, 1.0f, "given values constructer");

	// Get the length of a vector
	vector2 = { 6.0f, 8.0f };
	float floatResult = vector2.Length();
	vector2CheckValid(floatResult, 10.0f, "length");

	// Get the length squared of a vector
	floatResult = vector2.LengthSquared();
	vector2CheckValid(floatResult, 100.0f, "length squared");

	// Get the unit vector of a vector
	vector2.Normalise();
	vector2CheckValid(vector2, 0.6f, 0.8f, "unit vector");

	// Plus operator
	vector2 = { 4.0f, 2.0f };
	vector2Two = { 2.0f, 4.0f };
	cube::Vector2f resultVector = vector2 + vector2Two;
	vector2CheckValid(resultVector, 6.0f, 6.0f, "plus operator");

	// Minus operator
	resultVector = vector2 - vector2Two;
	vector2CheckValid(resultVector, 2.0f, -2.0f, "minus operator");

	// Negation operator
	resultVector = -vector2;
	vector2CheckValid(resultVector, -4.0f, -2.0f, "negation operator");

	// Dot product operator
	vector2 = { 1.0f, 2.0f };
	vector2Two = { 1.0f, 5.0f };
	floatResult = vector2 * vector2Two;
	vector2CheckValid(floatResult, 11.0f, "dot product operator");

	// Double scalar multiplication
	resultVector = vector2 * 2.0;
	vector2CheckValid(resultVector, 2.0f, 4.0f, "double scalar multiplication");

	// Float scalar multiplication
	resultVector = vector2 * 2.0f;
	vector2CheckValid(resultVector, 2.0f, 4.0f, "float scalar multiplication");

	// Int scalar multiplication
	resultVector = vector2 * 2;
	vector2CheckValid(resultVector, 2.0f, 4.0f, "int scalar multiplication");

	if (vector2.toString() == "{ 1.000000f, 2.000000f }")
	{
		std::cout << "| Vector2 to string test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- Vector2 to string test was unsuccessful." << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
void vector2CheckValid(cube::Vector2f t_vector2, float t_idealX, float t_idealY, std::string t_testName)
{
	if (t_vector2.x == t_idealX && t_vector2.y == t_idealY)
	{
		std::cout << "| Vector2 " + t_testName + " test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- Vector2 " + t_testName + " test was unsuccessful." << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
void vector2CheckValid(float t_value, float t_idealValue, std::string t_testName)
{
	if (t_value == t_idealValue)
	{
		std::cout << "| Vector2 " + t_testName + " test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- Vector2 " + t_testName + " test was unsuccessful." << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
void vector3Tests()
{

}

//////////////////////////////////////////////////////////////////////////////////////
void vector3CheckValid(cube::Vector3f t_vector3, float t_idealX, float t_idealY, float t_idealZ, std::string t_testName)
{
	if (t_vector3.x == t_idealX && t_vector3.y == t_idealY && t_vector3.z == t_idealZ)
	{
		std::cout << "| Vector3 " + t_testName + " test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- Vector3 " + t_testName + " test was unsuccessful." << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
void vector3CheckValid(float t_value, float t_idealValue, std::string t_testName)
{
	if (t_value == t_idealValue)
	{
		std::cout << "| Vector3 " + t_testName + " test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- Vector3 " + t_testName + " test was unsuccessful." << std::endl;
	}
}
