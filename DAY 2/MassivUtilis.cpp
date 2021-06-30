#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

void SkofromList(int* source, int size)
{
	setlocale(LC_ALL, "rus");
	double arifm = 0;
	double kvadrat = 0;
	double kvadratOtklon = 0;
	for (int i = 0; i < size; i++)
		arifm += source[i];
	arifm = arifm / size;
	for (int i = 0; i < size; i++)
		kvadrat += pow((source[i] - arifm), 2);
	for (int i = 0; i < size; i++)
		kvadratOtklon = sqrt(kvadrat / size);
	cout << kvadratOtklon;
}

bool CompareMas(int* a, int* b)
{
	if (a != b) return false;

	return true;
}

int testSkofromList()
{
	cout << "                    TEST" << endl;
	int mas1[5] = { 1,2,3,4,5 };
	int mas2[5] = { 4,1,2,5,3 };
	SkofromList(mas1, 5);
	SkofromList(mas2, 5);
	bool test1 = CompareMas(mas1, mas2);

	int mas3[10] = { -1,-10,20,0,0,0,12,4,1,7 };
	int mas4[10] = { 0,-10,20,0,0,0,12,4,1,4 };
	SkofromList(mas3, 10);
	SkofromList(mas4, 10);
	bool test2 = CompareMas(mas3, mas4);
	return ((test1 && test2) ? 0 : -1);
}

void runTest(int (*testFunction)(), const std::string& testName)
{
	if (testFunction() == 0)
		std::cout << "Test " << testName << " - OK" << std::endl;
	else
		std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main()
{
	runTest(testSkofromList, "testlRoundShiftMas");
}