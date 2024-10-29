all: projet #tests

# fichier executable
#tests: test.o coord.o grille.o
#	g++ -std=c++11 -Wall -o tests test.o coord.o grille.o

projet: coord.o grille.o termite.o population.o projet.o
	g++ -std=c++11 -Wall -o projet coord.o grille.o termite.o projet.o population.o

# fichiers objets
projet.o: projet.cpp termite.hpp grille.hpp coord.hpp
	g++ -std=c++11 -Wall -c projet.cpp

test.o: test.cpp termite.hpp grille.hpp coord.hpp 
	g++ -std=c++11 -Wall -c test.cpp

population.o: population.cpp population.hpp termite.hpp grille.hpp coord.hpp
	g++ -std=c++11 -Wall -c population.cpp

termite.o: termite.cpp termite.hpp grille.hpp coord.hpp
	g++ -std=c++11 -Wall -c termite.cpp

grille.o: grille.cpp grille.hpp coord.hpp 
	g++ -std=c++11 -Wall -c grille.cpp

coord.o: coord.cpp coord.hpp
	g++ -std=c++11 -Wall -c coord.cpp


clean:
	rm -f *.o projet*

