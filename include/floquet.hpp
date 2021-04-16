#ifndef FLOQUET_HPP_
#define FLOQUET_HPP_

#include <armadillo>
using namespace arma;

void tc_stab_x(double theta, int dx, int dz, cx_dvec &psi);
void tc_stab_z(double theta, int dx, int dz, cx_dvec &psi);

void tc_logical_x(double theta, int dx, int dz, cx_dvec &psi);
void tc_logical_z(double theta, int dx, int dz, cx_dvec &psi);

#endif // FLOQUET_HPP_
