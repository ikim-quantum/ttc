#include "../include/floquet.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Checking that apply_ppr and apply_ppr_slow yields the same result.
int main(int argc, char *argv[])
{

  int dx=atoi(argv[1]);
  int dz=atoi(argv[2]);
  int t = atoi(argv[3]);
  double theta = atof(argv[4]);

  cx_dvec psi = initial_allzero(dx, dz);

  cout << "Starting with all-0 state." << endl;
  for (int i=0; i<t;i++)
    {
      tc_stab_x(theta, dx, dz, psi);
      tc_stab_z(theta, dx, dz, psi);
      tc_logical_x(dx, dz, psi);
      tc_logical_z(dx, dz, psi);

      double logical_x = measure_logical_x(dx, dz, psi);
      double logical_z = measure_logical_z(dx, dz, psi);

      cout << "i="<<i<<endl;
      cout << "Logical X=" << logical_x << endl;
      cout << "Logical Z=" << logical_z << endl;
    }

  cout << "Starting with all-plus state." << endl;

  for (int i=0; i<t;i++)
    {
      tc_stab_x(theta, dx, dz, psi);
      tc_stab_z(theta, dx, dz, psi);
      tc_logical_x(dx, dz, psi);
      tc_logical_z(dx, dz, psi);

      double logical_x = measure_logical_x(dx, dz, psi);
      double logical_z = measure_logical_z(dx, dz, psi);

      cout << "i="<<i<<endl;
      cout << "Logical X=" << logical_x << endl;
      cout << "Logical Z=" << logical_z << endl;
    }
}
