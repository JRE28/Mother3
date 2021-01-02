#ifndef WORLD_H
#define WORLD_H

class World
{
public:
  World();
  const static int scrX = 1200;
  const static int scrY = 600;
  sf::Texture tbackground;
  sf::Sprite background;
  sf::RectangleShape area;
  void initBackground(string path, int x0 = 0, int y0 = 0, int w = scrX, int h = scrY);
  sf::View wview;
private:
  sf::View prepareView();
};

#endif
