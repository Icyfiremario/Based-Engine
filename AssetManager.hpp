#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <map>
#include <string>
#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include "ECS/ECS.hpp"
#include <SDL2/SDL_ttf.h>

class AssetManager
{
    public:

        AssetManager(Manager* man);
        ~AssetManager();

        //GameObjects
        void CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id);
        
        //texture stuffs
        void AddTexture(std::string id, const char* path);
        SDL_Texture* GetTexture(std::string id);

        void AddFont(std::string id, std::string path, int fontSize);
        TTF_Font* GetFont(std::string id);

        void AddSfx(std::string id, const char* path);
        Mix_Chunk* GetSfx(std::string id);

    private:

        Manager* manager;
        std::map<std::string, SDL_Texture*> textures;
        std::map<std::string, TTF_Font*> fonts;
        std::map<std::string, Mix_Chunk*> sfxs;
        
};

#endif /* AssetManager_hpp */