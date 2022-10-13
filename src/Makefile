CC = g++ 
INCLUDES = -I../include 
INCLUDES += -I/Users/dominicaleonard/SFMLGame/src/include
LDFLAGS = $$(pkg-config --libs --cflags sfml-window sfml-system sfml-graphics)

main: Source.o Player.o Ground.o Animation.o
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@ $(INCLUDES)
Source.o: Source.cpp 
	$(CC) -c $(CFLAGS) $? $(LDFLAGS) -o $@ $(INCLUDES)
Player.o: Player.cpp 
	$(CC) -c $(CFLAGS) $? $(LDFLAGS) -o $@ $(INCLUDES)
Ground.o: Ground.cpp 
	$(CC) -c $(CFLAGS) $? $(LDFLAGS) -o $@ $(INCLUDES)
Animation.o: Animation.cpp 
	$(CC) -c $(CFLAGS) $? $(LDFLAGS) -o $@ $(INCLUDES)
.PHONY: run 
run: main
		cd ../ && ./src/main
