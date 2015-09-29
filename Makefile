all: main.o doc

CC=g++
CPPFLAGS=-Wall -Iinclude

#Remember $@ = target, $< = first dependency

Random.o: src/Random.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c src/Random.cpp -o obj/$@

AbstractDerivative.o: src/AbstractDerivative.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c src/AbstractDerivative.cpp -o obj/$@

Forward.o: src/Forward.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c src/Forward.cpp -o obj/$@

main.o: Random.o Forward.o AbstractDerivative.o
	mkdir -p build
	$(CC) $(CPPFLAGS) main.cpp obj/Forward.o obj/AbstractDerivative.o obj/Random.o -o build/$@

clean:
	@echo "Cleaning...";
	rm -rf obj build doc

doc: doxy.conf
	@echo "Generating documentation...";
	mkdir -p doc
	doxygen doxy.conf
	cd doc/latex/ && make