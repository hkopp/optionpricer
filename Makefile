all: main.o

CC=g++
CPPFLAGS=-Wall -Iinclude

#Remember $@ = target, $< = first dependency

Random.o: src/Random.cpp
	$(CC) $(CPPFLAGS) -c src/Random.cpp -o obj/$@

AbstractDerivative.o: src/AbstractDerivative.cpp
	$(CC) $(CPPFLAGS) -c src/AbstractDerivative.cpp -o obj/$@

Forward.o: src/Forward.cpp
	$(CC) $(CPPFLAGS) -c src/Forward.cpp -o obj/$@

main.o: obj/Random.o obj/Forward.o obj/AbstractDerivative.o
	$(CC) $(CPPFLAGS) main.cpp obj/Forward.o obj/AbstractDerivative.o obj/Random.o -o obj/$@

clean:
	rm -f obj/*.o
