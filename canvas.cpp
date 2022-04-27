#include "canvas.h"

Canvas::Canvas(){

}

int Canvas::Execute(){

	if(!Init()) return 0;
	Running = true;

	SDL_Event Event;

	while(Running){
		
		while(SDL_PollEvent(&Event) != 0){
			OnEvent(Event);
		}

		Render();
		SDL_Delay(1);

	}

	CleanUp();
	return 1;
}

void Canvas::OnEvent(SDL_Event Event){

	switch(Event.type){

		case SDL_QUIT:
			Running = false;
			exit(0);
			break;

		default:
			break;
	}

}

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

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	if(Renderer == NULL){
		printf("Unable to create renderer: %s", SDL_GetError());
		return false;
	}

    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;

	return true;
}

void Canvas::Render(){

	SDL_SetRenderDrawColor( Renderer, 255, 0, 0, 255 );
	SDL_RenderClear(Renderer);
	DrawRect();
	SDL_RenderPresent(Renderer);
}

void Canvas::CleanUp(){

	if(Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

    SDL_Quit();
}

void Canvas::DrawRect(){

	SDL_SetRenderDrawColor( Renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect( Renderer, &r );
}