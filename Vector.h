#pragma once
/*Это файл с обьявлением методов класса*/
class Vector
{
protected:
	char name_vector;
	double x;
	double y;
	double z;
	static inline unsigned count_v = 0; //inline используется для обхода правила одного определения, Будник может за это спросить, лучше в инете прочитать

public:
	/*Конструктор*/
	Vector(char input_name_vector = '-', double input_x = 0, double input_y = 0, double input_z = 0);

	/*Перегрузка оператора =*/
	Vector operator = (const Vector& v) const;

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
	friend void SetCordinatesVector(Vector& v_1, Vector& v_2);

	/*Переопределение оператора +*/
	Vector operator +(const Vector& v) const;

	/*Переопределение оператора */
	double operator *(const Vector& v) const;
};
/*Дочерний класс для 5+ лаб*/
class BazisVector : public Vector
{
private:
	char axis;
public:
	using Vector::Vector;
	BazisVector(char input_name_vector, double len, char axis);
};