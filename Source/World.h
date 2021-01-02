#ifndef WORLD_H
#define WORLD_H
using namespace std;
class World
{
public:
  World();
  const static int scrX = 1200;
  const static int scrY = 600;
  sf::Texture tbackground;
  sf::Sprite background;
  sf::RectangleShape area;
  void setBackground(string path, int x0, int y0, int w, int h);
  sf::View wview;
private:
  sf::View prepareView();
};

#endif
