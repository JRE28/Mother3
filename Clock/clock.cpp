#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{

	sf::Clock clock;
	sf::Time time = clock.restart();
	cout << time.asMicroseconds() << endl;
}