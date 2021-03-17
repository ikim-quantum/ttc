#ifndef QSIM_PAULI_PRODUCT_HPP_
#define QSIM_PAULI_PRODUCT_HPP_

#include <armadillo>
using namespace arma;

void apply_pauli(int k, bool x, bool z, cx_dvec &psi);
void apply_pauli_slow(int k, bool x, bool z, cx_dvec &psi);
void apply_ppr(unsigned int x, unsigned int z, double theta, cx_dvec &psi);
void apply_ppr_slow(unsigned int x, unsigned int z, double theta, cx_dvec &psi);
double measure_pp(unsigned int x, unsigned int z, cx_dvec &psi);
double measure_pp_slow(unsigned int x, unsigned int z, cx_dvec & psi);

#endif // QSIM_PAULI_PRODUCT_HPP_
