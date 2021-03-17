#ifndef FLOQUET_HPP_
#define FLOQUET_HPP_

#include <armadillo>
using namespace arma;

void col_stab_x(double theta, cx_dvec &psi);
void col_stab_z(double theta, cx_dvec &psi);
void col_stab_y(double theta, cx_dvec &psi);
void col_rot_x(double theta, cx_dvec &psi);
void col_rot_y(double theta, cx_dvec &psi);
void col_rot_z(double theta, cx_dvec &psi);
void col_stab_x_disordered(double* thetas, cx_dvec &psi);
void col_stab_z_disordered(double* thetas, cx_dvec &psi);
void col_stab_y_disordered(double* thetas, cx_dvec &psi);
void col_rot_x_disordered(double* thetas, cx_dvec &psi);
void col_rot_y_disordered(double* thetas, cx_dvec &psi);
void col_rot_z_disordered(double* thetas, cx_dvec &psi);
double measure_x(cx_dvec &psi);
double measure_z(cx_dvec &psi);

void col_stab_x_big(double theta, cx_dvec &psi);
void col_stab_z_big(double theta, cx_dvec &psi);
void col_stab_y_big(double theta, cx_dvec &psi);
void col_rot_x_big(double theta, cx_dvec &psi);
void col_rot_y_big(double theta, cx_dvec &psi);
void col_rot_z_big(double theta, cx_dvec &psi);
void col_stab_x_big_disordered(double* thetas, cx_dvec &psi);
void col_stab_z_big_disordered(double* thetas, cx_dvec &psi);
void col_stab_y_big_disordered(double* thetas, cx_dvec &psi);
void col_rot_x_big_disordered(double* thetas, cx_dvec &psi);
void col_rot_y_big_disordered(double* thetas, cx_dvec &psi);
void col_rot_z_big_disordered(double* thetas, cx_dvec &psi);
double measure_x_big(cx_dvec &psi);
double measure_z_big(cx_dvec &psi);

#endif // FLOQUET_HPP_
