#pragma once

class Vector
{
private:
	char name_vector;
	double x;
	double y;
	double z;
	static inline unsigned count_v = 0;
public:
	Vector(char input_name_vector, double input_x = 0, double input_y = 0, double input_z = 0);
	/*��������� ���������� x �������*/
	double GetX() const;
	/*��������� ���������� y �������*/
	double GetY() const;
	/*��������� ���������� z �������*/
	double GetZ() const;
	/*��������� ��� �������*/
	char GetNameVector() const;

	/*���������� ������������ ��������*/
	static int GetCountVectors();

	/*����� �������*/
	double LenVector() const;

	/*����� ��������*/
	Vector Sum(const Vector& v) const;

	/*��������� ��������*/
	Vector Dif(const Vector& v) const;

	/*��������� ������������*/
	double Mult(const Vector& v) const;

	/*������� ���� ����� ���������*/
	double CosVectors(const Vector& v) const;
};