#include <iostream>
#include "Vector.h"
#include <vector>
using namespace std;

void print_menu_item(char item) {
	cout << "Выбран " << item << " пункт меню\n";
}

Vector search_vector_in_array_of_name(const vector<Vector> &vectors, char name_vector)
{
	for (int i = 0; i < vectors.size(); i++)
	{
		if (vectors[i].GetNameVector() == name_vector)
		{
			return vectors[i];
			break;
		}
	}
}

bool check_vectors_count(int num_v) 
{
	if ((num_v - (int)Vector::GetCountVectors()) > 0)
		return false;
	else
		return true;
}

int main()
{
	char choice;
	bool close = false;
	setlocale(LC_ALL, "RU");
	std::vector<Vector> vectors;
	while (close == false) 
	{
		cout << "Выберите действие:\n";
		cout << "1. Создать вектор;\n";
		cout << "2. Вывести координаты вектора;\n";
		cout << "3. Сложить два вектора;\n";
		cout << "4. Вычесть из одного вектора другой;\n";
		cout << "5. Вычислить скалярное произведение векторов;\n";
		cout << "6. Найти косинус угла между векторами;\n";
		cout << "7. Выйти из программы.\n";
		cin >> choice;
		switch (choice)
		{
		default:
			cout << "Введеные данные не соответствуют пунктам меню!\n";
			continue;
			case '1':
				char name_vector;
				double x, y, z;
				print_menu_item(choice);
				cout << "Введите имя будущего вектора:\n";
				cin >> name_vector;
				cout << "Введите координаты X, Y, Z для будущего вектора\n";
				cin >> x >> y >> z;
				vectors.push_back(Vector {name_vector, x, y, z });
				cout << "Вектор " << name_vector << " = {" << x << ", " << y << ", " << z << "} создан!\n";
				continue;
			case '2':
				print_menu_item(choice);
				if (not(check_vectors_count(1)))
				{
					cout << "Недостаточно создано векторов для проведения операции!\n";
					continue;
				}
				else 
				{
					char name_search;
					cout << "Введите имя интересующего вектора:\n";
					cin >> name_search;
					Vector vector_search = search_vector_in_array_of_name(vectors, name_search);
					cout << "Координаты вектора " << name_search << " = {" << vector_search.GetX() << ", " << vector_search.GetY() << ", " << vector_search.GetZ() << "}\n";
				}
				continue;
			case '3':
				print_menu_item(choice);
				if (not(check_vectors_count(2)))
				{
					cout << "Недостаточно создано векторов для проведения операции!\n";
					continue;
				}
				else
				{
					char name_1, name_2;
					cout << "Введите имена суммируемых векторов:\n";
					cin >> name_1 >> name_2;
					Vector vector_1 = search_vector_in_array_of_name(vectors, name_1);
					Vector vector_2 = search_vector_in_array_of_name(vectors, name_2);
					cout << "Выполняется сложение следующих векторов:\n";
					cout << name_1 << " = {" << vector_1.GetX() << ", " << vector_1.GetY() << ", " << vector_1.GetZ() << "}\n";
					cout << name_2 << " = {" << vector_2.GetX() << ", " << vector_2.GetY() << ", " << vector_2.GetZ() << "}\n";
					Vector result = vector_1.Sum(vector_2);
					cout << name_1 << " + " << name_2 << " = {" << result.GetX() << ", " << result.GetY() << ", " << result.GetZ() << "}\n";
				}
				continue;
			case '4':
				print_menu_item(choice);
				if (not(check_vectors_count(2)))
				{
					cout << "Недостаточно создано векторов для проведения операции!\n";
					continue;
				}
				else
				{
					char name_1, name_2;
					cout << "Введите имя уменьшаемого вектора:\n";
					cin >> name_1;
					cout << "Введите имя вычитаемого вектора:\n";
					cin >> name_2;
					Vector vector_1 = search_vector_in_array_of_name(vectors, name_1);
					Vector vector_2 = search_vector_in_array_of_name(vectors, name_2);
					cout << "Выполняется вычитание следующих векторов:\n";
					cout << name_1 << " = {" << vector_1.GetX() << ", " << vector_1.GetY() << ", " << vector_1.GetZ() << "}\n";
					cout << name_2 << " = {" << vector_2.GetX() << ", " << vector_2.GetY() << ", " << vector_2.GetZ() << "}\n";
					Vector result = vector_1.Dif(vector_2);
					cout << name_1 << " - " << name_2 << " = {" << result.GetX() << ", " << result.GetY() << ", " << result.GetZ() << "}\n";
				}
				continue;
			case '5':
				print_menu_item(choice);
				if (not(check_vectors_count(2)))
				{
					cout << "Недостаточно создано векторов для проведения операции!\n";
					continue;
				}
				else
				{
					char name_1, name_2;
					cout << "Введите имена перемножаемых векторов:\n";
					cin >> name_1 >> name_2;
					Vector vector_1 = search_vector_in_array_of_name(vectors, name_1);
					Vector vector_2 = search_vector_in_array_of_name(vectors, name_2);
					cout << "Вычисляется скалярное произведение следующих векторов:\n";
					cout << name_1 << " = {" << vector_1.GetX() << ", " << vector_1.GetY() << ", " << vector_1.GetZ() << "}\n";
					cout << name_2 << " = {" << vector_2.GetX() << ", " << vector_2.GetY() << ", " << vector_2.GetZ() << "}\n";
					double result = vector_1.Mult(vector_2);
					cout << name_1 << " * " << name_2 << " = " << result << "\n";
				}
				continue;
			case '6':
				print_menu_item(choice);
				if (not(check_vectors_count(2)))
				{
					cout << "Недостаточно создано векторов для проведения операции!\n";
					continue;
				}
				else
				{
					char name_1, name_2;
					cout << "Введите имена интересующих векторов:\n";
					cin >> name_1 >> name_2;
					Vector vector_1 = search_vector_in_array_of_name(vectors, name_1);
					Vector vector_2 = search_vector_in_array_of_name(vectors, name_2);
					cout << "Вычисляется косинус угла между следующими векторами:\n";
					cout << name_1 << " = {" << vector_1.GetX() << ", " << vector_1.GetY() << ", " << vector_1.GetZ() << "}\n";
					cout << name_2 << " = {" << vector_2.GetX() << ", " << vector_2.GetY() << ", " << vector_2.GetZ() << "}\n";
					double result = vector_1.CosVectors(vector_2);
					cout << "Cos = " << result << "\n";
					continue;
				}
			case '7':
				print_menu_item(choice);
				cout << "Осуществляется выход из программы...";
				close = true;
				continue;
		}
	}
}