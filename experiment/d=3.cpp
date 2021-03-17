#include "../include/floquet.hpp"
#include <armadillo>
#include <chrono>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
using namespace arma;

// Checking that apply_ppr and apply_ppr_slow yields the same result.
int main(int argc, char *argv[])
{
  int n_q = 7;
  int n = (1<<n_q);
  int n_itt = 100;
  double pi = 3.14159265358979;
  double alpha_stab, sigma_stab, error_1q;
  double theta_stab_x, theta_stab_z, theta_rot_x, theta_rot_z;

  alpha_stab = atof(argv[1]);
  sigma_stab = atof(argv[2]);
  error_1q = atof(argv[3]);

  double thetas_stab_x[3], thetas_stab_z[3], thetas_rot_y[7], thetas_rot_z[7];

  for (int i=0; i<3; i++)
    {
      double lower_bound = -sigma_stab;
      double upper_bound = sigma_stab;
      std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
      std::default_random_engine re;
      double myrand = unif(re);
      thetas_stab_x[i] = (alpha_stab + myrand) * pi;
      myrand = unif(re);
      thetas_stab_z[i] = (alpha_stab + myrand) * pi;
    }

  for (int i=0; i<7; i++)
    {
      double lower_bound = -error_1q;
      double upper_bound = error_1q;
      std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
      std::default_random_engine re;
      double myrand = unif(re);
      thetas_rot_y[i] = (0.25 + myrand) * pi;
      myrand = unif(re);
      thetas_rot_z[i] = (0.25 + myrand) * pi;
    }


  cx_vec psi;
  psi.zeros(n);
  psi(0)=1.0;

  ofstream hist;
  hist.open ("./files/3t_history_small.txt");
  for (int i=0; i<n_itt; i++)
    {
      col_stab_x_disordered(thetas_stab_x, psi);
      col_stab_z_disordered(thetas_stab_z, psi);
      col_rot_z_disordered(thetas_rot_z, psi);
      col_rot_y_disordered(thetas_rot_y, psi);
      cout << i+1 << ":" << measure_z(psi) << endl;
      hist <<measure_z(psi) << endl;
      std::string name="./files/3t_small_disordered_" + std::to_string(i) + ".txt";
      ofstream myfile;
      myfile.open (name);
      myfile << psi;
      myfile.close();
      //      cout << psi << endl;
    }
  hist.close();

}
