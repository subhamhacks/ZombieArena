#include <SFML/Graphics.hpp>
#include "Player.h"


using namespace sf;

int main()
{
	//get screen resolution
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	
	//create full screen window
	RenderWindow window(VideoMode(resolution.x,resolution.y),"Zombie Arena");
	
	//view to follow player:
	View mainView(FloatRect(0,0,resolution.x,resolution.y));
	
	//Player object
	Player player;
	player.spawn(resolution);
	Sprite playerSprite = player.getSprite();
	
	//gameloop
	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			if(Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
		
		if(Keyboard::isKeyPressed(Keyboard::W))
		{
			player.moveUp();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::A))
		{
			player.moveLeft();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::S))
		{
			player.moveDown();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::D))
		{
			player.moveRight();
		}
		
		window.clear();
		window.setView(mainView);
		window.draw(playerSprite);
		window.display();
	}
	
	return 0;
}
