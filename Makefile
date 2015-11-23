all: main.o doc tests
tests: test_Forward.o test_EuropeanCallOption.o test_DigitalCallOption.o test_MonteCarlo.o test_PutCallParity.o test_MersenneTwisterRNG.o test_BlackScholesFormulas.o

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

EuropeanPutOption.o: $(SRCDIR)/EuropeanPutOption.cpp Random.o
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/EuropeanPutOption.cpp -o obj/$@

DigitalCallOption.o: $(SRCDIR)/DigitalCallOption.cpp Random.o
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/DigitalCallOption.cpp -o obj/$@

DigitalPutOption.o: $(SRCDIR)/DigitalPutOption.cpp Random.o
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/DigitalPutOption.cpp -o obj/$@

Bond.o: $(SRCDIR)/Bond.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Bond.cpp -o obj/$@

BlackScholesFormulas.o: $(SRCDIR)/BlackScholesFormulas.cpp EuropeanCallOption.o EuropeanPutOption.o DigitalCallOption.o DigitalPutOption.o Bond.o Random.o
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/BlackScholesFormulas.cpp -o obj/$@

MersenneTwisterRNG.o: $(SRCDIR)/MersenneTwisterRNG.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/MersenneTwisterRNG.cpp -o obj/$@

MonteCarlo.o: $(SRCDIR)/MonteCarlo.cpp
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

test_BlackScholesFormulas.o: test/test_BlackScholesFormulas.cpp BlackScholesFormulas.o Random.o EuropeanCallOption.o EuropeanPutOption.o DigitalCallOption.o DigitalPutOption.o Bond.o
	mkdir -p $(TESTBINDIR)
	$(CC) $(CPPFLAGS) test/test_BlackScholesFormulas.cpp -o $(TESTBINDIR)/$@ -lboost_unit_test_framework obj/BlackScholesFormulas.o obj/Random.o obj/EuropeanCallOption.o obj/EuropeanPutOption.o obj/DigitalCallOption.o obj/DigitalPutOption.o obj/Bond.o
	./$(TESTBINDIR)/$@

test_MonteCarlo.o: test/test_MonteCarlo.cpp MonteCarlo.o Random.o EuropeanCallOption.o EuropeanPutOption.o DigitalCallOption.o DigitalPutOption.o Bond.o MersenneTwisterRNG.o BlackScholesFormulas.o
	mkdir -p $(TESTBINDIR)
	$(CC) $(CPPFLAGS) test/test_MonteCarlo.cpp -o $(TESTBINDIR)/$@ -lboost_unit_test_framework obj/MonteCarlo.o obj/Random.o obj/EuropeanCallOption.o obj/EuropeanPutOption.o obj/DigitalCallOption.o obj/DigitalPutOption.o obj/Bond.o obj/MersenneTwisterRNG.o obj/BlackScholesFormulas.o
	./$(TESTBINDIR)/$@

test_PutCallParity.o:  test/test_PutCallParity.cpp obj/BlackScholesFormulas.o  EuropeanCallOption.o EuropeanPutOption.o DigitalCallOption.o DigitalPutOption.o Forward.o Bond.o MersenneTwisterRNG.o BlackScholesFormulas.o
	mkdir -p $(TESTBINDIR)
	$(CC) $(CPPFLAGS) test/test_PutCallParity.cpp -o $(TESTBINDIR)/$@ -lboost_unit_test_framework obj/BlackScholesFormulas.o obj/EuropeanCallOption.o obj/EuropeanPutOption.o obj/DigitalCallOption.o obj/DigitalPutOption.o obj/Bond.o obj/Random.o obj/Forward.o
	./$(TESTBINDIR)/$@

test_MersenneTwisterRNG.o:  test/test_MersenneTwisterRNG.cpp MersenneTwisterRNG.o Random.o
	mkdir -p $(TESTBINDIR)
	$(CC) $(CPPFLAGS) test/test_MersenneTwisterRNG.cpp -o $(TESTBINDIR)/$@ -lboost_unit_test_framework obj/MersenneTwisterRNG.o obj/Random.o
	./$(TESTBINDIR)/$@

clean:
	@echo "Cleaning...";
	rm -rf obj build doc

doc: doxy.conf
	@echo "Generating documentation...";
	mkdir -p doc
	doxygen doxy.conf
	cd doc/latex/ && make