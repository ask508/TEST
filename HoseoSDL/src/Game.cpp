#define WIDTH (600)
#define HEIGHT (400)

#include "Game.h"

#include <random>

std::random_device rd;
std::mt19937_64 rng(rd());

std::uniform_int_distribution<__int64> dist1(0, 600);
std::uniform_int_distribution<__int64> dist2(0, 400);
std::uniform_int_distribution<__int64> dist3(8, 32);


Game* Game::s_pInstance = 0;

bool Game::setup()
{
  bool result;

  result = init("Nature of Code", 0, 0, WIDTH, HEIGHT, false);

  _player = new Player(10,10);
  for (int i = 0; i < 5; i++)
  {
      _obs[i] = new Object(dist1(rng), dist2(rng), dist3(rng));
  }

  _walker = new Walker(WIDTH / 2, HEIGHT / 2, _player, _obs);
 
  return result;
}

void Game::update()
{
  _walker->update();
  _player->update();

}
      
void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    for (int i = 0; i < 5; i++)
        _obs[i]->draw(m_pRenderer);

    _walker->draw(m_pRenderer);
    _player->draw(m_pRenderer);

  
  
  
  SDL_RenderPresent(m_pRenderer); 



}

void Game::clean() 
{
  delete _walker;

  for (int i = 0; i < 5; i++)
      delete  _obs[i];

  delete  _player;

  TheInputHandler::Instance()->clean();
  
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);

  m_pWindow = NULL;
  m_pRenderer = NULL;

  SDL_Quit();
}

//==================================================

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) 
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
  {
    return false;
  }

  m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_OPENGL);
  
  if (m_pWindow != NULL ) 
  {
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255); 
    SDL_RenderClear(m_pRenderer);
  } 
  else 
  {
    return false; // ?ˆë„???ì„¤ ?¤íŒ¨ l
  }
  
  m_bRunning = true;
  
  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

  return true;
}

bool Game::running()
{ 
  return m_bRunning; 
}

void Game::handleEvents() 
{
  TheInputHandler::Instance()->update();
}