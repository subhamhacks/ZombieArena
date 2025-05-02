#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
	private:
		Vector2f m_Position;
		Sprite m_Sprite;
		Texture m_Texture;
		
		Vector2f m_Resolution;
		
		//for Movement
		bool m_up;
		bool m_down;
		bool m_left;
		bool m_right;
		
		float m_speed=200;//px per sec
		
	public:
		Player(); //constructor
		
		void spawn(Vector2f resolution); //spawn player in center of screen
		
		Sprite getSprite(); //Return sprite to draw
		
		//for movement
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
		void stopRight();
		void stopLeft();
		void stopUp();
		void stopDown();
		void Update(float elapsedTime, Vector2i mousePosition);
};
