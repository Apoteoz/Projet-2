main.exe : main.o bestiaire.o menu.o pokedex.o journal.o utils.o combat.o
	g++ -o main.exe main.o bestiaire.o menu.o pokedex.o journal.o utils.o combat.o
	make clean

main.o : main.cpp
	g++ -c main.cpp

pokedex.o : Pokedex/pokedex.cpp 
	g++ -c Pokedex/pokedex.cpp

menu.o : Menu/menu.cpp
	g++ -c Menu/menu.cpp

journal.o : Journal/journal.cpp
	g++ -c Journal/journal.cpp

utils.o : Utils/utils.cpp
	g++ -c Utils/utils.cpp

bestiaire.o : Bestiaire/bestiaire.cpp
	g++ -c Bestiaire/bestiaire.cpp

combat.o : Combat/combat.cpp
	g++ -c Combat/combat.cpp

clean :
	rm -f *.o