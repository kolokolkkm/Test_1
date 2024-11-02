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
	static inline unsigned count_v = 0; //inline используется для обхода ODR

public:
	/*Конструктор*/
	Vector(char input_name_vector = '-', Type input_x = 0, Type input_y = 0, Type input_z = 0);

	/*Перегрузка оператора =*/
	Vector& operator = (const Vector& v) const;

	/*Получение координаты x вектора*/
	Type GetX() const;

	/*Получение координаты y вектора*/
	Type GetY() const;

	/*Получение координаты z вектора*/
	Type GetZ() const;

	/*Получение имя вектора*/
	char GetNameVector() const;

	/*Количество существуемых векторов*/
	static int GetCountVectors();

	/*Длина вектора*/
	Type LenVector() const;

	/*Сумма векторов*/
	virtual Vector Sum(const Vector& v) const;

	/*Вычитание векторов*/
	virtual Vector Dif(const Vector& v) const;

	/*Скалярное произведение*/
	Type Mult(const Vector& v) const;

	/*Косинус угла между векторами*/
	double CosVectors(const Vector& v) const;

	/*Смена значений координат вектора*/
	friend void SetCordinatesVector(Vector& v, double new_x, double new_y, double new_z);
	friend void SetCordinatesVector(Vector& v_1, Vector& v_2);

	/*Переопределение оператора +*/
	Vector operator +(const Vector v) const;

	/*Перегрузки оператора */
	double operator *(const Vector<double>& v) const;
	Vector<double> operator *(double m) const;

	/*Переопределение оператора -*/
	Vector operator -(const Vector& v) const;
	
	/*Поиск вектора в контейнере*/
	static int search_index_vector_in_array_of_name(const std::vector<Vector<Type>*>& vectors, char name_vector);
};

class BazisVector : public Vector<double>
{
private:
	char axis;
public:
	/*Конструктор от базового класса*/
	using Vector::Vector;

	/*Уникальный конструктор дочернего класса*/
	BazisVector(char input_name_vector, double len, char axis);

	/*Получение имени оси*/
	char GetAxis() const;

	/*Изменение оси*/
	void SetAxis(char new_axis);

	/*Переопределение виртуальных функции*/
	Vector Sum(const Vector& v) const override;

	Vector Dif(const Vector& v) const override;
}; 