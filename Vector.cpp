#include <iostream>
#include "Vector.h"
#include <cmath>

Vector::Vector(char input_name_vector, double input_x, double input_y, double input_z)
	:name_vector(input_name_vector), x(input_x), y(input_y), z(input_z)
{
	++count_v;
}

double Vector::GetX() const
{
	return x;
}

double Vector::GetY() const
{
	return y;
}

double Vector::GetZ() const
{
	return z;
}

char Vector::GetNameVector() const
{
	return name_vector;
}

int Vector::GetCountVectors()
{
	return count_v;
}

double Vector::LenVector() const
{
	double lenVector = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return lenVector;
}

Vector Vector::Sum(const Vector& v) const
{
	return Vector('-', x + v.x, y + v.y, z + v.z);
}

Vector Vector::Dif(const Vector& v) const
{
	return Vector('-', x - v.x, y - v.y, z - v.z);
}

double Vector::Mult(const Vector& v) const
{
	return (x * v.x + y * v.y + z * v.z);
}

double Vector::CosVectors(const Vector& v) const
{
	if ((LenVector() == 0) || (v.LenVector() == 0))
		std::cout << "Один из векторов нулевой!";
	return (double)Mult(v) / (LenVector() * v.LenVector());
}