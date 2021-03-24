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

#endif // TORIC_HPP_
