#include<iostream>
#include<SDL3/SDL.h>
int main(){
  if(SDL_Init(SDL_INIT_VIDEO)==false) 
    {
	    std::cerr << "init subsystems are failed " << SDL_GetError() << "\n" ; 	
	    return 1; 
    }; 
SDL_Window *window  = SDL_CreateWindow(
		"pacman", 800 , 600 , 0  //this data structure is to define a window 
		);
      if(!window){
	std::cerr << "error in window creation" << SDL_GetError() << "\n" ;
	return 1 ; 
        }
SDL_Renderer * renderer = SDL_CreateRenderer(
	           window,nullptr 	//this is to interact with the framebuffer or the window 
		);
      if(!renderer){
	std::cerr << "error in render creation" << SDL_GetError() << "\n" ;
	return 1; 
	}
    bool running = true;
     while(running){
        SDL_Event event ; 
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_EVENT_QUIT)running = false ; 	
			
			}
     } 
     SDL_DestroyRenderer(renderer); 
     SDL_DestroyWindow(window); 
     SDL_Quit();
return 0 ; 
          }
