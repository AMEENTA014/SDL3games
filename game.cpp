#include<iostream>// use the in and out files so we  can see things in terminal 
#include<SDL3/SDL.h>//inorder to use the abstraction for using the winman loops and render 
				     // also for using sdl3 we need this file
int main(int  , char ** ){
if(SDL_Init(SDL_INIT_VIDEO)!=0){std::cerr << "dl_init failed" << SDL_GetError() << "\n" ; return 1;}//initialise the window so that some systems and default configs are set underneath
SDL_Window *window = SDL_CreateWindow(//creating a window by requesting the window manager 
		"sdl3game " , //title of the game and this structure is used for managing the windows
		800, 600, 
	       0	//this flag says the window can be resizable 
		
		); 
SDL_Renderer * renderer = SDL_CreateRenderer(window,nullptr); 
bool running = true;
float x = 0.0f; 
while(running){
SDL_Event event; 
   while(SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
	  running =  false; 
	}
 
     }
   x+=2.0f; 
   if(x>800)x=0; 
   SDL_SetRenderDrawColor(renderer,0,0,0,255); 
   SDL_RenderClear(renderer); 
   SDL_SetRenderDrawColor(renderer,255,0,0,255);
   SDL_FRect rect = {x, 200, 50 , 50 }; 
   SDL_RenderFillRect(renderer, &rect); 
   SDL_RenderPresent(renderer);
   SDL_Delay(16);

    }
	//loop and in the loop clear screen with color 
	//draw the square in some position 
	//change the var for different position 
	//render it 
	//loop again
SDL_DestroyRenderer(renderer); 
SDL_DestroyWindow(window); 
SDL_Quit(); 
return 0 ; 
}
