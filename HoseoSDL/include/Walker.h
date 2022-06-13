#pragma once

#include "main.h"
#include "Vector2D.h"

#include "Object.h"
#include "Player.h"

class Vector2D;
class Object;
class Player;


class Walker 
{
  int _x, _y;
  float maxVel=10.0f;
public:

	Player* _p;
	Object* _obs[5];
  Walker(int x, int y,Player* p, Object* obs[5]);
  void draw(SDL_Renderer* renderer);
  void update();
  Vector2D* pos; Vector2D* vel; Vector2D* acc;

  void Arrive(Vector2D point);
  void Seek();
  void ApplyFoace(Vector2D foace);

  void Move();
  void Edge();

  void Hide();


};