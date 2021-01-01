#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "World1.h"
using namespace std;

int scrX = 1000, scrY = 600;
sf::RenderWindow window(sf::VideoMode(scrX,scrY), "kk");
Player lucas("lsheet.png", 10, 10, sf::Vector2u(4,4));
int dir;
float deltatime;
sf::Clock Clock;
bool pressed = false;
int main()
{
  while(window.isOpen())
  {
    deltatime += Clock.restart().asSeconds();
    window.clear(sf::Color::White);
    sf::Event event;
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          pressed = true;
          dir = lucas.inputTranslate(event.key.code, pressed);
        case sf::Event::KeyReleased:
          pressed = false;
      }
    }

    lucas.sprite.setScale(2, 2);
    deltatime = lucas.animate(dir, 0.3, deltatime);
    window.draw(lucas.sprite);

    window.display();
  }
}
