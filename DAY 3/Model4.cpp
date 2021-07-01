#include "Formuls.h"
#include <math.h>
#include <windows.h>

const int K = 3;

int main()

{					
	setlocale(LC_ALL, "rus");
	std::cout << "Введите скорость по горизонтали, вертикали и массу шара" << std::endl;
	std::cin >> Vx >> Vy >> m;
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	MoveToEx(hdc, 0, 400, NULL);
	LineTo(hdc, 200, 400);
	MoveToEx(hdc, 0, 400, NULL);
	LineTo(hdc, 0, 300);


	x = Vx * t;
	y = Vy * t - a * t * t / 2;
	t++;
	for (x = Vx * t; x <= 200; t++) // O(0,400) - center
		for (y = Vy * t - a * t * t / 2; y>=400; t++)
		{
			MoveToEx(hdc, x, y + 400, NULL);
			LineTo(hdc, x + 1, y + 399);
		}
	/*while (y >= 0)
	{
		yk = 590 - K * y;
		xk = 100 + x;
		Fx = -R * Vx;
		Fy = -R * Vy;
		ay = Fy / m - g;
		ax = Fx / m;
		y = y + Vy * dt + (ay * pow(dt, 2)) / 2;
		Vy = Vy + ay * dt;
		x = x + Vx * dt + (ax * pow(dt, 2)) / 2;
		Vx = Vx + ax * dt;
		t = t + dt;
		if (h > hmax) hmax = h;
	}
	std::cout << "максимальная высота равна: " << hmax << std::endl;
	std::cout << sqrt(pow(ax, 2) + pow(ay, 2)) << std::endl;
	*/
	return 0;
}