CXX = g++
RM = rm
CXXFLAGS = -I. -Wall -Wextra -std=c++14
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

PROJECT = a.out
PROJECT_HEADERS = Common.hpp System.hpp Game.hpp Position.hpp\
                  DebugRenderSystem.hpp Body.hpp PhysicsSystem.hpp\
                  PlayerController.hpp Command.hpp CommandQueue.hpp
PROJECT_SOURCES = main.cpp Game.cpp Position.cpp DebugRenderSystem.cpp Body.cpp\
                  Shape.cpp DebugDraw.cpp PhysicsSystem.cpp\
                  PlayerController.cpp Command.cpp CommandQueue.cpp
PROJECT_OBJECTS = $(subst .cpp,.o,$(PROJECT_SOURCES))

all: $(PROJECT)

$(PROJECT): $(PROJECT_OBJECTS)
	$(CXX) -o $(PROJECT) $(PROJECT_OBJECTS) $(CXXFLAGS) $(LDFLAGS)

$(PROJECT_OBJECTS): $(PROJECT_SOURCES) $(PROJECT_HEADERS)
	$(CXX) -c $(PROJECT_SOURCES) $(CXXFLAGS) $(LDFLAGS)

clean:
	$(RM) $(PROJECT_OBJECTS)
	$(RM) $(PROJECT)

.PHONY: clean all
