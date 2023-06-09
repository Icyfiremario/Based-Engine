#ifndef MixerManager_hpp
#define MixerManager_hpp

#include "Game.hpp"
#include "AssetManager.hpp"
#include <SDL2/SDL_mixer.h>
#include <string>

class MixerManager
{
    public:

        MixerManager();
        ~MixerManager();

        void PlaySFX(std::string id);

        void PlayMusic(std::string id);

    private:
        Mix_Chunk* sfx;
        Mix_Music* music;
};

#endif /* MixerManager_hpp */