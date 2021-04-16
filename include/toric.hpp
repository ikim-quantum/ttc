#ifndef TORIC_HPP_
#define TORIC_HPP_
#include <vector>

int coordinate2num(int x, int y, int d);
int num2x(int n, int d);
int num2y(int n, int d);

std::vector<int> stab_x_bulk(int d);
std::vector<int> stab_z_bulk(int d);
std::vector<int> stab_x_bdy(int d);
std::vector<int> stab_z_bdy(int d);

// "nu" means non-uniform, i.e., (possibly) different values of x- and z-distance. 
int coordinate2num_nu(int x, int y, int dx, int dz);
int num2x_nu(int n, int dx, int dz);
int num2y_nu(int n, int dx, int dz);

std::vector<int> stab_x_bulk_nu(int dx, int dz);
std::vector<int> stab_z_bulk_nu(int dx, int dz);
std::vector<int> stab_x_bdy_nu(int dx, int dz);
std::vector<int> stab_z_bdy_nu(int dx, int dz);

#endif // TORIC_HPP_
