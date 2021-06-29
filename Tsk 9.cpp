#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

void ToMas(int* source, int size)
{
	setlocale(LC_ALL, "rus");
	double arifm = 0;
	double kvadrat = 0;
	double kvadratOtklon = 0;
	//������� ��������������:
	for (int i = 0; i < size; i++)
		arifm += source[i];
	arifm = arifm / size;
	//����� ��������� ��������:
	for (int i = 0; i < size; i++)
		kvadrat += pow((source[i] - arifm), 2);
	//����������:
	for (int i = 0; i < size; i++)
		kvadratOtklon = sqrt(kvadrat / size);
	cout << "������� ������������ ���������� ������� �����: " << kvadratOtklon;
}

void test()
{
	cout << "                    ����" << endl;
	cout << "��� ������� � �������� 10 � ������� �� 1 �� 10" << endl;
	const int size = 10;
	int source[size] = { 1,2,3,4,5,6,7,8,9,10 };
	double arifm = 0;
	double kvadrat = 0;
	double kvadratOtklon = 0;
	for (int i = 0; i < size; i++)
		arifm += source[i]; //������ ��������� 55
	cout << "�������������� �����: " << arifm << endl;;
	arifm = arifm / size; //������ ��������� 5.5
	cout << "������� ��������������: " << arifm << endl;
	for (int i = 0; i < size; i++)
		kvadrat += pow((source[i] - arifm), 2); //������ ��������� 82.5
	cout << "������� ������������: " << kvadrat << endl;
	for (int i = 0; i < size; i++)
		kvadratOtklon = sqrt(kvadrat / size); //�������������� ����� 2.9
	cout << "������� ������������ ���������� �������: " << kvadratOtklon << endl;
}

int main()
{
	const int size = 1000;
	int source[size];
	//��������� ������ ���������� �������
	for (int i = 0; i < size; i++)
		source[i] = rand() % 100 + 1;
	//�������� �������, ������� ��������� ������� ������������ ����������
	ToMas(source, size);
	cout << endl;
	//�������� ������� ��� ���� ������������� ����� �� ������� ������� �������� 10, ������������ ������� �� 1 �� 10
	test();
	return 0;
}