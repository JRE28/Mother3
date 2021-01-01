#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "World1.h"
using namespace std;

int scrX = 1200;
int scrY = 600;
sf::RenderWindow window(sf::VideoMode(scrX, scrY), "Lucas running"); //Creates window with fixed size


class Game
{
public:
	Player* lucas = new Player("lsheet.png", 10, 10, sf::Vector2u(4,4));

	sf::Time timer;
	World world;
	void run()
	{
		setup();
		sf::Clock clock;
		sf::Clock deltaClock;
		while(window.isOpen())
		{
			timer = clock.restart();
			deltatime += deltaClock.restart().asSeconds();

			//cout << deltatime << endl;
			controlInput();
			update();
			render();

		}
	}
private:
	//sf::Texture tlucas;
	//sf::Sprite lucas;
	float deltatime = 0;
	bool up, down, left, right;
	float chrspeed = 100.f;
	int dir; //Direction for animation
	int x = 0;

	void controlInput()
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					handleInput(event.key.code);
					dir = lucas->inputTranslate(event.key.code, true);
					deltatime = lucas->animate(dir, 0.3, deltatime);
					break;
				case sf::Event::KeyReleased:
					deltatime = 0;
					cancelInput();
					break;
			}
		}
	}

	void update()
	{

		moveCharacter(lucas->sprite, timer);

	}

	void render()
	{
		window.clear(sf::Color::White);
		window.setView(world.wview);
		world.wview.setCenter(lucas->sprite.getPosition().x, lucas->sprite.getPosition().y);
		window.draw(world.background);
		window.draw(lucas->sprite);
		window.display();

	}

	void handleInput(sf::Keyboard::Key key)
	{
		switch(key)
		{
			case sf::Keyboard::Up:
				up = true;
				break;
			case sf::Keyboard::Down:
				down = true;
				break;
			case sf::Keyboard::Left:
				left = true;
				break;
			case sf::Keyboard::Right:
				right = true;
				break;
		}
	}

	void cancelInput()
	{
		up = false;
		down = false;
		left = false;
		right = false;
	}

	void moveCharacter(sf::Sprite& target, sf::Time deltatime)
	{
		sf::Vector2f movement(0,0);
		if(up)	//Gets which key is pressed and moves referenced sprite in consequence
		{
			movement.y -= chrspeed;
		}if(down)
		{
			movement.y += chrspeed;
		}if(left)
		{
			movement.x -= chrspeed;
		}if(right)
		{
			movement.x += chrspeed;
		}
		target.move(movement * deltatime.asSeconds()); //Distance = speed * time elapsed
	}
	sf::Sprite createTexture(string pathtotexture)	//Receives path to texture to retrieve it in function
	{
		sf::Texture texture;	//Creates texture
		if(texture.loadFromFile(pathtotexture))	//Path.png
		{
			sf::Sprite sprite;
			sprite.setTexture(texture);
			return sprite;
		}

	}

	void setup()	//Function to setup everything before running loop
	{
		cancelInput();
		lucas->currentimage = sf::Vector2u(1,1);
		world.initBackground();
		window.setView(world.wview);

	}

/*	void initLucas()
	{
		tlucas.loadFromFile("Lucas.png");
		lucas.setTexture(tlucas);
		lucas.setPosition(100,100);
		lucas.setScale(sf::Vector2f(0.25,0.25));
	}
	*/
};


int main()
{
	Game game;
	game.run();


}
