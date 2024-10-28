#pragma once

class Vector
{
protected:
	char name_vector;
	double x;
	double y;
	double z;
	static inline unsigned count_v = 0; //inline ������������ ��� ������ ������� ������ �����������

public:
	/*�����������*/
	Vector(char input_name_vector = '-', double input_x = 0, double input_y = 0, double input_z = 0);

	/*���������� ��������� =*/
	Vector operator = (const Vector& v) const;

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
	virtual Vector Sum(const Vector& v) const;

	/*��������� ��������*/
	virtual Vector Dif(const Vector& v) const;

	/*��������� ������������*/
	double Mult(const Vector& v) const;

	/*������� ���� ����� ���������*/
	double CosVectors(const Vector& v) const;

	/*����� �������� ��������� �������*/
	friend void SetCordinatesVector(Vector& v, double new_x, double new_y, double new_z);
	friend void SetCordinatesVector(Vector& v_1, Vector& v_2);

	/*��������������� ��������� +*/
	Vector operator +(const Vector& v) const;

	/*��������������� ��������� */
	double operator *(const Vector& v) const;

	/*��������������� ��������� -*/
	Vector operator -(const Vector& v) const;
};

class BazisVector : public Vector
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

	/*��������������� ����������� �������*/
	Vector Sum(const Vector& v) const override;

	Vector Dif(const Vector& v) const;
}; 