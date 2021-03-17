#include "../include/floquet.hpp"
#include "../include/pauli_product.hpp"
#include <armadillo>
#include <cmath>
#include <stdlib.h>


using namespace std;
using namespace arma;

/* Stabilizers for color code: 7 qubits, Xs and Zs
1. 0134
2. 1245
3. 3456
 */

/* Logicals: 7 qubits
1. 012
2. 036
3. 256
4. 045
5. 146
6. 234
 */


void col_stab_x(double theta, cx_dvec &psi)
{
  int s0, s1, s2;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<4) | (1<<5);
  s2 = (1<<3) | (1<<4) | (1<<5) | (1<<6);

  apply_ppr(s0, 0, theta, psi);
  apply_ppr(s1, 0, theta, psi);
  apply_ppr(s2, 0, theta, psi);
}

void col_stab_z(double theta, cx_dvec &psi)
{
  int s0, s1, s2;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<4) | (1<<5);
  s2 = (1<<3) | (1<<4) | (1<<5) | (1<<6);

  apply_ppr(0, s0, theta, psi);
  apply_ppr(0, s1, theta, psi);
  apply_ppr(0, s2, theta, psi);
}

void col_stab_y(double theta, cx_dvec &psi)
{
  int s0, s1, s2;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<4) | (1<<5);
  s2 = (1<<3) | (1<<4) | (1<<5) | (1<<6);

  apply_ppr(s0, s0, theta, psi);
  apply_ppr(s1, s1, theta, psi);
  apply_ppr(s2, s2, theta, psi);
}

void col_rot_x(double theta, cx_dvec &psi)
{
  for (int i=0; i<7; i++)
    {
      apply_ppr((1<<i), 0, theta, psi);
    }
}

void col_rot_y(double theta, cx_dvec &psi)
{
  for (int i=0; i<7; i++)
    {
      apply_ppr((1<<i), (1<<i), theta, psi);
    }
}

void col_rot_z(double theta, cx_dvec &psi)
{
  for (int i=0; i<7; i++)
    {
      apply_ppr(0, (1<<i), theta, psi);
    }
}

void col_stab_x_disordered(double* thetas, cx_dvec &psi)
{
  int s0, s1, s2;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<4) | (1<<5);
  s2 = (1<<3) | (1<<4) | (1<<5) | (1<<6);

  apply_ppr(s0, 0, thetas[0], psi);
  apply_ppr(s1, 0, thetas[1], psi);
  apply_ppr(s2, 0, thetas[2], psi);
}

void col_stab_z_disordered(double* thetas, cx_dvec &psi)
{
  int s0, s1, s2;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<4) | (1<<5);
  s2 = (1<<3) | (1<<4) | (1<<5) | (1<<6);

  apply_ppr(0, s0, thetas[0], psi);
  apply_ppr(0, s1, thetas[1], psi);
  apply_ppr(0, s2, thetas[2], psi);
}

void col_stab_y_disordered(double* thetas, cx_dvec &psi)
{
  int s0, s1, s2;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<4) | (1<<5);
  s2 = (1<<3) | (1<<4) | (1<<5) | (1<<6);

  apply_ppr(s0, s0, thetas[0], psi);
  apply_ppr(s1, s1, thetas[1], psi);
  apply_ppr(s2, s2, thetas[2], psi);
}

void col_rot_x_disordered(double* thetas, cx_dvec &psi)
{
  for (int i=0; i<7; i++)
    {
      apply_ppr((1<<i), 0, thetas[i], psi);
    }
}

void col_rot_y_disordered(double* thetas, cx_dvec &psi)
{
  for (int i=0; i<7; i++)
    {
      apply_ppr((1<<i), (1<<i), thetas[i], psi);
    }
}

void col_rot_z_disordered(double* thetas, cx_dvec &psi)
{
  for (int i=0; i<7; i++)
    {
      apply_ppr(0, (1<<i), thetas[i], psi);
    }
}


double measure_x(cx_dvec &psi)
{
  int x;
  x = (1<<0) | (1<<1) | (1<<2);
  return measure_pp(x, 0, psi);
  
}

double measure_z(cx_dvec &psi)
{
  int z;
  z = (1<<0) | (1<<1) | (1<<2);
  return measure_pp(0, z, psi);
}

/* Stabilizers for color code: 19 qubits, Xs and Zs
1. 0,1,5,6
2. 1,2,6,7,10,11
3. 2,3,7,8
4. 3,4,8,12
5. 5,6,9,10
6. 9,10,11,13,15,16
7. 7,8,11,12,13,14
8. 13,14,16,17
9. 15,16,17,18
 */


void col_stab_x_big(double theta, cx_dvec &psi)
{
  int s0, s1, s2, s3, s4, s5, s6, s7, s8;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<6) | (1<<7) | (1<<10) | (1<<11);
  s2 = (1<<2) | (1<<3) | (1<<7) | (1<<8);
  s3 = (1<<3) | (1<<4) | (1<<8) | (1<<12);
  s4 = (1<<5) | (1<<6) | (1<<9) | (1<<10);
  s5 = (1<<9) | (1<<10) | (1<<11) | (1<<13) | (1<<15) | (1<<16);
  s6 = (1<<7) | (1<<8) | (1<<11) | (1<<12) | (1<<13) | (1<<14);
  s7 = (1<<13) | (1<<14) | (1<<16) | (1<<17);
  s8 = (1<<15) | (1<<16) | (1<<17) | (1<<18);

  apply_ppr(s0, 0, theta, psi);
  apply_ppr(s1, 0, theta, psi);
  apply_ppr(s2, 0, theta, psi);
  apply_ppr(s3, 0, theta, psi);
  apply_ppr(s4, 0, theta, psi);
  apply_ppr(s5, 0, theta, psi);
  apply_ppr(s6, 0, theta, psi);
  apply_ppr(s7, 0, theta, psi);
  apply_ppr(s8, 0, theta, psi);
}

void col_stab_z_big(double theta, cx_dvec &psi)
{
  int s0, s1, s2, s3, s4, s5, s6, s7, s8;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<6) | (1<<7) | (1<<10) | (1<<11);
  s2 = (1<<2) | (1<<3) | (1<<7) | (1<<8);
  s3 = (1<<3) | (1<<4) | (1<<8) | (1<<12);
  s4 = (1<<5) | (1<<6) | (1<<9) | (1<<10);
  s5 = (1<<9) | (1<<10) | (1<<11) | (1<<13) | (1<<15) | (1<<16);
  s6 = (1<<7) | (1<<8) | (1<<11) | (1<<12) | (1<<13) | (1<<14);
  s7 = (1<<13) | (1<<14) | (1<<16) | (1<<17);
  s8 = (1<<15) | (1<<16) | (1<<17) | (1<<18);

  apply_ppr(0, s0, theta, psi);
  apply_ppr(0, s1, theta, psi);
  apply_ppr(0, s2, theta, psi);
  apply_ppr(0, s3, theta, psi);
  apply_ppr(0, s4, theta, psi);
  apply_ppr(0, s5, theta, psi);
  apply_ppr(0, s6, theta, psi);
  apply_ppr(0, s7, theta, psi);
  apply_ppr(0, s8, theta, psi);
}

void col_stab_y_big(double theta, cx_dvec &psi)
{
  
  int s0, s1, s2, s3, s4, s5, s6, s7, s8;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<6) | (1<<7) | (1<<10) | (1<<11);
  s2 = (1<<2) | (1<<3) | (1<<7) | (1<<8);
  s3 = (1<<3) | (1<<4) | (1<<8) | (1<<12);
  s4 = (1<<5) | (1<<6) | (1<<9) | (1<<10);
  s5 = (1<<9) | (1<<10) | (1<<11) | (1<<13) | (1<<15) | (1<<16);
  s6 = (1<<7) | (1<<8) | (1<<11) | (1<<12) | (1<<13) | (1<<14);
  s7 = (1<<13) | (1<<14) | (1<<16) | (1<<17);
  s8 = (1<<15) | (1<<16) | (1<<17) | (1<<18);

  apply_ppr(s0, s0, theta, psi);
  apply_ppr(s1, s1, theta, psi);
  apply_ppr(s2, s2, theta, psi);
  apply_ppr(s3, s3, theta, psi);
  apply_ppr(s4, s4, theta, psi);
  apply_ppr(s5, s5, theta, psi);
  apply_ppr(s6, s6, theta, psi);
  apply_ppr(s7, s7, theta, psi);
  apply_ppr(s8, s8, theta, psi);
}

void col_rot_x_big(double theta, cx_dvec &psi)
{
  for (int i=0; i<19; i++)
    {
      apply_ppr((1<<i), 0, theta, psi);
    }
}

void col_rot_y_big(double theta, cx_dvec &psi)
{
  for (int i=0; i<19; i++)
    {
      apply_ppr((1<<i), (1<<i), theta, psi);
    }
}

void col_rot_z_big(double theta, cx_dvec &psi)
{
  for (int i=0; i<19; i++)
    {
      apply_ppr(0, (1<<i), theta, psi);
    }
}

void col_stab_x_big_disordered(double* thetas, cx_dvec &psi)
{
  int s0, s1, s2, s3, s4, s5, s6, s7, s8;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<6) | (1<<7) | (1<<10) | (1<<11);
  s2 = (1<<2) | (1<<3) | (1<<7) | (1<<8);
  s3 = (1<<3) | (1<<4) | (1<<8) | (1<<12);
  s4 = (1<<5) | (1<<6) | (1<<9) | (1<<10);
  s5 = (1<<9) | (1<<10) | (1<<11) | (1<<13) | (1<<15) | (1<<16);
  s6 = (1<<7) | (1<<8) | (1<<11) | (1<<12) | (1<<13) | (1<<14);
  s7 = (1<<13) | (1<<14) | (1<<16) | (1<<17);
  s8 = (1<<15) | (1<<16) | (1<<17) | (1<<18);

  apply_ppr(s0, 0, thetas[0], psi);
  apply_ppr(s1, 0, thetas[1], psi);
  apply_ppr(s2, 0, thetas[2], psi);
  apply_ppr(s3, 0, thetas[3], psi);
  apply_ppr(s4, 0, thetas[4], psi);
  apply_ppr(s5, 0, thetas[5], psi);
  apply_ppr(s6, 0, thetas[6], psi);
  apply_ppr(s7, 0, thetas[7], psi);
  apply_ppr(s8, 0, thetas[8], psi);
}

void col_stab_z_big_disordered(double* thetas, cx_dvec &psi)
{
  int s0, s1, s2, s3, s4, s5, s6, s7, s8;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<6) | (1<<7) | (1<<10) | (1<<11);
  s2 = (1<<2) | (1<<3) | (1<<7) | (1<<8);
  s3 = (1<<3) | (1<<4) | (1<<8) | (1<<12);
  s4 = (1<<5) | (1<<6) | (1<<9) | (1<<10);
  s5 = (1<<9) | (1<<10) | (1<<11) | (1<<13) | (1<<15) | (1<<16);
  s6 = (1<<7) | (1<<8) | (1<<11) | (1<<12) | (1<<13) | (1<<14);
  s7 = (1<<13) | (1<<14) | (1<<16) | (1<<17);
  s8 = (1<<15) | (1<<16) | (1<<17) | (1<<18);

  apply_ppr(0, s0, thetas[0], psi);
  apply_ppr(0, s1, thetas[1], psi);
  apply_ppr(0, s2, thetas[2], psi);
  apply_ppr(0, s3, thetas[3], psi);
  apply_ppr(0, s4, thetas[4], psi);
  apply_ppr(0, s5, thetas[5], psi);
  apply_ppr(0, s6, thetas[6], psi);
  apply_ppr(0, s7, thetas[7], psi);
  apply_ppr(0, s8, thetas[8], psi);
}

void col_stab_y_big_disordered(double* thetas, cx_dvec &psi)
{
  
  int s0, s1, s2, s3, s4, s5, s6, s7, s8;
  s0 = (1<<0) | (1<<1) | (1<<5) | (1<<6);
  s1 = (1<<1) | (1<<2) | (1<<6) | (1<<7) | (1<<10) | (1<<11);
  s2 = (1<<2) | (1<<3) | (1<<7) | (1<<8);
  s3 = (1<<3) | (1<<4) | (1<<8) | (1<<12);
  s4 = (1<<5) | (1<<6) | (1<<9) | (1<<10);
  s5 = (1<<9) | (1<<10) | (1<<11) | (1<<13) | (1<<15) | (1<<16);
  s6 = (1<<7) | (1<<8) | (1<<11) | (1<<12) | (1<<13) | (1<<14);
  s7 = (1<<13) | (1<<14) | (1<<16) | (1<<17);
  s8 = (1<<15) | (1<<16) | (1<<17) | (1<<18);

  apply_ppr(s0, s0, thetas[0], psi);
  apply_ppr(s1, s1, thetas[1], psi);
  apply_ppr(s2, s2, thetas[2], psi);
  apply_ppr(s3, s3, thetas[3], psi);
  apply_ppr(s4, s4, thetas[4], psi);
  apply_ppr(s5, s5, thetas[5], psi);
  apply_ppr(s6, s6, thetas[6], psi);
  apply_ppr(s7, s7, thetas[7], psi);
  apply_ppr(s8, s8, thetas[8], psi);
}

void col_rot_x_big_disordered(double* thetas, cx_dvec &psi)
{
  for (int i=0; i<19; i++)
    {
      apply_ppr((1<<i), 0, thetas[i], psi);
    }
}

void col_rot_y_big_disordered(double* thetas, cx_dvec &psi)
{
  for (int i=0; i<19; i++)
    {
      apply_ppr((1<<i), (1<<i), thetas[i], psi);
    }
}

void col_rot_z_big_disordered(double* thetas, cx_dvec &psi)
{
  for (int i=0; i<19; i++)
    {
      apply_ppr(0, (1<<i), thetas[i], psi);
    }
}

double measure_x_big(cx_dvec &psi)
{
  int x;
  x = (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4);
  return measure_pp(x, 0, psi);
  
}

double measure_z_big(cx_dvec &psi)
{
  int z;
  z = (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4);
  return measure_pp(0, z, psi);
}
