#include <iostream>
#include <SFML/Graphics.hpp>
#include <mutex>
#include <thread>
using namespace std;

int scrX = 1200;
int scrY = 600;
sf::RenderWindow window(sf::VideoMode(scrX,scrY), "Bola de kk");
mutex mtx;

float x = 50.f;
float y = 100.f;
bool fall = false;
float radC1 = 100.f;
int pulse = 1;
sf::CircleShape circle(radC1);

int x1 = 10, y1 = 300;
bool once = true;
sf::CircleShape bullet(10.f);


void shoot(sf::Vector2f direction)
{
    if(once)
    {
        bullet.setFillColor(sf::Color::Yellow);
        bullet.setPosition(x1, y1);
    }
    sf::Vector2f pos = bullet.getPosition();
    
    if(pos.x < 1200 && pos.x > 0 && pos.y < 600 && pos.y > 0)
    {
        pos = bullet.getPosition();
        bullet.move(direction);
        mtx.lock();
        window.draw(bullet);
        mtx.unlock();
    }
    once = false;
}

void circlee()
{
    circle.setPosition(x, y);
    x+= 0.2 * pulse;
    if (fall)
    {
        y+= 0.98;
    }
    if(x >= scrX - radC1*2)
    {
        pulse = -1;
    }
    mtx.lock();
    window.draw(circle);
    mtx.unlock();
}

int main()
{   
    
    
    
    
	while(window.isOpen())
	{
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                fall = true;
            }
        }
        window.clear();
        thread tshoot (shoot, sf::Vector2f(0.2f,-0.1f));
        thread tcirclee(circlee);
        tshoot.join();
        tcirclee.join();
        window.display();
	}
}