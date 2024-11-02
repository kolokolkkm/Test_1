#include <iostream>
#include "Vector.h"
#include <vector>
using namespace std;

std::ostream& operator<<(std::ostream& stream, const Vector<double>& v)
{
	stream << "{" << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << "}\n";
	return stream;
}

void print_menu_item(char item) {
	cout << "Выбран " << item << " пункт меню\n";
}

bool check_vectors_count(int num_v)
{
	if ((num_v - Vector<double>::GetCountVectors()) > 0)
		return false;
	else
		return true;
}

int main()
{
	char choice;
	bool close = false;
	setlocale(LC_ALL, "RU");
	std::vector<Vector<double>*> vectors;
	while (close == false) 
	{
		cout << "Выберите действие:\n";
		cout << "1. Создать вектор;\n";
		cout << "2. Вывести координаты вектора;\n";
		cout << "3. Сложить два вектора;\n";
		cout << "4. Вычесть из одного вектора другой;\n";
		cout << "5. Вычислить скалярное произведение векторов;\n";
		cout << "6. Найти косинус угла между векторами;\n";
		cout << "7. Изменить координаты существующего вектора;\n";
		cout << "8. Выйти из программы.\n";
		cin >> choice;
		switch (choice)
		{
		default:
			cout << "Введеные данные не соответствуют пунктам меню!\n";
			continue;
			case '1':
				print_menu_item(choice);
				char choice_1;
				cout << "Выберите, какой вектор создать:\n";
				cout << "1. Обычный;\n";
				cout << "2. Базисный:\n";
				cin >> choice_1;
				switch (choice_1)
				{
				default:
					break;
				case '1':
				{
					char name_vector_1;
					double x, y, z;
					cout << "Введите имя будущего вектора:\n";
					cin >> name_vector_1;
					cout << "Введите координаты X, Y, Z для будущего вектора\n";
					cin >> x >> y >> z;
					Vector v_add = Vector{ name_vector_1, x, y, z };
					vectors.push_back(&v_add);
					cout << "Вектор " << name_vector_1 << " = {" << x << ", " << y << ", " << z << "} создан!\n";
					continue;
				}
				case '2':
				{
					char name_vector_2, axis;
					double len;
					cout << "Введите имя будущего вектора:\n";
					cin >> name_vector_2;
					cout << "Введите длину вектора:\n";
					cin >> len;
					cout << "Введите ось вектора:\n";
					cin >> axis;
					BazisVector bv_add = BazisVector{ name_vector_2, len, axis };
					vectors.push_back(&bv_add);
					cout << "Создан базисный вектор " << name_vector_2 << " = " << bv_add;
					continue;
				}
				}
			case '2':
				print_menu_item(choice);
				if (not(check_vectors_count(1)))
				{
					cout << "Нет созданных векторов!\n";
					continue;
				}
				else
				{
					char name_search;
					int i_src;
					cout << "Введите имя интересующего вектора:\n";
					cin >> name_search;
					i_src = Vector<double>::search_index_vector_in_array_of_name(vectors, name_search);
					Vector<double> vector_search = *vectors[i_src];
					cout << "Координаты вектора " << name_search << " = " << vector_search;
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
					int i_1, i_2;
					cout << "Введите имена суммируемых векторов:\n";
					cin >> name_1 >> name_2;
					i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_1);
					i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_2);
					Vector<double>* vector_1 = vectors[i_1];
					Vector<double>* vector_2 = vectors[i_2];
					cout << "Выполняется сложение следующих векторов:\n";
					cout << name_1 << " = " << *vector_1;
					cout << name_2 << " = " << *vector_2;
					Vector result = vector_1->Sum(*vector_2);
					cout << name_1 << " + " << name_2 << " = " << result;
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
					int i_1, i_2;
					cout << "Введите имя уменьшаемого вектора:\n";
					cin >> name_1;
					cout << "Введите имя вычитаемого вектора:\n";
					cin >> name_2;
					i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_1);
					i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_2);
					Vector<double>* vector_1 = vectors[i_1];
					Vector<double>* vector_2 = vectors[i_2];
					cout << "Выполняется вычитание следующих векторов:\n";
					cout << name_1 << " = " << *vector_1;
					cout << name_2 << " = " << *vector_2;
					Vector<double> result = *vector_1 - *vector_2;
					cout << name_1 << " - " << name_2 << " = " << result;
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
					int i_1, i_2;
					i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_1);
					i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_2);
					Vector<double>* vector_1 = vectors[i_1];
					Vector<double>* vector_2 = vectors[i_2];
					cout << "Вычисляется скалярное произведение следующих векторов:\n";
					cout << name_1 << " = " << *vector_1;
					cout << name_2 << " = " << *vector_2;
					double result = (*vector_1) * (*vector_2);
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
					int i_1, i_2;
					i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_1);
					i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_2);
					Vector<double>* vector_1 = vectors[i_1];
					Vector<double>* vector_2 = vectors[i_2];
					cout << "Вычисляется косинус угла между следующими векторами:\n";
					cout << name_1 << " = " << vector_1;
					cout << name_2 << " = " << vector_2;
					double result = (*vector_1).CosVectors(*vector_2);
					cout << "Cos = " << result << "\n";
					continue;
				}
			case '7':
				print_menu_item(choice);
				if (not(check_vectors_count(1)))
				{
					cout << "Нет созданных векторов!\n";
					continue;
				}
				else
				{
					char choice_set, name;;
					cout << "Как сменить координаты?\n";
					cout << "1. Ввести координаты самостоятельно;\n";
					cout << "2. Позаимствовать координаты другого вектора.\n";
					cin >> choice_set;
					switch (choice_set)
					{
					default:
						cout << "Введеные данные не соответствуют пунктам меню!\n";
						continue;
					case '1':
					{
						double new_x, new_y, new_z;
						cout << "Введите имя вектора, координаты которого требуется сменить:\n";
						cin >> name;
						int i_src = Vector<double>::search_index_vector_in_array_of_name(vectors, name);
						Vector<double>* vector_searched = vectors[i_src];
						cout << "Введите новые координаты X, Y, Z для вектора:\n";
						cin >> new_x >> new_y >> new_z;
						SetCordinatesVector(*vector_searched, new_x, new_y, new_z);
						cout << "Координаты вектора " << name << " изменены на " << *vector_searched;
						continue;
					}
					case '2':
					{
						if (not(check_vectors_count(2)))
						{
							cout << "Недостаточно создано векторов для проведения операции!\n";
							continue;
						}
						else
						{
							char name_2;
							cout << "Введите имя вектора, координаты которого требуется сменить:\n";
							cin >> name;
							int i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name);
							Vector<double>* vector_searched_1 = vectors[i_1];
							cout << "Введите имя вектора, координаты которого заимствуются:\n";
							cin >> name_2;
							int i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name);
							Vector<double>* vector_searched_2 = vectors[i_2];
							SetCordinatesVector(*vector_searched_1, *vector_searched_2);
							cout << "Координаты вектора " << name << " изменены на " << *vector_searched_2;
							continue;
						}
					}
					}
				}
				continue;
			case '8':
				print_menu_item(choice);
				cout << "Осуществляется выход из программы...";
				close = true;
				continue;
		}
	}
}