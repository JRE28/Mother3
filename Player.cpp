#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

Player::Player(const string tname, float xi, float yi, sf::Vector2u imgcount)
{
  setSprite(tname);
  imagecount.x = imgcount.x;
  imagecount.y = imgcount.y;
  sprite.setPosition(xi, yi);
  uvrect.width = texture.getSize().x / float(imgcount.x);
  uvrect.height = texture.getSize().y / float(imgcount.y);
}

bool Player::setSprite(string dir, bool smooth)
{
  if(texture.loadFromFile(dir))
  {
    if(smooth = true)
    {
      texture.setSmooth(true);
      return true;
    }
    sprite.setTexture(texture);
    size = texture.getSize();
    return true;
  }
  return false;
}

bool Player::setSprite(string dir)
{
  if(texture.loadFromFile(dir))
  {
    sprite.setTexture(texture);
    return true;
  }
  return false;
}

int Player::inputTranslate(sf::Keyboard::Key key, bool pressed)
{
  int dir;  //Resumido para evitar condiciones largas
  dir = 0;
  if(pressed)
  {
    switch (key) {
      case sf::Keyboard::Up:
        direct.x = 0;
        direct.y = 1;
        dir = UP;
        break;
        case sf::Keyboard::Down:
        direct.x = 0;
        direct.y = -1;
        dir = DOWN;
        break;
        case sf::Keyboard::Right:
        direct.x = 1;
        direct.y = 0;
        dir = RIGHT;
        break;
        case sf::Keyboard::Left:
        direct.x = -1;
        direct.y = 0;
        dir = LEFT;
        break;
      }
    }
  return dir;
}
float Player::animate(int dir, float stime, float dtime)
{
  switch(dir)
  {
    case UP:
      currentimage.y = 3;
      break;
    case DOWN:
      currentimage.y = 0;
      break;
    case LEFT:
      currentimage.y = 1;
      break;
    case RIGHT:
      currentimage.y = 2;
      break;
  }
  //currentimage = sf::Vector2u(x, y)

  if(dtime >= stime)
  {
    dtime-= stime;
    currentimage.x = xa;

    if(xa < imagecount.x -1)
    {
      xa++;
    } else {xa = 0;}

  }

  sprite.setTextureRect(sf::IntRect(currentimage.x*uvrect.width, currentimage.y*uvrect.height, uvrect.width, uvrect.height));
  return dtime; //Returns deltatime
}
