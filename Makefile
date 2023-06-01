.PHONY: generateCodeObj generateResourcesObj generateEXE clean deepclean

CXX := g++
RC := RC
CFLAGS := -g -Wall -m64

CODE = $(wildcard *.cpp) $(wildcard ECS/*.cpp)
OBJ = $(wildcard *.o)
RESOURCES = $(wildcard *.rc)
LINKEDLIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer


all: generateEXE clean

generateEXE: generateResourcesObj generateCodeObj
	$(CXX) $(CFLAGS) $(OBJ) $(COMPRESOURCES) $(LINKEDLIBS) -o 'Wheatly Crab the game'

generateCodeObj: 
	$(CXX) -c $(CODE)

generateResourcesObj: $(RESOURCES)
	$(RC) $(RESOURCES)


clean:
	rm *.o *.res

deepclean:
	rm *.o *.res *.exe