#ifndef TORIC_HPP_
#define TORIC_HPP_
#include <vector>

int coordinate2num(int x, int y, int d);
int num2x(int n, int d);
int num2y(int n, int d);
void print_surface(int dx, int dz, int bitstring);

std::vector<std::tuple<int, int, int>> stab_x_bulk(int d);
std::vector<std::tuple<int, int, int>> stab_z_bulk(int d);
std::vector<std::tuple<int, int, int>> stab_x_bdy(int d);
std::vector<std::tuple<int, int, int>> stab_z_bdy(int d);

int logical_x(int d);
int logical_z(int d);

// "nu" means non-uniform, i.e., (possibly) different values of x- and z-distance. 
int coordinate2num_nu(int x, int y, int dx, int dz);
int num2x_nu(int n, int dx, int dz);
int num2y_nu(int n, int dx, int dz);

std::vector<std::tuple<int, int, int>> stab_x_bulk_nu(int dx, int dz);
std::vector<std::tuple<int, int, int>> stab_z_bulk_nu(int dx, int dz);
std::vector<std::tuple<int, int, int>> stab_x_bdy_nu(int dx, int dz);
std::vector<std::tuple<int, int, int>> stab_z_bdy_nu(int dx, int dz);

int logical_x_nu(int dx, int dz);
int logical_z_nu(int dx, int dz);

std::vector<bool> measure_stab_x(int dx, int dz, int xstring);
std::vector<bool> measure_stab_z(int dx, int dz, int zstring);

#endif // TORIC_HPP_
