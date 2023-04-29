#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <map>
#include <string>
#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include "ECS/ECS.hpp"

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

    private:

        std::map<std::string, SDL_Texture*> textures;
        Manager* manager;
};

#endif /* AssetManager_hpp */