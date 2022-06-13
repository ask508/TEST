#include "Object.h"


Object::Object(int x, int y,int size)
{
	_x = x;
	_y = y;
	size = size;
	*pos = Vector2D(x, y);

}
void Object::draw(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, _x, _y, size, 0xFFFFFFFF);
}
void Object::update()
{
}