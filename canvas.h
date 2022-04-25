#ifndef _CANVAS_ 
#define _CANVAS_

#include <SDL2/SDL.h>
class Canvas {

public: 

	Canvas				();
	int Execute			();

private: 

	bool Running;
	SDL_Window * Window = NULL;
	SDL_Surface * Surface = NULL;
	SDL_Renderer * Renderer = NULL;

private:	
	void OnEvent 		(SDL_Event * Event);
	bool Init  			();
	void Render 		();
	void CleanUp  		();
	
};

#endif 