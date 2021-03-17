// Testing PPR
#include "../include/pauli_product.hpp"
#include <armadillo>
#include <chrono>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace arma;

// Checking that apply_ppr and apply_ppr_slow yields the same result.
int main()
{
  int n_q = 11;
  int n = (1<<n_q);
  int n_itt = 20;

  double theta_lower, theta_upper;
  theta_lower = 0; theta_upper = 3.14159265358979;
  uniform_real_distribution<double> unif(theta_lower, theta_upper);
  default_random_engine re;  

  cout << "Pauli product rotation test: Correctness test" << endl;
  cout << "Number of qubits=" << n_q << endl;
 
  for (int i=0; i<n_itt; i++)
    {
      cx_vec psi1, psi2;
      psi1.randn(n);
      psi1 = normalise(psi1, 2);
      psi2 = psi1;

      double theta = unif(re);
      unsigned x = rand()%n;
      unsigned z = rand()%n;
      apply_ppr(x, z, theta, psi1);
      apply_ppr_slow(x, z, theta, psi2);
      cout << i+1 << "/" << n_itt << ":Difference = " << norm(psi1-psi2, 2) << endl;
    }

  cout << "Pauli product rotation test: Speed test" << endl;
  cx_vec psi1, psi2;
  psi1.randn(n);
  psi1 = normalise(psi1, 2);
  psi2 = psi1;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  for (int i=0; i<n_itt; i++)
    {
      double theta = unif(re);
      unsigned x = rand()%n;
      unsigned z = rand()%n;
      
      apply_ppr(x, z, theta, psi1);
    }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::cout << "PPR Time (fast) = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/n_itt << "[µs]" << std::endl;
  std::cout << "PPR Time (fast) = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()/n_itt << "[ns]" << std::endl;


  
  psi1.randn(n);
  psi1 = normalise(psi1, 2);
  psi2 = psi1;
  std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
  for (int i=0; i<n_itt; i++)
    { 
      double theta = unif(re);
      unsigned x = rand()%n;
      unsigned z = rand()%n;
      
      apply_ppr_slow(x, z, theta, psi1);
    }
  std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

  std::cout << "PPR Time (slow) = " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count()/n_itt << "[µs]" << std::endl;
  std::cout << "PPR Time (slow) = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - begin2).count()/n_itt << "[ns]" << std::endl;

}
