#ifndef CAPP_H
#define CAPP_H

// #include <cpp_ray_tracer/CApp_export.h>
#include <SDL2/SDL.h>

class CApp
{
public:
  CApp();

  bool OnInit();
  int OnExecute();
  void OnEvent(SDL_Event *event);
  static void OnLoop();
  void OnRender();
  void OnExit();

private:
  bool isRunning{ true };
  SDL_Window *pWindow{ nullptr };
  SDL_Renderer *pRenderer{ nullptr };
};

#endif
