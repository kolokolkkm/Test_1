#include <iostream>
#include "Vector.h"
#include <vector>
#include <Windows.h>

using namespace std;

std::ostream &operator<<(std::ostream &stream, const Vector<double> &v)
{
	stream << "{" << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << "}\n";
	return stream;
}

void print_menu_item(char item)
{
	cout << "������ " << item << " ����� ����\n";
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
	SetConsoleCP(1251);
	std::vector<Vector<double> *> vectors;
	while (close == false)
	{
		cout << "�������� ��������:\n";
		cout << "1. ������� ������;\n";
		cout << "2. ������� ���������� �������;\n";
		cout << "3. ������� ��� �������;\n";
		cout << "4. ������� �� ������ ������� ������;\n";
		cout << "5. ��������� ��������� ������������ ��������;\n";
		cout << "6. ����� ������� ���� ����� ���������;\n";
		cout << "7. �������� ���������� ������������� �������;\n";
		cout << "8. ����� �� ���������.\n";
		cin >> choice;
		switch (choice)
		{
		default:
			cout << "�������� ������ �� ������������� ������� ����!\n";
			continue;
		case '1':
			print_menu_item(choice);
			char choice_1;
			cout << "��������, ����� ������ �������:\n";
			cout << "1. �������;\n";
			cout << "2. ��������:\n";
			cin >> choice_1;
			switch (choice_1)
			{
			default:
				break;
			case '1':
			{
				char name_vector_1;
				double x, y, z;
				cout << "������� ��� �������� �������:\n";
				cin >> name_vector_1;
				cout << "������� ���������� X, Y, Z ��� �������� �������\n";
				cin >> x >> y >> z;
				Vector v_add = Vector{name_vector_1, x, y, z};
				vectors.push_back(&v_add);
				cout << "������ " << name_vector_1 << " = {" << x << ", " << y << ", " << z << "} ������!\n";
				continue;
			}
			case '2':
			{
				char name_vector_2, axis;
				double len;
				cout << "������� ��� �������� �������:\n";
				cin >> name_vector_2;
				cout << "������� ����� �������:\n";
				cin >> len;
				cout << "������� ��� �������:\n";
				cin >> axis;
				BazisVector bv_add = BazisVector{name_vector_2, len, axis};
				vectors.push_back(&bv_add);
				cout << "������ �������� ������ " << name_vector_2 << " = " << bv_add;
				continue;
			}
			}
			continue;
		case '2':
			print_menu_item(choice);
			if (not(check_vectors_count(1)))
			{
				cout << "��� ��������� ��������!\n";
				continue;
			}
			else
			{
				try
				{
					char name_search;
					int i_src;
					cout << "������� ��� ������������� �������:\n";
					cin >> name_search;
					i_src = Vector<double>::search_index_vector_in_array_of_name(vectors, name_search);
					Vector<double> vector_search = *vectors[i_src];
					cout << "���������� ������� " << name_search << " = " << vector_search;
				}
				catch (const string &error_message)
				{
					cout << error_message << "\n";
					continue;
				}
			}
			continue;
		case '3':
			print_menu_item(choice);
			if (not(check_vectors_count(2)))
			{
				cout << "������������ ������� �������� ��� ���������� ��������!\n";
				continue;
			}
			else
			{
				try
				{
					char name_1, name_2;
					int i_1, i_2;
					cout << "������� ����� ����������� ��������:\n";
					cin >> name_1 >> name_2;
					i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_1);
					i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_2);
					Vector<double> *vector_1 = vectors[i_1];
					Vector<double> *vector_2 = vectors[i_2];
					cout << "����������� �������� ��������� ��������:\n";
					cout << name_1 << " = " << *vector_1;
					cout << name_2 << " = " << *vector_2;
					Vector result = vector_1->Sum(*vector_2);
					cout << name_1 << " + " << name_2 << " = " << result;
				}
				catch (const string &error_message)
				{
					cout << error_message << "\n";
					continue;
				}
			}
			continue;
		case '4':
			print_menu_item(choice);
			if (not(check_vectors_count(2)))
			{
				cout << "������������ ������� �������� ��� ���������� ��������!\n";
				continue;
			}
			else
			{
				try
				{
					char name_1, name_2;
					int i_1, i_2;
					cout << "������� ��� ������������ �������:\n";
					cin >> name_1;
					cout << "������� ��� ����������� �������:\n";
					cin >> name_2;
					i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_1);
					i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_2);
					Vector<double> *vector_1 = vectors[i_1];
					Vector<double> *vector_2 = vectors[i_2];
					cout << "����������� ��������� ��������� ��������:\n";
					cout << name_1 << " = " << *vector_1;
					cout << name_2 << " = " << *vector_2;
					Vector<double> result = *vector_1 - *vector_2;
					cout << name_1 << " - " << name_2 << " = " << result;
				}
				catch (const string &error_message)
				{
					cout << error_message << "\n";
					continue;
				}
			}
			continue;
		case '5':
			print_menu_item(choice);
			if (not(check_vectors_count(2)))
			{
				cout << "������������ ������� �������� ��� ���������� ��������!\n";
				continue;
			}
			else
			{
				try
				{
					char name_1, name_2;
					cout << "������� ����� ������������� ��������:\n";
					cin >> name_1 >> name_2;
					int i_1, i_2;
					double result;
					i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_1);
					i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_2);
					Vector<double> *vector_1 = vectors[i_1];
					Vector<double> *vector_2 = vectors[i_2];
					if (!vector_2->LenVector())
					{
						result = ((*vector_1) * 0).LenVector();
					}
					else if (!vector_2->LenVector())
					{
						result = ((*vector_2) * 0).LenVector();
					}
					else
					{
						cout << "����������� ��������� ������������ ��������� ��������:\n";
						cout << name_1 << " = " << *vector_1;
						cout << name_2 << " = " << *vector_2;
						result = (*vector_1) * (*vector_2);
						cout << name_1 << " * " << name_2 << " = " << result << "\n";
					}
				}
				catch (const string &error_message)
				{
					cout << error_message << "\n";
					continue;
				}
			}
			continue;
		case '6':
			print_menu_item(choice);
			if (not(check_vectors_count(2)))
			{
				cout << "������������ ������� �������� ��� ���������� ��������!\n";
				continue;
			}
			else
			{
				try
				{
					char name_1, name_2;
					cout << "������� ����� ������������ ��������:\n";
					cin >> name_1 >> name_2;
					int i_1, i_2;
					i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_1);
					i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name_2);
					Vector<double> *vector_1 = vectors[i_1];
					Vector<double> *vector_2 = vectors[i_2];
					cout << "����������� ������� ���� ����� ���������� ���������:\n";
					cout << name_1 << " = " << vector_1;
					cout << name_2 << " = " << vector_2;
					double result = (*vector_1).CosVectors(*vector_2);
					cout << "Cos = " << result << "\n";
					continue;
				}
				catch (const string &error_message)
				{
					cout << error_message << "\n";
					continue;
				}
			}
		case '7':
			print_menu_item(choice);
			if (not(check_vectors_count(1)))
			{
				cout << "��� ��������� ��������!\n";
				continue;
			}
			else
			{
				char choice_set, name;
				;
				cout << "��� ������� ����������?\n";
				cout << "1. ������ ���������� ��������������;\n";
				cout << "2. �������������� ���������� ������� �������.\n";
				cin >> choice_set;
				switch (choice_set)
				{
				default:
					cout << "�������� ������ �� ������������� ������� ����!\n";
					continue;
				case '1':
				{
					try
					{
						double new_x, new_y, new_z;
						cout << "������� ��� �������, ���������� �������� ��������� �������:\n";
						cin >> name;
						int i_src = Vector<double>::search_index_vector_in_array_of_name(vectors, name);
						Vector<double> *vector_searched = vectors[i_src];
						cout << "������� ����� ���������� X, Y, Z ��� �������:\n";
						cin >> new_x >> new_y >> new_z;
						SetCordinatesVector(*vector_searched, new_x, new_y, new_z);
						cout << "���������� ������� " << name << " �������� �� " << *vector_searched;
						continue;
					}
					catch (const string &error_message)
					{
						cout << error_message << "\n";
						continue;
					}
				}
				case '2':
				{
					if (not(check_vectors_count(2)))
					{
						cout << "������������ ������� �������� ��� ���������� ��������!\n";
						continue;
					}
					else
					{
						try
						{
							char name_2;
							cout << "������� ��� �������, ���������� �������� ��������� �������:\n";
							cin >> name;
							int i_1 = Vector<double>::search_index_vector_in_array_of_name(vectors, name);
							Vector<double> *vector_searched_1 = static_cast<Vector<double> *>(vectors[i_1]);
							cout << "������� ��� �������, ���������� �������� ������������:\n";
							cin >> name_2;
							int i_2 = Vector<double>::search_index_vector_in_array_of_name(vectors, name);
							Vector<double> *vector_searched_2 = static_cast<Vector<double> *>(vectors[i_2]);
							SetCordinatesVector(*vector_searched_1, *vector_searched_2);
							cout << "���������� ������� " << name << " �������� �� " << *vector_searched_2;
							continue;
						}
						catch (const string &error_message)
						{
							cout << error_message << "\n";
							continue;
						}
					}
				}
				}
			}
			continue;
		case '8':
			print_menu_item(choice);
			cout << "�������������� ����� �� ���������...";
			close = true;
			continue;
		}
	}
}