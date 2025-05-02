#include "Player.h"
#include <cmath>

using namespace sf;

Player::Player()
{
	// Load texture
	m_Texture.loadFromFile("graphics/player.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(25, 25);  // Set the sprite origin to the center
}

void Player::spawn(Vector2f Res)
{
	// Spawn the player in the center of the screen
	m_Position.x = Res.x / 2;
	m_Position.y = Res.y / 2;
	m_Resolution = Res;  // Store resolution for mouse positioning
	m_Sprite.setPosition(m_Position);
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

void Player::moveRight() { m_right = true; }
void Player::moveLeft() { m_left = true; }
void Player::moveUp() { m_up = true; }
void Player::moveDown() { m_down = true; }

void Player::stopRight() { m_right = false; }
void Player::stopLeft() { m_left = false; }
void Player::stopUp() { m_up = false; }
void Player::stopDown() { m_down = false; }

void Player::Update(float ET, Vector2i MousePos)
{
	// Move player based on flags
	if (m_up)
		m_Position.y -=m_speed*ET;  // Move up (decrease y)
	
	if (m_down)
		m_Position.y +=m_speed*ET;  // Move down (increase y)

	if (m_left)
		m_Position.x -=m_speed*ET;   // Move left (decrease x)

	if (m_right)
		m_Position.x +=m_speed*ET;  // Move right (increase x)

	// Apply the updated position to the sprite
	m_Sprite.setPosition(m_Position);

	// Calculate the angle to rotate toward the mouse
	// Get the difference between the mouse position and the player's position
	float deltaX = MousePos.x - m_Position.x;
	float deltaY = MousePos.y - m_Position.y;

	// Calculate the angle in radians, then convert it to degrees
	float angle = atan2(deltaY, deltaX) * 180.0f / 3.14159f;

	// Set the rotation of the sprite to face the mouse position
	m_Sprite.setRotation(angle);
}

