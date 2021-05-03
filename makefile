CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11 -O2 -larmadillo

tests: test_ppr test_toric test_floquet
	RM *.o

test_ppr: pauli_product.o ./test/test_ppr.cpp
	$(CXX) -o test_ppr pauli_product.o ./test/test_ppr.cpp $(CPPFLAGS)

test_toric: toric.o stabilizer.o ./test/test_toric.cpp
	$(CXX) -o test_toric toric.o stabilizer.o ./test/test_toric.cpp $(CPPFLAGS)

test_floquet: floquet.o pauli_product.o toric.o stabilizer.o ./test/test_floquet.cpp
	$(CXX) -o test_floquet floquet.o pauli_product.o toric.o stabilizer.o ./test/test_floquet.cpp $(CPPFLAGS)

rand_state.o: ./src/rand_state.cpp pauli_product.o
	$(CXX) -c $(CPPFLAGS) ./src/rand_state.cpp pauli_product.o

pauli_product.o: ./src/pauli_product.cpp
	$(CXX) -c $(CPPFLAGS) ./src/pauli_product.cpp

floquet.o: pauli_product.o toric.o ./src/floquet.cpp
	$(CXX) -c $(CPPFLAGS) ./src/floquet.cpp

toric.o: ./src/toric.cpp stabilizer.o
	$(CXX) -c $(CPPFLAGS) ./src/toric.cpp stabilizer.o

stabilizer.o: ./src/stabilizer.cpp
	$(CXX) -c $(CPPFLAGS) ./src/stabilizer.cpp

clean:
	$(RM) *.o test_* exp_*
