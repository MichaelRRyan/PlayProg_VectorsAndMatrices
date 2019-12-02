/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 25/11/19
/// </summary>

#include <iostream>
#include "Vector2f.h"
#include "Vector3f.h"
#include "Matrix3f.h"

using namespace cube;


void vector2Tests(); // Vector2 tests
void vector3Tests(); // Vector3 tests
void matrix3Tests(); // Matrix3 tests

void floatCheckValid(float t_value, float t_idealValue, std::string t_testName); // Prints out whether or not t_value matches the ideal value
void vector2CheckValid(Vector2f t_vector2, float t_idealX, float t_idealY, std::string t_testName); // Prints out whether or not the components of t_vector2 match the ideal x and y
void vector3CheckValid(Vector3f t_vector2, float t_idealX, float t_idealY, float t_idealZ, std::string t_testName); // Prints out whether or not the components of t_vector3 match the ideal x, y and z
void matrix3CheckValid(Matrix3f t_matrix, Vector3f t_idealRow1, Vector3f t_idealRow2, Vector3f t_idealRow3, std::string t_testName);

//////////////////////////////////////////////////////////////////////////////////////
int main()
{
	// Run the tests
	std::cout << "Vector2 Tests:" << std::endl;
	vector2Tests();

	std::cout << "Vector3 Tests:" << std::endl;
	vector3Tests();

	std::cout << "Matrix3 Tests:" << std::endl;
	matrix3Tests();

	system("pause");
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////
void vector2Tests()
{
	// Create a zero vector
	Vector2f vector2;
	vector2CheckValid(vector2, 0.0f, 0.0f, "zero constructer");
	
	// Create a vector with given values
	Vector2f vector2Two{ 2.0f, 1.0f };
	vector2CheckValid(vector2Two, 2.0f, 1.0f, "given values constructer");

	// Get the length of a vector
	vector2 = { 6.0f, 8.0f };
	float floatResult = vector2.Length();
	floatCheckValid(floatResult, 10.0f, "length");

	// Get the length squared of a vector
	floatResult = vector2.LengthSquared();
	floatCheckValid(floatResult, 100.0f, "length squared");

	// Get the unit vector of a vector
	vector2.Normalise();
	vector2CheckValid(vector2, 0.6f, 0.8f, "unit vector");

	// Plus operator
	vector2 = { 4.0f, 2.0f };
	vector2Two = { 2.0f, 4.0f };
	Vector2f resultVector = vector2 + vector2Two;
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
	floatCheckValid(floatResult, 11.0f, "dot product operator");

	// Double scalar multiplication
	resultVector = vector2 * 2.0;
	vector2CheckValid(resultVector, 2.0f, 4.0f, "double scalar multiplication");

	// Float scalar multiplication
	resultVector = vector2 * 2.0f;
	vector2CheckValid(resultVector, 2.0f, 4.0f, "float scalar multiplication");

	// Int scalar multiplication
	resultVector = vector2 * 2;
	vector2CheckValid(resultVector, 2.0f, 4.0f, "int scalar multiplication");

	// Vector to string
	if (vector2.toString() == "{ 1.000000f, 2.000000f }")
	{
		std::cout << "| Vector2 to string test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- Vector2 to string test was unsuccessful." << std::endl;
	}
	std::cout << vector2 << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////
void vector3Tests()
{
	// Creates a zero vector
	Vector3f vector3;
	vector3CheckValid(vector3, 0.0f, 0.0f, 0.0f, "zero constructer");

	// Given value vector
	Vector3f vector3Two{ 1.0f, 2.0f, 3.0f };
	vector3CheckValid(vector3Two, 1.0f, 2.0f, 3.0f, "given value constructer");

	// Get the length of a vector
	vector3 = { 2.0f, 4.0f, -2.25f };
	float floatResult = vector3.Length();
	floatCheckValid(floatResult, 5.00624609f, "length");

	// Get the length squared of a vector
	vector3 = { 2.0f, 4.0f, -2.0f };
	floatResult = vector3.LengthSquared();
	floatCheckValid(floatResult, 24.0f, "length");

	// Normalise a vector
	vector3 = { 6.0f, 8.0f, 1.0f };
	vector3.Normalise();
	vector3CheckValid(vector3, 0.597022355f, 0.796029806f, 0.0995037258f, "unit vector");

	// Plus operator
	vector3 = { 2.0f, 4.0f, 6.0f };
	vector3Two = { 6.0f, 4.0f, 2.0f };
	Vector3f vector3Result = vector3 + vector3Two;
	vector3CheckValid(vector3Result, 8.0f, 8.0f, 8.0f, "plus operator");

	// Minus operator
	vector3Result = vector3 - vector3Two;
	vector3CheckValid(vector3Result, -4.0f, 0.0f, 4.0f, "minus operator");

	// Negation operator
	vector3Result = -vector3;
	vector3CheckValid(vector3Result, -2.0f, -4.0f, -6.0f, "negation operator");

	// Double multiplication operator
	vector3Result = vector3 * 2.0;
	vector3CheckValid(vector3Result, 4.0f, 8.0f, 12.0f, "double multiplication operator");

	// float multiplication operator
	vector3Result = vector3 * 2.0f;
	vector3CheckValid(vector3Result, 4.0f, 8.0f, 12.0f, "float multiplication operator");

	// int multiplication operator
	vector3Result = vector3 * 2;
	vector3CheckValid(vector3Result, 4.0f, 8.0f, 12.0f, "int multiplication operator");

	// Vector product operator
	vector3 = { 1.0f, 2.0f, 3.0f };
	vector3Two = { 1.0f, 5.0f, 7.0f };
	vector3Result = vector3 ^ vector3Two;
	vector3CheckValid(vector3Result, -1.0f, -4.0f, 3.0f, "vector product operator");

	// Vector to string
	if (vector3.toString() == "{ 1.000000f, 2.000000f, 3.000000f }")
	{
		std::cout << "| Vector3 to string test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- Vector3 to string test was unsuccessful." << std::endl;
	}

	std::cout << vector3 << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////
void matrix3Tests()
{
	// Create a zero matrix
	Matrix3f matrix3;
	matrix3CheckValid(matrix3, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, "zero matrix");

	// Create a matrix from 3 vector3's
	Matrix3f matrix3Two{ Vector3f{1.0f, 2.0f, 3.0f}, Vector3f{4.0f, 5.0f, 6.0f}, Vector3f{7.0f, 8.0f, 9.0f} };
	matrix3CheckValid(matrix3Two, { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, { 7.0f, 8.0f, 9.0f }, "3 given vector3's matrix");

	// Create a matrix from 9 float values
	Matrix3f matrix3Three{ 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f };
	matrix3CheckValid(matrix3Three, { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, { 7.0f, 8.0f, 9.0f }, "9 given values matrix");

	// Multiply a matrix with a vector3
	Vector3f vector3{ 1.0f, 2.0f, 3.0f };
	matrix3 = matrix3Two;
	Vector3f vectorResult = matrix3 * vector3;
	//matrix3CheckValid(vectorResult, { 1.0f, 2.0f, 3.0f }, { 4.0f, 5.0f, 6.0f }, { 7.0f, 8.0f, 9.0f }, "9 given values matrix");
}

//////////////////////////////////////////////////////////////////////////////////////
void floatCheckValid(float t_value, float t_idealValue, std::string t_testName)
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
void vector2CheckValid(Vector2f t_vector2, float t_idealX, float t_idealY, std::string t_testName)
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
void vector3CheckValid(Vector3f t_vector3, float t_idealX, float t_idealY, float t_idealZ, std::string t_testName)
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
void matrix3CheckValid(Matrix3f t_matrix, Vector3f t_idealRow1, Vector3f t_idealRow2, Vector3f t_idealRow3, std::string t_testName)
{
	if (t_matrix.Row(0) == t_idealRow1 && t_matrix.Row(1) == t_idealRow2 && t_matrix.Row(2) == t_idealRow3)
	{
		std::cout << "| Matrix3 " + t_testName + " test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- Matrix3 " + t_testName + " test was unsuccessful." << std::endl;
	}
}
