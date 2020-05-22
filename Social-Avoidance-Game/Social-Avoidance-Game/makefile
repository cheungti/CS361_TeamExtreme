Avoidance: Avoidance.o Buildings.o Bystander.o Die.o Entity.o GameBoard.o Player.o Police.o
	g++ -std=c++0x Avoidance.o Buildings.o Bystander.o Die.o Entity.o GameBoard.o Player.o Police.o -o Avoidance

Avoidance.o: Avoidance.cpp
	g++ -std=c++0x -c Avoidance.cpp

Buildings.o: Buildings.cpp Buildings.hpp
	g++ -std=c++0x -c Buildings.cpp

Bystander.o: Bystander.cpp Bystander.hpp
	g++ -std=c++0x -c Bystander.cpp

Die.o: Die.cpp Die.hpp
	g++ -std=c++0x -c Die.cpp

Entity.o: Entity.cpp Entity.hpp
	g++ -std=c++0x -c Entity.cpp

GameBoard.o: GameBoard.cpp GameBoard.hpp
	g++ -std=c++0x -c GameBoard.cpp

Player.o: Player.cpp Player.hpp
	g++ -std=c++0x -c Player.cpp

Police.o: Police.cpp Police.hpp
	g++ -std=c++0x -c Police.cpp

clean:
	rm *.o Avoidance