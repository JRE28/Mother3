#include <iostream>
#include <SFML/Graphics.hpp>
#include "World1.h"
using namespace std;


World::World()
{
  wview = prepareView();
}

void World::initBackground(int x0, int y0, int w, int h)
{
  tbackground.loadFromFile("Grass.jpg");
  tbackground.setRepeated(true);
  background.setTexture(tbackground);
  background.setTextureRect(sf::IntRect(x0,y0,w,h));
  background.setPosition(0,0);
}

sf::View World::prepareView()
{
  wview.setCenter(scrX/2, scrY/2);
  wview.setSize(scrX, scrY);
  return wview;
}
