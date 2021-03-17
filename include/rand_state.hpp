#ifndef RAND_STATE_HPP_
#define RAND_STATE_HPP_

#include <armadillo>
using namespace arma;

void apply_rand_gate(unsigned int q1, unsigned int q2, cx_dvec &psi);
void apply_rand_clifford(unsigned int q1, unsigned int q2, cx_dvec &psi);
cx_dvec rand_haar(unsigned int n_q);
cx_dvec scrambled_1d(unsigned int n_q, unsigned int depth);
cx_dvec scrambled_1d_clifford(unsigned int n_q, unsigned int depth);

#endif // RAND_STATE_HPP_
