#include "../include/toric.hpp"
#include "../include/stabilizer.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Checking that apply_ppr and apply_ppr_slow yields the same result.
int main(int argc, char *argv[])
{

  int d=atoi(argv[1]);
  const int n = 4096;

  
  std::vector<Stabilizer> xchecks_bulk = stab_x_bulk(d);
  std::vector<Stabilizer> zchecks_bulk = stab_z_bulk(d);
  std::vector<Stabilizer> xchecks_bdy = stab_x_bdy(d);
  std::vector<Stabilizer> zchecks_bdy = stab_z_bdy(d);
  
  cout << "X-checks (bulk) " << endl;
  for (auto v: xchecks_bulk)
    {
      cout << "(x,y)=(" << v.x << ","<< v.y << ")"<< endl;
      int i = v.bitrep;
      print_surface(d, d, i);
      cout << endl;
    }

  cout << "Z-checks (bulk) " << endl;
  for (auto v: zchecks_bulk)
    {
      cout << "(x,y)=(" << v.x << ","<<v.y << ")"<< endl;
      int i = v.bitrep;
      print_surface(d, d, i);
      cout << endl;
    }

  cout << "X-checks (boundary) " << endl;
  for (auto v: xchecks_bdy)
    {
      cout << "(x,y)=(" << v.x << ","<<v.y << ")"<< endl;
      int i = v.bitrep;
      print_surface(d, d, i);
      cout << endl;
    }

  cout << "Z-checks (boundary) " << endl;
  for (auto v: zchecks_bdy)
    {
      cout << "(x,y)=(" << v.x << ","<<v.y << ")"<< endl;
      int i = v.bitrep;
      print_surface(d, d, i);
      cout << endl;
    }

  cout <<"Logical X:" << endl;
  {
    const string str = std::bitset<n>(logical_x(d)).to_string();
    std::cout << str.substr(str.size()-d*d,str.size()) << ' ';
  }

  cout << endl;
  
  cout <<"Logical Z:" << endl;
  {
    const string str = std::bitset<n>(logical_z(d)).to_string();
    std::cout << str.substr(str.size()-d*d,str.size());
    cout << endl;
  }
}
