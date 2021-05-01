#include "../include/floquet.hpp"
#include "../include/pauli_product.hpp"
#include "../include/toric.hpp"
#include "../include/stabilizer.hpp"
#include <armadillo>
#include <cmath>
#include <stdlib.h>


using namespace std;
using namespace arma;

void tc_stab_x(double theta, int dx, int dz, cx_dvec &psi)
{
  std::vector<Stabilizer> xchecks_bulk = stab_x_bulk_nu(dx, dz);
  std::vector<Stabilizer> xchecks_bdy = stab_x_bdy_nu(dx, dz);

  for (auto s: xchecks_bulk)
    {
      apply_ppr(s.bitrep, 0, theta, psi);
    }
  for (auto s: xchecks_bdy)
    {
      apply_ppr(s.bitrep, 0, theta, psi);
    }
}

void tc_stab_z(double theta, int dx, int dz, cx_dvec &psi)
{
  std::vector<Stabilizer> zchecks_bulk = stab_z_bulk_nu(dx, dz);
  std::vector<Stabilizer> zchecks_bdy = stab_z_bdy_nu(dx, dz);

  for (auto s: zchecks_bulk)
    {
      apply_ppr(0, s.bitrep, theta, psi);
    }
  for (auto s: zchecks_bdy)
    {
      apply_ppr(0, s.bitrep, theta, psi);
    }
}

void tc_logical_x(int dx, int dz, cx_dvec &psi)
{
  double theta = 1.57079632679;
  apply_ppr(logical_x_nu(dx, dz), 0, theta, psi);
}

void tc_logical_z(int dx, int dz, cx_dvec &psi)
{
  double theta = 1.57079632679;
  apply_ppr(0, logical_z_nu(dx, dz), theta, psi);
}

cx_dvec initial_allzero(int dx, int dz)
{
  cx_dvec psi;
  psi.zeros(1<<(dx*dz));
  psi(0) = 1;
  return psi;
}

cx_dvec initial_allplus(int dx, int dz)
{
  cx_dvec psi(1<<(dx*dz), fill::ones);
  psi /= norm(psi);
  return psi;
}

double measure_logical_x(int dx, int dz, cx_dvec &psi)
{
  return measure_pp(logical_x_nu(dx, dz), 0, psi);
}

double measure_logical_z(int dx, int dz, cx_dvec &psi)
{
  return measure_pp(0, logical_z_nu(dx, dz), psi);
}

void global_x(double theta, int dx, int dz, cx_dvec &psi)
{
  for (int i=0; i<dx*dz; i++)
    {
      apply_ppr(1<<i, 0, theta, psi);
    }
}

void global_z(double theta, int dx, int dz, cx_dvec &psi)
{
  for (int i=0; i<dx*dz; i++)
    {
      apply_ppr(0, 1<<i, theta, psi);
    }
}
