#include <iostream>
#include <cmath>

/*
Вариант 4 задание 6 - 7.
Разработать программу для моделирования полета брошенного с  со скоростью vx (горизонтальная составляющая) и vx (горизонтальная составляющая) шарика массой m.
При соударении с землей шарик прилипает. 
- Вычисления положения (h) и параметров движения шарика (v, a) через заданный промежуток времени
- Позволять записывать параметы движения шарика и метку времении в односвязный списко
- Печатать на экран информацию о траектории движения шарика за заданный промежуток времени

*/
using namespace std;

const double g = 9.8;

struct Node
{
	double h, Vx, Vy, a, t;
	Node* next;
};

void initList(Node* head)
{
	head->h = 0;
	head->Vx = 0;
	head->Vy = 0;
	head->a = 0;
	head->t = 0;
	head->next = NULL;
}

void showList(Node* head, double h, double Vx, double Vy, double a, double t)
{
	Node* print = head;
	while (print != 0)
	{
		cout << "t= " << print->t << ", Vx = " << print->Vx << ", Vy = " << print->Vy << ", a= " << print->a << ", h= " << print->h << "." << endl;
		print = print->next;
	}
	cout << endl;
}

void pushNode(double h, double a, double Vx, double Vy, double t)
{
	Node* nd = new Node();
	while (nd->next != NULL)
		nd = nd->next;
	nd->h = h;
	nd->Vx = Vx;
	nd->Vy = Vy;
	nd->a = a;
	nd->t = t;

	nd->next = new Node();
	initList(nd->next);
}

Node* Physics(double h, double Vx, double Vy, double dt)
{
	Node* out = new Node();
	
	double Vxt = Vx; //Vx проекция скорости на ось x, не изменется
	double Vyt = Vy - g * dt; //Vy - проекция скорости на ось y, изменяется с течением времени dt
	double V = sqrt(pow(Vxt, 2) + pow(Vyt, 2)) / 2;
	double a = pow(Vyt,2)/(t * t);
	double max_t, max_h; //максимальные значения скорости и времени

	if (V > 0)
	{
		max_t = V / a;
		max_h = Vyt / (2 * g);

		showList(out, h, Vxt, Vyt, g, 0);
	}
	else
	{
		showList(out, h, Vxt, Vyt, 0, 0);
	}

	double ct = dt;
	while (ct <= max_t)
	{
		h+= V * ct - a * ct * ct / 2;
		Vxt = Vx;
		Vyt -= Vy - g * (dt + ct);
		showList(out, h, Vxt, Vyt, g, ct);
		ct++;
	}

	Vxt = Vx;
	Vyt = Vy - g * (ct - max_t);
	V = a * (ct - max_t);
	h = max_h - a * pow(ct - max_t, 2) / 2;
	showList(out, h, Vxt, Vyt, a, ct);
	while (ct < dt + max_t)
	{
		h -= V * ct - a * ct * ct / 2;
		Vxt = Vx;
		Vyt += Vy + g * (dt + ct);
		showList(out, h, Vxt, Vyt, g, ct);
		ct++;
	}

	showList(out, 0, 0, 0, 0, ct);
	cout << "Stop" << endl;
	return out;
}

bool testPhysics()
{
	Node* test = Physics(5,2,2,0.1);
	if (test->h > 0 && test->Vx > 0 && test->Vy > 0 && test->a > 0 && test->t == 0)
	{
		test = test->next;
		if (test->h == 0 && test->Vx == 0 && test->Vy == 0 && test->a == 0 && test->t >= 0)
		{
			return true;
		}
	}
	return false;
}

void runTest(bool (*testFunction)(), const string& testName)
{
	if (testFunction() == true)
		cout << "Test " << testName << " - OK" << endl;
	else
		cout << "Test " << testName << " - FAIL" << endl;
}

int main()
{
	runTest(testPhysics, "TestPhysics");
}
