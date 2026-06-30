CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

main: main.cpp welt.cpp welt.h player.cpp player.h inventar.cpp inventar.h SaveSystem.cpp SaveSystem.h
	$(CXX) main.cpp welt.cpp player.cpp inventar.cpp SaveSystem.cpp $(CXXFLAGS) -o main

clean:
	rm -f main
