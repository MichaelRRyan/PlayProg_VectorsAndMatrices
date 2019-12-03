/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 25/11/19
/// </summary>

#include <iostream>
#include "Vector2f.h"
#include "Vector3f.h"
#include "Matrix3f.h"
#include "Quaternion.h"

using namespace cube;


void vector2Tests(); // Vector2 tests
void vector3Tests(); // Vector3 tests
void matrix3Tests(); // Matrix3 tests
void quaternionTests(); // Quaternion tests

void floatCheckValid(float t_value, float t_idealValue, std::string t_testName); // Prints out whether or not t_value matches the ideal value
void vector2CheckValid(Vector2f t_vector2, float t_idealX, float t_idealY, std::string t_testName); // Prints out whether or not the components of t_vector2 match the ideal x and y
void vector3CheckValid(Vector3f t_vector2, float t_idealX, float t_idealY, float t_idealZ, std::string t_testName); // Prints out whether or not the components of t_vector3 match the ideal x, y and z
void matrix3CheckValid(Matrix3f t_matrix, Vector3f t_idealRow1, Vector3f t_idealRow2, Vector3f t_idealRow3, std::string t_testName);
void quaternionCheckValid(Quaternion t_quaternion, float t_idealW , float t_idealX, float t_idealY, float t_idealZ, std::string t_testName);

//////////////////////////////////////////////////////////////////////////////////////
int main()
{
	// Run the tests
	std::cout << std::endl << "Vector2 Tests:" << std::endl;
	vector2Tests();

	std::cout << std::endl << "Vector3 Tests:" << std::endl;
	vector3Tests();

	std::cout << std::endl << "Matrix3 Tests:" << std::endl;
	matrix3Tests();

	std::cout << std::endl << "Quaternion Tests:" << std::endl;
	quaternionTests();

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

	// Matrix transpose
	matrix3 = matrix3Two;
	Matrix3f matrixResult = Matrix3f::Transpose(matrix3);
	matrix3CheckValid(matrixResult, { 1.0f, 4.0f, 7.0f }, {2.0f, 5.0f, 8.0f }, { 3.0f, 6.0f, 9.0f }, "matrix transpose");

	// Matrix plus matrix
	matrixResult = matrix3 + matrix3Two;
	matrix3CheckValid(matrixResult, { 2.0f, 4.0f, 6.0f }, { 8.0f, 10.0f, 12.0f }, { 14.0f, 16.0f, 18.0f }, "matrix plus matrix");

	// Matrix minus matrix
	matrixResult = matrix3 - matrix3Two;
	matrix3CheckValid(matrixResult, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, "matrix minus matrix");

	// Matrix multiplied by scalar
	matrixResult = matrix3 * 2.0f;
	matrix3CheckValid(matrixResult, { 2.0f, 4.0f, 6.0f }, { 8.0f, 10.0f, 12.0f }, { 14.0f, 16.0f, 18.0f }, "matrix multiplied by scalar");

	// Scalar multiplied by matrix
	matrixResult = 2.0f * matrix3;
	matrix3CheckValid(matrixResult, { 2.0f, 4.0f, 6.0f }, { 8.0f, 10.0f, 12.0f }, { 14.0f, 16.0f, 18.0f }, "scalar multiplied by matrix");

	// Matrix multiplied by matrix
	matrix3Two = { 9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f };
	matrixResult = matrix3 * matrix3Two;
	matrix3CheckValid(matrixResult, { 30.0f, 24.0f, 18.0f }, { 84.0f, 69.0f, 54.0f }, { 138.0f, 114.0f, 90.0f }, "matrix multiplied by matrix");
	// Matrix Multiplied by a vector3
	Vector3f vector3{ 1.0f, 2.0f, 3.0f };
	Vector3f vectorResult = matrix3 * vector3;
	vector3CheckValid(vectorResult, 14.0f, 32.0f, 50.0f, "Matrix multiplied by vector3");

	// Vector3 multiplied by matrix
	vectorResult = vector3 * matrix3;
	vector3CheckValid(vectorResult, 30.0f, 36.0f, 42.0f, "Vector3 multiplied by matrix");

	// Matrix determinant
	matrix3 = { 5.0, 2.0, 7.0, 3.0, 12.0, 4.0, 8.0, 1.0, 9.0 };
	float floatResult = Matrix3f::Determinant(matrix3);
	floatCheckValid(floatResult, -121.0f, "matrix determinant");

	// Matrix row
	vectorResult = matrix3.Row(0);
	vector3CheckValid(vectorResult, 5.0f, 2.0f, 7.0f, "Matrix row");

	// Matrix col
	vectorResult = matrix3.Column(0);
	vector3CheckValid(vectorResult, 5.0f, 3.0f, 8.0f, "Matrix col");

	// Matrix inverse
	matrix3 = { -5.0, 1.0, 4.0, -1.0, 1.0, 1.0, -4.0, 1.0, 3.0 };
	matrixResult = Matrix3f::Inverse(matrix3);
	matrix3CheckValid(matrixResult, {2.0f, 1.0f, -3.0f}, {-1.0f, 1.0f, 1.0f}, {3.0f, 1.0f, -4.0f}, "matrix inverse");

	// Matrix rotation
	matrixResult = Matrix3f::Rotation(45);
	matrix3CheckValid(matrixResult, { 0.707106769f, 0.707106769f, 0.0f }, {-0.707106769f, 0.707106769f, 0.0f }, { 0.0f, 0.0f, 1.0f}, "matrix rotation");

	// Matrix translate
	matrixResult = Matrix3f::Translate(20.0f, 20.0f);
	matrix3CheckValid(matrixResult, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {20.0f, 20.0f, 1.0f}, "matrix translate");

	// Matrix scale
	matrixResult = Matrix3f::Scale(100.0f, 100.0f);
	matrix3CheckValid(matrixResult, { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f }, "matrix scale");

	// Matrix negation operator
	matrixResult = -matrix3;
	matrix3CheckValid(matrixResult, { 5.0f, -1.0f, -4.0f }, { 1.0f, -1.0f, -1.0f }, { 4.0f, -1.0f, -3.0f }, "matrix negation operator");

	// Matrix rotationX
	matrixResult = Matrix3f::RotationX(45.0f);
	matrix3CheckValid(matrixResult, { 1.0f, 0.0f, 0.0f }, { 0.0f, 0.707106769f, -0.707106769f }, { 0.0f, 0.707106769f, 0.707106769f }, "matrix rotation X");

	// Matrix rotationY
	matrixResult = Matrix3f::RotationY(45.0f);
	matrix3CheckValid(matrixResult, { 0.707106769f, 0.0f, 0.707106769f }, { 0.0f, 1.0f, 0.0f }, { -0.707106769f, 0.0f, 0.707106769f }, "matrix rotation Y");

	// Matrix rotationZ
	matrixResult = Matrix3f::RotationZ(45.0f);
	matrix3CheckValid(matrixResult, { 0.707106769f, -0.707106769f, 0.0f }, { 0.707106769f, 0.707106769f, 0.0f }, { 0.0f, 0.0f, 1.0f }, "matrix rotation Z");

	// Matrix scale3D
	matrixResult = Matrix3f::Scale3D(100.0f);
	matrix3CheckValid(matrixResult, { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f }, "matrix scale 3D");
}

//////////////////////////////////////////////////////////////////////////////////////
void quaternionTests()
{
	// Zero quaternion constructer
	Quaternion quaternion;
	quaternionCheckValid(quaternion, 0.0f, 0.0f, 0.0f, 0.0f, "Zero quaternion constructer");

	// Quaternion constructer with 4 given float values
	Quaternion quaternionTwo{ 1.0f, 2.0f, 3.0f, 4.0f};
	quaternionCheckValid(quaternionTwo, 1.0f, 2.0f, 3.0f, 4.0f, "Quaternion constructer with 4 given values");

	// Quaternion constructer with a given float and vector3
	Quaternion quaternionThree{ 1.0f, Vector3f{ 2.0f, 3.0f, 4.0f } };
	quaternionCheckValid(quaternionThree, 1.0f, 2.0f, 3.0f, 4.0f, "Quaternion constructer with given float and vector3 value");

	// Quaternion modulus
	quaternion = quaternionTwo;
	float floatResult = quaternion.modulus();
	floatCheckValid(floatResult, 5.47722578f, "Quaternion modulus");

	// Quaternion normalise
	quaternion = { 1.0f, 1.0f, 1.0f, 1.0f };
	Quaternion quaternionResult = quaternion.normalise();
	quaternionCheckValid(quaternionResult, 0.5f, 0.5f, 0.5f, 0.5f, "Quaternion normalise");

	// Quaternion conjugate
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = quaternion.conjugate();
	quaternionCheckValid(quaternionResult, 1.0f, -2.0f, -3.0f, -4.0f, "Quaternion conjugate");

	// Quaternion from axis angle
	Vector3f axis{ 1.0f, 0.0f, 0.0f };
	quaternion.fromAxisAngle(axis, 2.0f);
	quaternionCheckValid(quaternion, 0.540302277f, 0.841470957f, -0.0f, -0.0f, "Quaternion from axis angle");

	// Quaternion multipied by quaternion
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = quaternion.multiply(quaternionTwo);
	quaternionCheckValid(quaternionResult, -28.0f, 4.0f, 6.0f, 8.0f, "Quaternion multiply function");

	// Quaternion copy
	quaternionResult = quaternion.copy();
	quaternionCheckValid(quaternionResult, 1.0f, 2.0f, 3.0f, 4.0f, "Quaternion copy");

	// Quaternion rotate
	Vector3f point{ 1.0f, 1.0f, 1.0f };
	quaternion = { 1.0f, 1.0f, 1.0f, 1.0f };
	Vector3f vector3Result = quaternion.rotate(point, 90);
	vector3CheckValid(vector3Result, 0.874999881f, 0.874999881f, 0.874999881f, "Quaternion rotate");

	// Quaternion addition
	quaternionResult = quaternion + quaternionThree;
	quaternionCheckValid(quaternionResult, 2.0f, 3.0f, 4.0f, 5.0f, "Quaternion addition");

	// Quaternion negation operator
	quaternionResult = -quaternion;
	quaternionCheckValid(quaternionResult, -1.0f, -1.0f, -1.0f, -1.0f, "Quaternion negation operator");

	// Quaternion negation
	quaternionResult = quaternion - quaternionThree;
	quaternionCheckValid(quaternionResult, 0.0f, -1.0f, -2.0f, -3.0f, "Quaternion negation");

	// Quaternion multiplied by double
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = quaternion * 2.0;
	quaternionCheckValid(quaternionResult, 2.0f, 4.0f, 6.0f, 8.0f, "Quaternion multiplied by double");

	// Quaternion multiplied by float
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = quaternion * 2.0f;
	quaternionCheckValid(quaternionResult, 2.0f, 4.0f, 6.0f, 8.0f, "Quaternion multiplied by float");

	// Quaternion multiplied by int
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = quaternion * 2;
	quaternionCheckValid(quaternionResult, 2.0f, 4.0f, 6.0f, 8.0f, "Quaternion multiplied by int");

	// Double multiplied by quaternion
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = 2.0 * quaternion;
	quaternionCheckValid(quaternionResult, 2.0f, 4.0f, 6.0f, 8.0f, "Double multiplied by quaternion");

	// float multiplied by quaternion
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = 2.0f * quaternion;
	quaternionCheckValid(quaternionResult, 2.0f, 4.0f, 6.0f, 8.0f, "float multiplied by quaternion");

	// int multiplied by quaternion
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = 2 * quaternion;
	quaternionCheckValid(quaternionResult, 2.0f, 4.0f, 6.0f, 8.0f, "int multiplied by quaternion");

	// Quaternion multipied by quaternion
	quaternion = { 1.0f, 2.0f, 3.0f, 4.0f };
	quaternionResult = quaternion * quaternionTwo;
	quaternionCheckValid(quaternionResult, -28.0f, 4.0f, 6.0f, 8.0f, "Quaternion multipied by quaternion");

	// Vector to string
	if (quaternion.toString() == "{ 1.000000, 2.000000i, 3.000000j, 4.000000k }")
	{
		std::cout << "| quaternion to string test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- quaternion to string test was unsuccessful." << std::endl;
	}
	std::cout << quaternion << std::endl;
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


//////////////////////////////////////////////////////////////////////////////////////
void quaternionCheckValid(Quaternion t_quaternion, float t_idealW, float t_idealX, float t_idealY, float t_idealZ, std::string t_testName)
{
	if (t_quaternion.getW() == t_idealW && t_quaternion.getX() == t_idealX
		&& t_quaternion.getY() == t_idealY && t_quaternion.getZ() == t_idealZ)
	{
		std::cout << "| " + t_testName + " test was successful." << std::endl;
	}
	else
	{
		std::cout << "-- " + t_testName + " test was unsuccessful." << std::endl;
	}
}
