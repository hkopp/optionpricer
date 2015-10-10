all: main.o doc tests
tests: test_Forward.o

CC=g++
CPPFLAGS=-Wall -Iinclude
SRCDIR=src
TESTBINDIR=bin/test
#where the testing binaries will end up

#Remember $@ = target, $< = first dependency

Random.o: src/Random.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Random.cpp -o obj/$@

AbstractDerivative.o: $(SRCDIR)/AbstractDerivative.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/AbstractDerivative.cpp -o obj/$@

Forward.o: src/Forward.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Forward.cpp -o obj/$@

EuropeanCallOption.o: $(SRCDIR)/EuropeanCallOption.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/EuropeanCallOption.cpp -o obj/$@

MonteCarlo.o: src/MonteCarlo.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/MonteCarlo.cpp -o obj/$@

main.o: Random.o Forward.o AbstractDerivative.o EuropeanCallOption.o MonteCarlo.o
	mkdir -p build
	$(CC) $(CPPFLAGS) main.cpp obj/Forward.o obj/AbstractDerivative.o obj/Random.o obj/EuropeanCallOption.o obj/MonteCarlo.o -o build/$@

test_Forward.o: test/test_Forward.cpp Forward.o AbstractDerivative.o
	mkdir -p $(TESTBINDIR)
	$(CC) $(CPPFLAGS) test/test_Forward.cpp -o $(TESTBINDIR)/$@ -lboost_unit_test_framework obj/Forward.o obj/AbstractDerivative.o
	./$(TESTBINDIR)/$@

clean:
	@echo "Cleaning...";
	rm -rf obj build doc

doc: doxy.conf
	@echo "Generating documentation...";
	mkdir -p doc
	doxygen doxy.conf
	cd doc/latex/ && make