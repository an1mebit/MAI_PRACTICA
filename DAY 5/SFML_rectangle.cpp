#include <SFML/Graphics.hpp>

using namespace sf;

//Вариант 4

bool transf = false;
int x = 100;
int y = 50;
int main()
{
	RenderWindow window(VideoMode(800, 600), "pramougolnik");
	window.clear(Color::Black);

	RectangleShape rectangle(Vector2f(x , y));
	rectangle.setFillColor(Color::White);
	rectangle.move(150, 150);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();


			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::D) transf = true;
				if (event.key.code == Keyboard::A) transf = false;
			}
		}


		if (transf)
			rectangle.scale(1.0002, 1); //слишком быстро уходит в сторону при >1.01
		window.draw(rectangle);
		sleep(milliseconds(10));

		window.display();
	}
}
