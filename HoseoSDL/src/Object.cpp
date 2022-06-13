#include "Object.h"


Object::Object(int x, int y,int size)
{
	_x = x;
	_y = y;
	_size = size;
	pos = new Vector2D(x, y);

}
void Object::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	filledCircleColor(renderer, _x, _y, _size, 0xFFFF0000);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
void Object::update()
{
}