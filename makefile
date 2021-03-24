CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11 -O2 -larmadillo

tests: test_ppr test_color test_color_big test_color_disordered test_color_big_disordered test_toric
	RM *.o

test_ppr: pauli_product.o ./test/test_ppr.cpp
	$(CXX) -o test_ppr pauli_product.o ./test/test_ppr.cpp $(CPPFLAGS)

test_color: pauli_product.o floquet.o ./test/test_color.cpp
	$(CXX) -o test_color floquet.o pauli_product.o ./test/test_color.cpp $(CPPFLAGS)

test_color_disordered: pauli_product.o floquet.o ./test/test_color_disordered.cpp
	$(CXX) -o test_color_disordered floquet.o pauli_product.o ./test/test_color_disordered.cpp $(CPPFLAGS)

test_color_big_disordered: pauli_product.o floquet.o ./test/test_color_big_disordered.cpp
	$(CXX) -o test_color_big_disordered floquet.o pauli_product.o ./test/test_color_big_disordered.cpp $(CPPFLAGS)

test_color_big: pauli_product.o floquet.o ./test/test_color_big.cpp
	$(CXX) -o test_color_big floquet.o pauli_product.o ./test/test_color_big.cpp $(CPPFLAGS)

test_toric: toric.o ./test/test_toric.cpp
	$(CXX) -o test_toric toric.o ./test/test_toric.cpp $(CPPFLAGS)

exp_color_disordered: pauli_product.o floquet.o ./experiment/d=3.cpp
	$(CXX) -o exp_color_disordered floquet.o pauli_product.o ./experiment/d=3.cpp $(CPPFLAGS)

exp_color_big_disordered: pauli_product.o floquet.o ./experiment/d=5.cpp
	$(CXX) -o exp_color_big_disordered floquet.o pauli_product.o ./experiment/d=5.cpp $(CPPFLAGS)

rand_state.o: ./src/rand_state.cpp pauli_product.o
	$(CXX) -c $(CPPFLAGS) ./src/rand_state.cpp pauli_product.o

pauli_product.o: ./src/pauli_product.cpp
	$(CXX) -c $(CPPFLAGS) ./src/pauli_product.cpp

floquet.o: pauli_product.o ./src/floquet.cpp
	$(CXX) -c $(CPPFLAGS) ./src/floquet.cpp

toric.o: ./src/toric.cpp
	$(CXX) -c $(CPPFLAGS) ./src/toric.cpp

clean:
	$(RM) *.o test_* exp_*
