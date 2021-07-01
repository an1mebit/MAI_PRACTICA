#include "Formuls.h"
#include <math.h>
#include <windows.h>

int main()

{					
	setlocale(LC_ALL, "rus");
	std::cout << "Введите горизонтальную и вертикальную скорость" << std::endl;
	std::cin >> Vx >> Vy;
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	MoveToEx(hdc, 0, 400, NULL);
	LineTo(hdc, 200, 400);
	MoveToEx(hdc, 0, 400, NULL);
	LineTo(hdc, 0, 300);

	for (x = Vx * t; x <= 200; t++) // O(0,400) - center
		for (y = Vy * t - a * t * t / 2; y>=400; t++)
		{
			MoveToEx(hdc, x, y + 400, NULL);
			LineTo(hdc, x + 1, y + 399);
		}

	return 0;
}
