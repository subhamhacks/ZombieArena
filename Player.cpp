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

