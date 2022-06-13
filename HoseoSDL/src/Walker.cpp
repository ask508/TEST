#include "Walker.h"
#include <random>


Walker::Walker(int x, int y, Player* p, Object* obs[5])
{
  _x = x;
  _y = y;
  pos = new Vector2D(x, y);
  vel = new Vector2D(0,0);
  acc = new Vector2D(0,0);
  _p = p;
  for (int i = 0; i < 5; i++)
  {
	  _obs[i] = obs[i];
  }

}

void Walker::update() 
{
	Edge();
	Move();
	Hide();
	//Arrive(Vector2D(100, 300));

}

void Walker::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
 filledCircleColor(renderer, _x, _y, 16, 0xFFFFFF00); 
 SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}


void Walker::Move()
{
	*vel += *acc;
	vel->limit(maxVel);
	*pos += *vel;
	_x = pos->getX();
	_y = pos->getY();
}


void Walker::Arrive(Vector2D point)
{
	Vector2D taget = point - *pos;

	float dist = taget.length();
	if (dist>0)
	{
		float DT = 0.3f;
		float speed = dist / (0.3f * DT);
		Vector2D vel2 = taget*speed/dist;
		*vel = vel2;
		return;
	}
	*vel = Vector2D(0, 0);

}
void Walker::Seek()
{}
void Walker::ApplyFoace(Vector2D foace)
{
	*acc += foace;
}
void Walker::Edge()
{
	if (_x > 600)
		*pos = Vector2D(0,_y);
	else if (_x < 0)
		*pos = Vector2D(600, _y);
	
	if (_y > 400)
		*pos = Vector2D(_x, 0);
	else if (_y < 0)
		*pos = Vector2D(_x, 400);

}

void Walker::Hide()
{
	//player와 장애물위치를 기준으로 가장 작은 거리의 장애물을 찾고 그장애물로 이동함
	Vector2D dir(0,0);
	float min = 999999999;
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		Vector2D distnace = *_obs[i]->pos - *_p->pos;
		
		if (min > distnace.length())
		{
			min = distnace.length();
			index = i;

			dir = distnace;
			dir.normalize();

			dir= (dir * 30.0f) + *_obs[index]->pos;

		}
		
	}
	//Arrive(*_obs[index]->pos);
	Arrive(dir);


}
