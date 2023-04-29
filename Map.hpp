#ifndef Map_hpp
#define Map_hpp

#include "Game.hpp"
#include <string>

class Map
{
    public:

        Map(const char* mfp, int ms, int ts);
        ~Map();
        void AddTile(int srcX, int srcY, int xpos, int ypos);
        void LoadMap(std::string path, int sizeX, int sizeY);
    private:
        const char* mapfilePath;
        int mapScale;
        int tileSize;
        int scaledSize;

};

#endif /* Map_hpp */