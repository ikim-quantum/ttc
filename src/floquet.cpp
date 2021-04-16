#include "../include/floquet.hpp"
#include "../include/pauli_product.hpp"
#include "../include/toric.hpp"
#include <armadillo>
#include <cmath>
#include <stdlib.h>


using namespace std;
using namespace arma;

void tc_stab_x(double theta, int dx, int dz, cx_dvec &psi)
{
  std::vector<int> xchecks_bulk = stab_x_bulk_nu(dx, dz);
  std::vector<int> xchecks_bdy = stab_x_bdy_nu(dx, dz);

  for (int v: xchecks_bulk)
    {
      apply_ppr(v, 0, theta, psi);
    }
  for (int v: xchecks_bdy)
    {
      apply_ppr(v, 0, theta, psi);
    }
}

void tc_stab_z(double theta, int dx, int dz, cx_dvec &psi)
{
  std::vector<int> zchecks_bulk = stab_z_bulk_nu(dx, dz);
  std::vector<int> zchecks_bdy = stab_z_bdy_nu(dx, dz);

  for (int v: zchecks_bulk)
    {
      apply_ppr(0, v, theta, psi);
    }
  for (int v: zchecks_bdy)
    {
      apply_ppr(0, v, theta, psi);
    }
}
