.PHONY: clean realclean rebuild objbuild

TARGET = based-engine

CXX = g++
CXXFLAGS = -g -m64 -Wall -Wpedantic
LKFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

SRC := $(wildcard *.cpp) $(wildcard ECS/*.cpp)
HDR := $(wildcard *.hpp) $(wildcard ECS/*.hpp)
OBJ := $(SRC:.cpp=.o)
RC := $(wildcard *.rc)
RES := $(RC:.rc=.res)

$(TARGET): $(OBJ) $(RES)
	$(CXX) $(CXXFLAGS) $^ $(LKFLAGS) -o $@

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< $(LKFLAGS) -o $@

%.res: $(RC)
	@windres $^ -O coff -o $@

clean:
	@rm -f $(OBJ)
	@echo Removed obj files
	@rm -f $(RC)
	@echo Removed resource files

realclean: clean
	@rm -f $(TARGET).exe
	@echo Removed binary

rebuild:
	$(CXX) $(CXXFLAGS) $(OBJ) $(RES) $(LKFLAGS) -o $(TARGET)

objbuild: $(OBJ)