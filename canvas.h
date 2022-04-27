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
	SDL_Renderer * Renderer = NULL;
	SDL_Rect r;

private:	
	void OnEvent 		(SDL_Event Event);
	bool Init  			();
	void Render 		();
	void CleanUp  		();
	void DrawRect		();
};

#endif 