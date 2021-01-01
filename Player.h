#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
using namespace std;


class Player
{
public:

  Player(string tname, float xi, float yi, sf::Vector2u imgcount);
  float x, y;
  static const int UP = 1,DOWN = -1,LEFT = -10, RIGHT = 10;
  sf::Sprite sprite;
  int inputTranslate(sf::Keyboard::Key key, bool pressed);
  float animate(int dir, float stime, float dtime);
private:
  bool setSprite(string dir, bool smooth);
  bool setSprite(string dir);
  sf::Texture texture;
  sf::Vector2u size;
  /*Animation components*/
  int xa = 0; //X spritesheet pos
  sf::IntRect uvrect;
  sf::Vector2u direct;
  sf::Vector2u imagecount;
  sf::Vector2u currentimage;


};

#endif
