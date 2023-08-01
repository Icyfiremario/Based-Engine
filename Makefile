.PHONY: clean realclean rebuild

TARGET = based-engine

CXX = g++
CXXFLAGS = -g -m64
LKFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

SRC := $(wildcard *.cpp) $(wildcard ECS/*.cpp)
HDR := $(wildcard *.hpp) $(wildcard ECS/*.hpp)
OBJ := $(SRC:.cpp=.o)
RES = $(wildcard *.res)

$(TARGET): $(OBJ) $(RES)
	$(CXX) $(CXXFLAGS) $^ $(LKFLAGS) -o $@

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< $(LKFLAGS) -o $@

%.res: %.rc
	@rc /r $^

clean:
	@del %.o
	@echo Removed obj files

realclean: clean
	@del $(TARGET).exe
	@echo Removed binary

rebuild:
	$(CXX) $(CXXFLAGS) $(OBJ) $(RES) $(LKFLAGS) -o $(TARGET)