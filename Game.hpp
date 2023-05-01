#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>


class AssetManager;
class ColliderComponent;

class Game
{
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        bool running() {return isRunning;}
        void render();
        void clean();
        

        static SDL_Renderer *renderer;
        static SDL_Event event;
        static bool isRunning;
        static SDL_Rect camera;
        static AssetManager* assets;
        enum groupLabels : std::size_t
        {
            groupMap,
            groupPlayers,
            groupColliders,
            groupProjectiles,
            groupSFX,
        };
        
    private:
        int cnt = 0;
        SDL_Window *window;

};


#endif /* Game_hpp */