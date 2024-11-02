#include <iostream>
#include <vector>
#include "Vector.h"
#include <cmath>

template<typename Type>
Vector<Type>::Vector(char input_name_vector, Type input_x, Type input_y, Type input_z)
	:name_vector(input_name_vector), x(input_x), y(input_y), z(input_z)
{
	++count_v;
}
template<typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector& v) const
{
	return *this;
}

template<typename Type>
Type Vector<Type>::GetX() const
{
	return this->x;
}

template<typename Type>
Type Vector<Type>::GetY() const
{
	return this->y;
}

template<typename Type>
Type Vector<Type>::GetZ() const
{
	return this->z;
}

template<typename Type>
char Vector<Type>::GetNameVector() const
{
	return this->name_vector;
}

int Vector<double>::GetCountVectors()
{
	return count_v;
}

template<typename Type>
Type Vector<Type>::LenVector() const
{
	double lenVector = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return lenVector;
}

template<typename Type>
Vector<Type> Vector<Type>::Sum(const Vector& v) const
{
	return Vector('-', x + v.x, y + v.y, z + v.z);
}

template<typename Type>
Vector<Type> Vector<Type>::Dif(const Vector& v) const
{
	return Vector('-', x - v.x, y - v.y, z - v.z);
}

template<typename Type>
Type Vector<Type>::Mult(const Vector& v) const
{
	return (x * v.x + y * v.y + z * v.z);
}

double Vector<double>::CosVectors(const Vector& v) const
{
	if ((LenVector() == 0) || (v.LenVector() == 0))
		std::cout << "Один из векторов нулевой!";
	return (double)Mult(v) / (LenVector() * v.LenVector());
}

template<typename Type>
Vector<Type>& Vector<Type>::operator+(const Vector& v) const
{
	return Vector('-', x + v.x, y + v.y, z + v.z);
}

double Vector<double>::operator*(const Vector& v) const
{
	return (x * v.x + y * v.y + z * v.z);
}

Vector<double> Vector<double>::operator-(const Vector& v) const
{
	return Vector<double>('-', x - v.x, y - v.y, z - v.z);
}

int Vector<double>::search_index_vector_in_array_of_name(const std::vector<Vector<double>*>& vectors, char name_vector)
{
	for (int i = 0; i < vectors.size(); i++)
	{
		if (vectors[i]->GetNameVector() == name_vector)
		{
			return i;
			break;
		}
	}
	throw std::string{ "Не был найден нужный вектор!" };
}

void SetCordinatesVector(Vector<double>& v, double new_x, double new_y, double new_z)
{
	v.x = new_x;
	v.y = new_y;
	v.z = new_z;
}

void SetCordinatesVector(Vector<double>& v_1, Vector<double>& v_2)
{
	v_1.x = v_2.GetX();
	v_1.y = v_2.GetY();
	v_1.z = v_2.GetZ();
}


/*Конструктор дочернего класса*/
BazisVector::BazisVector(char input_name_vector, double len, char axis):Vector(input_name_vector)
{
	this->axis = axis;
	switch (axis)
	{
	default:
		break;
	case'x':
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

char BazisVector::GetAxis() const
{
	return axis;
}

Vector<double> BazisVector::Sum(const Vector& v) const
{
	//std::cout << "Используется виртуальная функций:\n";
	switch (axis)
	{
	default:
		break;
	case'x':
		return Vector('-', v.GetX() + GetX(), v.GetY(), v.GetZ());
		break;
	case 'y':
		return Vector('-', v.GetX(), v.GetY() + GetY(), v.GetZ());
		break;
	case 'z':
		return Vector('-', v.GetX(), v.GetY(), v.GetZ() + GetZ());
		break;
	}
}

Vector<double> BazisVector::Dif(const Vector& v) const
{
	//std::cout << "Используется виртуальная функций:\n";
	switch (axis)
	{
	default:
		break;
	case'x':
		return Vector('-', -v.GetX() - GetX(), -v.GetY(), -v.GetZ());
		break;
	case 'y':
		return Vector('-', -v.GetX(), -v.GetY() - GetY(), -v.GetZ());
		break;
	case 'z':
		return Vector('-', -v.GetX(), -v.GetY(), -v.GetZ() - GetZ());
		break;
	}
}
