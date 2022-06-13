#pragma once
#include "main.h"
#include "Vector2D.h"

class Vector2D;

class Object
{
	int _x, _y;
public:
	Object(int x, int y,int size);
	void draw(SDL_Renderer* renderer);
	void update();
	Vector2D* pos;
	int _size;

};