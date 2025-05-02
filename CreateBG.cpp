#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;

int TITLE_SIZE = 50;
int VERTS_IN_QUAD = 4;

VertexArray createBG(IntRect arena)
{
	VertexArray BG;
	BG.setsetprimitiveType(Quads);
	
	//Grid Size : number of tiles horizontally and vertically
	
	int w = arena.width/TILE_SIZE;
	int h = arena.height/TILE_SIZE;
	
	for(int y=0; y<h; y++)
	{
		for(int x=0; x<w; x++)
		{
			//Position each vertex of quad
			BG[currentVertex + 0].position=Vector2f(x*TILE_SIZE, y*TILE_SIZE);
			BG[currentVertex + 1].position=Vector2f((x+1)*TILE_SIZE, y*TILE_SIZE);
			BG[currentVertex + 2].position=Vector2f((x+1)*TILE_SIZE, (y+1)*TILE_SIZE);
			BG[currentVertex + 3].position=Vector2f(x*TILE_SIZE, (y+1)*TILE_SIZE);
		}
	}
}
