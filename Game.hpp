#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>


class ColliderComponent;

class Game
{
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() {return isRunning;}

        

        static SDL_Renderer *renderer;
        static SDL_Event event;

        static bool isRunning;

        static SDL_Rect camera;

        enum groupLabels : std::size_t
        {
            groupMap,
            groupPlayers,
            groupColliders
        };
        
    private:
        int cnt = 0;
        SDL_Window *window;

};


#endif /* Game_hpp */