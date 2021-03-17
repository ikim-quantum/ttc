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
  double theta_stab_x, theta_stab_z, theta_rot_x, theta_rot_z;

  double p1=atof(argv[1]);
  double p2=atof(argv[2]);
  double p3=atof(argv[3]);
  double p4=atof(argv[4]);

  theta_stab_x = pi * p1;
  theta_stab_z = pi * p2;
  theta_rot_x = pi * p3;
  theta_rot_z = pi * p4;

  cx_vec psi;
  psi.zeros(n);
  psi(0)=1.0;

  for (int i=0; i<n_itt; i++)
    {
      col_stab_x(theta_stab_x, psi);
      col_stab_z(theta_stab_z, psi);
      col_rot_x(theta_rot_x, psi);
      col_rot_z(theta_rot_z, psi);
      cout << i+1 << ":" << measure_z(psi) << endl;
      std::string name="./files/file_small_" + std::to_string(i) + ".txt";
      ofstream myfile;
      myfile.open (name);
      myfile << psi;
      myfile.close();
      //      cout << psi << endl;
    }

}
