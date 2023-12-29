#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cpp_ray_tracer/CApp.h>

CApp::CApp() = default;

bool CApp::OnInit()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) { return false; }

  constexpr int windowWidth = 1280;
  constexpr int windowHeight = 720;
  pWindow = SDL_CreateWindow(
    "Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

  if (pWindow == nullptr) { return false; }

  pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

  return true;
}

int CApp::OnExecute()
{
  SDL_Event event;

  if (!OnInit()) { return -1; }

  while (isRunning) {
    while (SDL_PollEvent(&event) != 0) { OnEvent(&event); }

    OnLoop();
    OnRender();
  }

  return 0;
}

void CApp::OnEvent(SDL_Event *event)
{
  if (event->type == SDL_QUIT) { isRunning = false; }
}

void CApp::OnLoop() {}

void CApp::OnRender()
{
  // Set the background color to white.
  SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
  SDL_RenderClear(pRenderer);

  SDL_RenderPresent(pRenderer);
}

void CApp::OnExit()
{
  SDL_DestroyRenderer(pRenderer);

  SDL_DestroyWindow(pWindow);
  pWindow = nullptr;

  SDL_Quit();
}
