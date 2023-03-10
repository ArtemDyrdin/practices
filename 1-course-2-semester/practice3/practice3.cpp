#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class KinematicSolver
{
public:
	int m_L1 = 0; // длины колен
	int m_L2 = 0;
	double m_x = 0; // координаты среденей точки
	double m_y = 0;
	double m_alpha = 0; // углы колен
	double m_beta = 0;

public:
	KinematicSolver() {};

	void SetLengths(unsigned int L1, unsigned int L2)
	{
		m_L1 = L1;
		m_L2 = L2;
	}

	void Solve(double x, double y)
	{
		double B = sqrt(pow(x, 2) + pow(y, 2)); // расстояние от начала до заданной точки

		// углы в радианах в первом случае
		m_alpha = acos(x / B) - acos((pow(m_L1, 2) - pow(m_L2, 2) + (B * B)) / (2 * B * m_L1));
		m_beta = acos(-1) - acos((pow(m_L1, 2) + pow(m_L2, 2) - (B * B)) / (2 * m_L1 * m_L2));

		// если ср. точка выше нуля берем углы в первом случае, иначе другие
		if (sin(m_alpha) >= 0) {
			m_x = m_L1 * cos(m_alpha); // координаты средней точки
			m_y = m_L1 * sin(m_alpha);
		}
		else {
			m_alpha = acos(x / B) + acos((pow(m_L1, 2) - pow(m_L2, 2) + (B * B)) / (2 * B * m_L1)); // углы во втором случае
			m_beta = -m_beta;
			m_x = m_L1 * cos(m_alpha); // координаты средней точки
			m_y = m_L1 * sin(m_alpha);
		}
		
		m_alpha = static_cast<float>(m_alpha * 180 / acos(-1)); // переводим в градусы
		m_beta = m_alpha + static_cast<float>(m_beta * 180 / acos(-1));
	}
};



int main()
{
	KinematicSolver Arm;

	int L1, L2;
	cout << "Enter a lengthes of lines (1-10 recommended): " << endl;
	cin >> L1;
	cin >> L2;

	Arm.SetLengths(L1, L2);

	int x, y;
	cout << "Enter x and y (0-10 recommended): " << endl;
	cin >> x;
	cin >> y;

	Arm.Solve(x, y);

	cout << "Angles: " << Arm.m_alpha << "\t" << Arm.m_beta << endl;

	RenderWindow window(VideoMode(1000.f, 1000.f), "Kinematic Solver");

	// задаём оси
	RectangleShape Ox(Vector2f(1000.f, 1.f));
	RectangleShape Oy(Vector2f(1.f, 1000.f));
	Ox.setFillColor(Color::White);
	Oy.setFillColor(Color::White);
	Ox.setPosition(0.f, 900.f);
	Oy.setPosition(500.f, 0.f);

	// плечо-предплечье
	RectangleShape line1(Vector2f(static_cast<float>(50 * Arm.m_L1), 5.f));
	RectangleShape line2(Vector2f(static_cast<float>(50 * Arm.m_L2), 5.f));
	line1.setFillColor(Color::Red);
	line2.setFillColor(Color::Yellow);

	line1.setPosition(500.f, 900.f);
	line2.setPosition(static_cast<float>(500 + 50 * Arm.m_x), static_cast<float>(900 - 50 * Arm.m_y));

	line1.rotate(-1 * Arm.m_alpha);
	line2.rotate(-1 * Arm.m_beta);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(line1);
		window.draw(line2);
		window.draw(Ox);
		window.draw(Oy);
		window.display();
	}
}
