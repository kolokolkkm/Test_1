#pragma once
#include <vector>

template<typename Type=double>
class Vector
{
protected:
	char name_vector;
	Type x;
	Type y;
	Type z;
	static inline unsigned count_v = 0; //inline ������������ ��� ������ ODR

public:
	/*�����������*/
	Vector(char input_name_vector = '-', Type input_x = 0, Type input_y = 0, Type input_z = 0);

	/*���������� ��������� =*/
	Vector& operator = (const Vector& v) const;

	/*��������� ���������� x �������*/
	Type GetX() const;

	/*��������� ���������� y �������*/
	Type GetY() const;

	/*��������� ���������� z �������*/
	Type GetZ() const;

	/*��������� ��� �������*/
	char GetNameVector() const;

	/*���������� ������������ ��������*/
	static int GetCountVectors();

	/*����� �������*/
	Type LenVector() const;

	/*����� ��������*/
	virtual Vector Sum(const Vector& v) const;

	/*��������� ��������*/
	virtual Vector Dif(const Vector& v) const;

	/*��������� ������������*/
	Type Mult(const Vector& v) const;

	/*������� ���� ����� ���������*/
	double CosVectors(const Vector& v) const;

	/*����� �������� ��������� �������*/
	friend void SetCordinatesVector(Vector& v, double new_x, double new_y, double new_z);
	friend void SetCordinatesVector(Vector& v_1, Vector& v_2);

	/*��������������� ��������� +*/
	Vector operator +(const Vector v) const;

	/*���������� ��������� */
	double operator *(const Vector<double>& v) const;
	Vector<double> operator *(double m) const;

	/*��������������� ��������� -*/
	Vector operator -(const Vector& v) const;
	
	/*����� ������� � ����������*/
	static int search_index_vector_in_array_of_name(const std::vector<Vector<Type>*>& vectors, char name_vector);
};

class BazisVector : public Vector<double>
{
private:
	char axis;
public:
	/*����������� �� �������� ������*/
	using Vector::Vector;

	/*���������� ����������� ��������� ������*/
	BazisVector(char input_name_vector, double len, char axis);

	/*��������� ����� ���*/
	char GetAxis() const;

	/*��������� ���*/
	void SetAxis(char new_axis);

	/*��������������� ����������� �������*/
	Vector Sum(const Vector& v) const override;

	Vector Dif(const Vector& v) const override;
}; 