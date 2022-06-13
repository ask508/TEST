#include "Player.h"


Player::Player(int x, int y)
{
	_x = x;
	_y = y;
	pos = new Vector2D(x, y);
	vel = new Vector2D(0, 0);
	acc = new Vector2D(0, 0);

}
void Player::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	filledCircleColor(renderer, _x, _y, 16, 0xFFFFFFFF);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
void Player::update()
{
	Edge();
	Move();

}
void Player::ApplyFoace(Vector2D foace)
{
	*acc += foace;
}
void Player::Move()
{
	*vel += *acc;
	vel->limit(maxVel);
	*pos += *vel;
	_x = pos->getX();
	_y = pos->getY();
}
void Player::Edge()
{
	if (_x > 600)
		*pos = Vector2D(0, _y);
	else if (_x < 0)
		*pos = Vector2D(600, _y);

	if (_y > 400)
		*pos = Vector2D(_x, 0);
	else if (_y < 0)
		*pos = Vector2D(_x, 400);

}