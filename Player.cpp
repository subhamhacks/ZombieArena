#include "Player.h"
using namespace sf;

Player::Player()
{
	//Load texture
	m_Texture.loadFromFile("graphics/player.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(25,25);
}
	
void Player::spawn(Vector2f Res)
{
	m_Position.x=Res.x/2;
	m_Position.y=Res.y/2;
	m_Sprite.setPosition(m_Position);
}
	
Sprite Player::getSprite()
{
	return m_Sprite;
}

void Player::moveRight()
{
	m_right=true;
}

void Player::moveLeft()
{
	m_left=true;
}

void Player::moveUp()
{
	m_up=true;
}

void Player::moveDown()
{
	m_down=true;
}

void Player::stopRight()
{
	m_right=false;
}

void Player::stopLeft()
{
	m_left=false;
}

void Player::stopUp()
{
	m_up=false;
}

void Player::stopDown()
{
	m_down=false;
}

void Player::Update(float ET)
{
	if(m_up)
	m_Position.y-=ET*m_speed;
	
	if(m_down)
	m_Position.y+=ET*m_speed;
	
	if(m_left)
	m_Position.x-=ET*m_speed;
	
	if(m_right)
	m_Position.x+=ET*m_speed;
	
	//apply to sprite
	m_Sprite.setPosition(m_Position);
}
