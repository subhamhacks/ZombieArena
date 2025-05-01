#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
	private:
		Vector2f m_Position;
		Sprite m_Sprite;
		Texture m_Texture;
		
		Vector2f m_Resolution;
		
	public:
		Player(); //constructor
		
		void spawn(Vector2f resolution); //spawn player in center of screen
		
		Sprite getSprite(); //Return sprite to draw
			
};
