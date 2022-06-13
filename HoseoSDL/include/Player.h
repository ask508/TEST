#pragma once
#include "main.h"
#include "Vector2D.h"

class Vector2D;

class Player
{
	int _x, _y;
public:
	float maxVel = 10.0f;
	Vector2D* pos; Vector2D* vel; Vector2D* acc;
	Player(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();
	void ApplyFoace(Vector2D foace);
	void Move();
	void Edge();
};