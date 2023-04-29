#ifndef Map_hpp
#define Map_hpp

#include "Game.hpp"
#include <string>

class Map
{
    public:

        Map();
        ~Map();

        static void LoadMap(std::string path, int sizeX, int sizeY);

};

#endif /* Map_hpp */