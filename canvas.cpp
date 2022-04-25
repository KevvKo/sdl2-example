#include "canvas.h"

Canvas::Canvas(){

}

int Canvas::Execute(){

	if(!Init()) return 0;
	Running = true;

	return 0;
}

void Canvas::OnEvent(){}

bool Canvas::Init(){

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Unable to Init SDL : %s", SDL_GetError());
		return false;
	}

	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
		printf("Unable to Init Hintig: %s", SDL_GetError());
	}

	Window = SDL_CreateWindow(
		"SDL2-Example",
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED,
    	640, 480, 
    	SDL_WINDOW_SHOWN
	);

	if(Window == NULL){
		printf("Unable to create window: %s", SDL_GetError());
		return false;
	}

	Surface = SDL_GetWindowSurface(Window);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	if(Renderer == NULL){
		printf("Unable to create renderer %s", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawColor( Renderer, 0x00, 0x00, 0x00, 0xFF);
	return true;
}

void Canvas::Render(){}

void Canvas::CleanUp(){}