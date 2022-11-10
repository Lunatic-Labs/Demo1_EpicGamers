CC = g++ 
INCLUDES = -I../include 
INCLUDES += -I/Users/dominicaleonard/Repo/Demo1_EpicGamers/src/include
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX := g++

all: thegame

%.o: %.cpp
	$(CXX) -c $< -o $@

%.o: %.hpp
	$(CXX) -c $< -o $@

thegame: Source.o Game.o SplashState.o MainMenuState.o GameState.o Hydrant.o StateMachine.o AssetManager.o InputManager.o GameOverState.o Player.o
	@echo "** Building the game"
	$(CXX) -o thegame Source.o Game.o SplashState.o MainMenuState.o GameState.o Hydrant.o StateMachine.o AssetManager.o InputManager.o GameOverState.o Player.o $(LIBS)
