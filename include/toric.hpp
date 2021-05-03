#ifndef TORIC_HPP_
#define TORIC_HPP_
#include <vector>
#include "stabilizer.hpp"

void print_surface(int dx, int dz, int bitstring);


// "nu" means non-uniform, i.e., (possibly) different values of x- and z-distance. 
int coordinate2num(int x, int y, int dx, int dz);
int num2x(int n, int dx, int dz);
int num2y(int n, int dx, int dz);

Stabilizers stab_x_bulk(int dx, int dz);
Stabilizers stab_z_bulk(int dx, int dz);
Stabilizers stab_x_bdy(int dx, int dz);
Stabilizers stab_z_bdy(int dx, int dz);

Stabilizers xchecks(int dx, int dz);
Stabilizers zchecks(int dx, int dz);

int logical_x(int dx, int dz);
int logical_z(int dx, int dz);

void measure_stab_x(Stabilizers SX, int xstring);
void measure_stab_z(Stabilizers SZ, int zstring);

int distance(Stabilizer s1, Stabilizer s2);

#endif // TORIC_HPP_
