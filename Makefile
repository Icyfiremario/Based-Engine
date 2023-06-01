.PHONY: generateCodeObj generateResourcesObj generateEXE clean deepclean

CXX := g++
CFLAGS := -g -Wall -m64

CODE = $(wildcard *.cpp) $(wildcard ECS/*.cpp)
OBJ = $(wildcard *.o)
RESOURCES = $(wildcard *.rc)
LINKEDLIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer


all: generateEXE clean

generateEXE: generateCodeObj generateResourcesObj
	$(CXX) $(CFLAGS) $(OBJ) $(LINKEDLIBS) -o 'Wheatly Crab the game'

generateCodeObj: 
	$(CXX) -c $(CODE)

generateResourcesObj:
	windres $(RESOURCES) -O coff -o resources.o


clean:
	rm *.o

deepclean:
	rm *.o *.exe