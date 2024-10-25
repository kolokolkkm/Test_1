#include <iostream>
#include "Vector.h"
#include <cmath>
/*Файл с определением методов класса*/
Vector::Vector(char input_name_vector, double input_x, double input_y, double input_z)
	:name_vector(input_name_vector), x(input_x), y(input_y), z(input_z)
{
	++count_v;
}

Vector Vector::operator=(const Vector& v) const
{
	return *this;
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

Vector Vector::Sum(Vector& v) const
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

Vector Vector::operator+(const Vector& v) const
{
	return Vector('-', x + v.x, y + v.y, z + v.z);
}

double Vector::operator*(const Vector& v) const
{
	return (x * v.x + y * v.y + z * v.z);
}

Vector operator*(const Vector& v, double m)
{
	return Vector('-', v.GetX() * m, v.GetY() * m, v.GetZ() * m);
}

void SetCordinatesVector(Vector& v, double new_x, double new_y, double new_z)
{
	v.x = new_x;
	v.y = new_y;
	v.z = new_z;
}
void SetCordinatesVector(Vector& v_1, Vector& v_2)
{
	v_1.x = v_2.GetX();
	v_1.y = v_2.GetY();
	v_1.z = v_2.GetZ();
}
/*Конструктор дочернего класса*/
BazisVector::BazisVector(char input_name_vector, double len, char axis):Vector(input_name_vector)
{
	switch (axis)
	{
	default:
		break;
	case 'x':
		this->x = len;
			break;
	case 'y':
		this->y = len;
		break;
	case 'z':
		this->z = len;
		break;
	}
}
