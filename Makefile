all: main.o doc tests
tests: test_Forward.o test_EuropeanCallOption.o test_DigitalCallOption.o

CC=g++
CPPFLAGS=-Wall -Iinclude -std=c++11
SRCDIR=src
TESTBINDIR=bin/test
#where the testing binaries will end up

#Remember $@ = target, $< = first dependency

Random.o: src/Random.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Random.cpp -o obj/$@

Forward.o: $(SRCDIR)/Forward.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Forward.cpp -o obj/$@

EuropeanCallOption.o: $(SRCDIR)/EuropeanCallOption.cpp Random.o
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/EuropeanCallOption.cpp -o obj/$@

DigitalCallOption.o: $(SRCDIR)/DigitalCallOption.cpp Random.o
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/DigitalCallOption.cpp -o obj/$@
	
Bond.o: $(SRCDIR)/Bond.cpp 
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Bond.cpp -o obj/$@

MonteCarlo.o: src/MonteCarlo.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/MonteCarlo.cpp -o obj/$@

main.o: Random.o Forward.o EuropeanCallOption.o MonteCarlo.o
	mkdir -p build
	$(CC) $(CPPFLAGS) main.cpp obj/Forward.o obj/Random.o obj/EuropeanCallOption.o obj/MonteCarlo.o -o build/$@

test_Forward.o: test/test_Forward.cpp Forward.o 
	mkdir -p $(TESTBINDIR)
	$(CC) $(CPPFLAGS) test/test_Forward.cpp -o $(TESTBINDIR)/$@ -lboost_unit_test_framework obj/Forward.o
	./$(TESTBINDIR)/$@

test_EuropeanCallOption.o: test/test_EuropeanCallOption.cpp EuropeanCallOption.o Random.o
	mkdir -p $(TESTBINDIR)
	$(CC) $(CPPFLAGS) test/test_EuropeanCallOption.cpp -o $(TESTBINDIR)/$@ -lboost_unit_test_framework obj/EuropeanCallOption.o obj/Random.o
	./$(TESTBINDIR)/$@

test_DigitalCallOption.o: test/test_DigitalCallOption.cpp DigitalCallOption.o
	mkdir -p $(TESTBINDIR)
	$(CC) $(CPPFLAGS) test/test_DigitalCallOption.cpp -o $(TESTBINDIR)/$@ -lboost_unit_test_framework obj/DigitalCallOption.o obj/Random.o
	./$(TESTBINDIR)/$@

clean:
	@echo "Cleaning...";
	rm -rf obj build doc

doc: doxy.conf
	@echo "Generating documentation...";
	mkdir -p doc
	doxygen doxy.conf
	cd doc/latex/ && make