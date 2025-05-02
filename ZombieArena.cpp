#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

int main()
{
	// Get screen resolution
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	
	// Create a fullscreen window
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie Arena");

	// Create a view to follow the player
	View mainView(FloatRect(0, 0, resolution.x, resolution.y));

	// Player object
	Player player;
	player.spawn(resolution);
	Sprite playerSprite = player.getSprite();

	Clock clock;

	// Game loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}

		// Handle player movement
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player.moveUp();
		}
		else
		{
			player.stopUp();
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			player.moveLeft();
		}
		else
		{
			player.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player.moveDown();
		}
		else
		{
			player.stopDown();
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			player.moveRight();
		}
		else
		{
			player.stopRight();
		}

		// Calculate the delta time
		Time dt = clock.restart();
		float dtSec=dt.asSeconds();
		// Mouse position pass
		Vector2i mousePosition = Mouse::getPosition(window);

		// Update player movement and rotation
		player.Update(dtSec, mousePosition);

		// Update the view to follow the player
		mainView.setCenter(player.getSprite().getPosition());

		// Draw everything
		window.clear();
		window.setView(mainView);
		window.draw(playerSprite);
		window.display();
	}

	return 0;
}

