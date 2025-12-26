#include<iostream>// use the in and out files so we  can see things in terminal 
#include<SDL3/SDL.h>//inorder to use the abstraction for using the winman loops and render 
				     // also for using sdl3 we need this file
int main(){
SDL_Init(SDL_INIT_VIDEO);
SDL_WINDOW *window = SDL_CreateWindow(
		"sdl3game " , 
		800, 600 
		
		)

}
