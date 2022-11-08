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
