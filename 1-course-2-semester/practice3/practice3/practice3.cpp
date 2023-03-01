#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

class KinematicSolver {
public:
    int m_L1;
    int m_L2;
    int m_x;
    int m_y;
    float m_alpha;
    float m_beta;

public:
    void SetLengthes(float L1, float L2) {
        m_L1 = (int)L1;
        m_L2 = (int)L2;
    }
    void Solve(float x, float y) {
        m_x = (int)x;
        m_y = (int)y;
        cout << "X, Y: " << m_x << " " << m_y << endl;
        findAngles();
    }
private:
    void findAngles() {
        double B = (double)pow(m_x*m_x + m_y*m_y, 0.5);
        if (B > m_L1 + m_L2) {
            cout << "Distance to (x, y) > L1 + L2" << endl;
        }
        else {
            m_alpha = (float)(acos(m_x / B) - acos((m_L1 * m_L1 - m_L2 * m_L2 + B * B) / (2 * B * m_L1)));
            m_beta = (float)(3.1415 - acos((m_L1 * m_L1 + m_L2 * m_L2 - B * B) / (2 * m_L1 * m_L2)));

            cout << "Alpha: " << m_alpha << endl;
            cout << "Beta: " << m_beta << endl;
        }
    }
};

int main()
{
    const int width = 800;
    const int heigth = 800;

    cout << "Lengthes:" << endl;
    float L1, L2;
    cin >> L1;
    cin >> L2;
    cout << "Dot:" << endl;
    float x, y;
    cin >> x;
    cin >> y;

    KinematicSolver One;
    One.SetLengthes(L1, L2);
    One.Solve(x, abs(y));

    // dot
    sf::CircleShape dot(10, 10);
    //dot.setPosition(x, (heigth/2)-abs(y));
    dot.setPosition(int(abs(One.m_L1 * cos(One.m_alpha))), heigth / 2 - int(abs(One.m_L1 * One.m_alpha*180/3.14)));
    cout << "Dot: " << int(abs(One.m_L1 * cos(One.m_alpha))) << " " << int(abs(One.m_L1 * One.m_alpha * 180 / 3.14));
    dot.setFillColor(sf::Color(sf::Color::Green));

    // 1st triangle (line1)
    sf::RectangleShape rectangle1(sf::Vector2f(L1, 5));
    rectangle1.setFillColor(sf::Color(sf::Color::Blue));
    rectangle1.setRotation(cos(One.m_alpha)*180/3.14);
    rectangle1.setPosition(0, heigth / 2);

    // 2nd triangle (line2)
    sf::RectangleShape rectangle2(sf::Vector2f(L2, 5));
    rectangle2.setFillColor(sf::Color(sf::Color::Red));
    rectangle2.setRotation(cos(One.m_beta) * 180 / 3.14);
    rectangle2.setPosition(int(abs(One.m_L1 * cos(One.m_alpha))), heigth / 2 - int(abs(One.m_L1 * One.m_alpha * 180 / 3.14)));

    cout << "Alpha grad: " << cos(One.m_alpha) * 180 / 3.14 << endl;
    cout << "Beta grad: " << cos(One.m_beta) * 180 / 3.14 << endl;


    sf::RenderWindow window(sf::VideoMode(width, heigth), "Practice #3");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(dot);
        window.display();
    }

    return 0;
}