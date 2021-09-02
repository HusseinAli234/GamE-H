#include<iostream>
#include<SDL.h>

int main(int argc, char* argv[])
{
    
   



   
    SDL_Init(SDL_INIT_VIDEO);
    
    
    SDL_Window* window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Surface* image1 = SDL_LoadBMP("BMP.bmp");
    SDL_Surface* image2 = SDL_LoadBMP("bmp22.bmp");
    SDL_Surface* image = nullptr;
    SDL_Texture* tex = nullptr;
    bool isRunning = true;
    SDL_Event ev;
    
    while (isRunning)
    {
        while (SDL_PollEvent(&ev) != 0)
        {
            if (ev.type == SDL_QUIT)
                isRunning = false;
            else if (ev.type == SDL_KEYDOWN)
            {
                switch (ev.key.keysym.sym)
                {
                case SDLK_1:
                    image = image1;
                    SDL_Log("KEY 1 PRESS");
                    break;
                case SDLK_2:
                    image = image2;
                    SDL_Log("KEY 2 PRESS");
                    break;



                }
             

           }
            tex = SDL_CreateTextureFromSurface(rend, image);


            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, tex, NULL, NULL);
            SDL_RenderPresent(rend);
        }
        
    }
    SDL_FreeSurface(image); 

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
   
  

    return 0;





    

 
}
