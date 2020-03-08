/*---------------------------------------------------------------------------------------------------------
|                                                                                                         |
|                                                                                                         |
|           Learning about functions such as: Pass by value, pass by reference, and default parameters    |
|                                                                                                         |
|                                                                                                         |
|----------------------------------------------------------------------------------------------------------*/

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <vector>

// Defining different names instead of calling the entire namespace for std
#define _cout std::cout
#define _endl std::endl
#define _vector std::vector

// Forward Declarations(Prototypes)
double Pass_By_Value(double number1);
double Pass_By_Reference(double &number2);
void Pass_Constant_Vector(const _vector<int> &vec1);
double Using_Function_Default(double number3, double tax = 0.06);

// Overloading functions
int add_numbers(int a, int b);
double add_numbers(double a, double b);

// Passing an array to a function
void Passing_Array_Print_Contents(int arr[], size_t size);

// Recursive functions
unsigned long long fibonacci(unsigned long long n);


int main()
{
	// Demostrating pass by value
	double number1 = 10.1;
	_cout << "Before being passed to function: " << number1 << _endl; // 10.1
	Pass_By_Value(number1); // Pass number1 to the function
	_cout << "After being passed to function with pass by value: " << number1 << _endl; // After pass = 10.1
	_cout << "Functions value: " << Pass_By_Value(number1) << _endl;
	_cout << _endl;

	//--------------------------------------------------------------------------------//

	// Demostrating pass by reference
	double number2 = 20.2;
	_cout << "Before being passed to function: " << number2 << _endl;
	Pass_By_Reference(number2);
	_cout << "After being passed to function with pass by reference: " << number2 << _endl;
	_cout << "Functions value: " << Pass_By_Reference(number2) << _endl;
	_cout << _endl;

	//--------------------------------------------------------------------------------//

	// Demostrating a const vector pass by reference
	_cout << "Passing a const vector by reference: " << _endl;
	_vector<int> vectorNums = { 4,5,2,6,1,2,8,123 };
	Pass_Constant_Vector(vectorNums);
	_cout << _endl;

	//--------------------------------------------------------------------------------//

	// Demostrating default function parameters
	double number3 = 30.3;
	double tax = 0.8;
	_cout << "Calculating using default function parameter: " << Using_Function_Default(number3) << _endl;
	_cout << "Calculating overwriting default function parameter: " << Using_Function_Default(number3, tax) << _endl;
	_cout << _endl;

	//--------------------------------------------------------------------------------//

	// Demostrating overloaded functions
	_cout << "Overloading:" << _endl;
	_cout << "Int based function: " << add_numbers(2, 2) << _endl;
	_cout << "Double based function: " << add_numbers(2.2, 2.2) << _endl;
	_cout << _endl;

	//--------------------------------------------------------------------------------//

	// Passing arrays to a function
	int myArray[] = { 44,23,65,74,23 };
	_cout << "Passing array to function: " << _endl;
	Passing_Array_Print_Contents(myArray, 5);
	_cout << _endl;

	//--------------------------------------------------------------------------------//

	// Demostrating a recursive function
	_cout << "Recursive function: " << _endl;
	_cout << fibonacci(5) << _endl;
	_cout << fibonacci(10) << _endl;



	return 0;
}


double Pass_By_Value(double number1)
{
	number1 = 1000.2;

	return number1;
}

double Pass_By_Reference(double &number2)
{
	number2 = 2000.2;

	return number2;
}

void Pass_Constant_Vector(const _vector<int> &vec1)
{
	// vec1.at(0) = 500; Not allowed to do this because the vector is a constant

	_cout << "My const vec1 values: ";
	for (auto num : vec1)
	{
		_cout << "\t[ " << num << " ]";
	}

	_cout << _endl;
}

// Default function using double tax = 0.06
double Using_Function_Default(double number3, double tax)
{
	double sum = number3 * tax;

	return sum;
}

// Overloading functions
int add_numbers(int a, int b)
{
	return a + b;
}

double add_numbers(double a, double b)
{
	return a + b;
}

// Passing array to function
void Passing_Array_Print_Contents(int arr[], size_t size)
{
	_cout << "Array contents: ";
	for (size_t i = 0; i < size; i++)
	{
		_cout << "[ " << arr[i] << " ]\t";
	}
	_cout << _endl;
}

// Fibonacci recursive function
unsigned long long fibonacci(unsigned long long n)
{
	if (n <= 1)
	{
		return 1;	
	}

	// Loops the function back over again... Recursive
	return fibonacci(n - 1) + fibonacci(n - 2);
}
