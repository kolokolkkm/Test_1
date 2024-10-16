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
	/*Получение координаты x вектора*/
	double GetX() const;
	/*Получение координаты y вектора*/
	double GetY() const;
	/*Получение координаты z вектора*/
	double GetZ() const;
	/*Получение имя вектора*/
	char GetNameVector() const;

	/*Количество существуемых векторов*/
	static int GetCountVectors();

	/*Длина вектора*/
	double LenVector() const;

	/*Сумма векторов*/
	Vector Sum(Vector& v) const;

	/*Вычитание векторов*/
	Vector Dif(const Vector& v) const;

	/*Скалярное произведение*/
	double Mult(const Vector& v) const;

	/*Косинус угла между векторами*/
	double CosVectors(const Vector& v) const;

	/*Смена значений координат вектора*/
	friend void SetCordinatesVector(Vector& v, double new_x, double new_y, double new_z);
};