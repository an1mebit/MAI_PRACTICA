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
	//Среднее арифметическое:
	for (int i = 0; i < size; i++)
		arifm += source[i];
	arifm = arifm / size;
	//Сумма квадратов разности:
	for (int i = 0; i < size; i++)
		kvadrat += pow((source[i] - arifm), 2);
	//Отклонение:
	for (int i = 0; i < size; i++)
		kvadratOtklon = sqrt(kvadrat / size);
	cout << "Среднее квадратичное отклонения массива равна: " << kvadratOtklon;
}

void test()
{
	cout << "                    ТЕСТ" << endl;
	cout << "Для массива с размером 10 и числами от 1 до 10" << endl;
	const int size = 10;
	int source[size] = { 1,2,3,4,5,6,7,8,9,10 };
	double arifm = 0;
	double kvadrat = 0;
	double kvadratOtklon = 0;
	for (int i = 0; i < size; i++)
		arifm += source[i]; //Должно получится 55
	cout << "Алгебраическая сумма: " << arifm << endl;;
	arifm = arifm / size; //Должно получится 5.5
	cout << "Среднее арифметическое: " << arifm << endl;
	for (int i = 0; i < size; i++)
		kvadrat += pow((source[i] - arifm), 2); //Должно получится 82.5
	cout << "Среднее квадратичное: " << kvadrat << endl;
	for (int i = 0; i < size; i++)
		kvadratOtklon = sqrt(kvadrat / size); //Приблизительно равно 2.9
	cout << "Среднее квадратичное отклонения массива: " << kvadratOtklon << endl;
}

int main()
{
	const int size = 1000;
	int source[size];
	//Заполняем массив случайными числами
	for (int i = 0; i < size; i++)
		source[i] = rand() % 100 + 1;
	//Вызываем функцию, которая вычисляет среднее квадратичное отклонения
	ToMas(source, size);
	cout << endl;
	//Вызываем функцию для пока промежуточных шагов на примере массива размером 10, заполненного числами от 1 до 10
	test();
	return 0;
}