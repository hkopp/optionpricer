all: main.o

CPPFLAGS=-Wall -Iinclude

Random.o: src/Random.cpp
	g++ $(CPPFLAGS) -c src/Random.cpp -o obj/$@

AbstractDerivative.o: src/AbstractDerivative.cpp
	g++ $(CPPFLAGS) -c src/AbstractDerivative.cpp -o obj/$@

Forward.o: src/Forward.cpp
	g++ $(CPPFLAGS) -c src/Forward.cpp -o obj/$@

main.o: Random.o Forward.o AbstractDerivative.o
	g++ $(CPPFLAGS) main.cpp obj/Forward.o obj/AbstractDerivative.o obj/Random.o -o obj/$@

clean:
	rm -f obj/*.o
