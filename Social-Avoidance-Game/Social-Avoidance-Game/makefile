Avoidance: Avoidance.o Buildings.o Bystander.o Die.o Entity.o GameBoard.o Player.o Police.o
	g++ -std=c++11 Avoidance.o Buildings.o Bystander.o Die.o Entity.o GameBoard.o Player.o Police.o -o Avoidance

Avoidance.o: Avoidance.cpp
	g++ -std=c++11 -c Avoidance.cpp

Buildings.o: Buildings.cpp Buildings.hpp
	g++ -std=c++11 -c Buildings.cpp

Bystander.o: Bystander.cpp Bystander.hpp
	g++ -std=c++11 -c Bystander.cpp

Die.o: Die.cpp Die.hpp
	g++ -std=c++11 -c Die.cpp

Entity.o: Entity.cpp Entity.hpp
	g++ -std=c++11 -c Entity.cpp

GameBoard.o: GameBoard.cpp GameBoard.hpp
	g++ -std=c++11 -c GameBoard.cpp

Player.o: Player.cpp Player.hpp
	g++ -std=c++11 -c Player.cpp

Police.o: Police.cpp Police.hpp
	g++ -std=c++11 -c Police.cpp

clean:
	rm *.o Avoidance