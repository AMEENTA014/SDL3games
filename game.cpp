#include<iostream>//using this lib , the functions provide abstraction to handle text input and output 
#include<SDL3/SDL.h>//this lib provides the method to create window , renderer and other display functions 

 struct Player{
  float x = 0.0f ; 
  float y = 0.0f ; 
  int speed = 5 ; 
  bool moveright = false ; 
  bool moveleft  = false ; 
  bool moveup = false ; 
  bool movedown = false ; 
}; 
struct Player player ; 
void boundary(float &a , float  &b ); 
void movePlayer(struct Player&); 
int main(int  , char ** ){
if(SDL_Init(SDL_INIT_VIDEO)==false){//init intitializes subsystems , first we need video for window creation 
  std::cerr << "this is error ofc"<<SDL_GetError() << "\n" ;//returns false means error in initialization 
  return 1 ; 
};
SDL_Window *window = SDL_CreateWindow(//creating a window by requesting the window manager 
		"pacman " , //title of the game and this structure is used for managing the windows
		800, 600, 
	       0	//this flag says the window can be resizable 
		
		); 
SDL_Renderer * renderer = SDL_CreateRenderer(window,nullptr);//inorder to draw to the window we need renderer  
bool running = true;//running should be true means currently the window is working 
player.x = 1.0f; 
player.y = 1.0f;
 //coordinates for the box to appear 
while(running){
SDL_Event event;//structure for the event , which is used to store the events from the os  
   while(SDL_PollEvent(&event)){//move the events to the event structure for processing 
        if(event.type == SDL_EVENT_QUIT){//checking the user did press the close button and the event is close event 
	  running =  false; //not exiting from the process but exit  the loop
	}
	if(event.type == SDL_EVENT_KEY_DOWN){//the type is key press event 
	   if(event.key.key == SDLK_RIGHT)player.moveright=true ; //if the keycode is right then make move right jkjj
	
	   if(event.key.key == SDLK_LEFT)player.moveleft=true ; 
	   if(event.key.key == SDLK_UP)player.moveup=true ; 
	   if(event.key.key == SDLK_DOWN)player.movedown=true ; 
	}

	if(event.type == SDL_EVENT_KEY_UP){
	   if(event.key.key == SDLK_RIGHT)player.moveright=false ; 
	
	   if(event.key.key == SDLK_LEFT)player.moveleft=false  ; 
	   if(event.key.key == SDLK_UP)player.moveup=false  ; 
	   if(event.key.key == SDLK_DOWN)player.movedown=false  ; 
     }
   }
   movePlayer(player);
   boundary(player.x, player.y); 
   SDL_SetRenderDrawColor(renderer,0,0,0,255); //setting the color and clearing the back buffer 
   SDL_RenderClear(renderer); 
   SDL_SetRenderDrawColor(renderer,255,0,0,255);//set color again and create a rectangle structure 
   SDL_FRect rect = {player.x, player.y, 50 , 50 }; 
   SDL_RenderFillRect(renderer, &rect);//draw the rectangle using the renderer 
   SDL_RenderPresent(renderer);
   
   SDL_Delay(16);

    }
SDL_DestroyRenderer(renderer);//after that destory the renderer and th window  then quit the initialization 
SDL_DestroyWindow(window); 
SDL_Quit(); 
return 0 ; 

}
void movePlayer(struct Player &player){
 if(player.moveright)player.x+=player.speed;  
 if(player.moveleft)player.x-=player.speed;  
 if(player.moveup)player.y-=player.speed;  
 if(player.movedown)player.y+=player.speed;  
}
void boundary(float &x , float &y ){


   if(x<0)x=0 ; 
   if(x>750)x=750; 
   if(y>550)y=550; 
   if(y<0)y=0 ; 
}
