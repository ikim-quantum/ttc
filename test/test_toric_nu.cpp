#include "../include/toric.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Checking that apply_ppr and apply_ppr_slow yields the same result.
int main(int argc, char *argv[])
{

  int dx=atoi(argv[1]);
  int dz=atoi(argv[2]);
  const int n = 4096;
  
  std::vector<int> xchecks_bulk = stab_x_bulk_nu(dx, dz);
  std::vector<int> zchecks_bulk = stab_z_bulk_nu(dx, dz);

  std::vector<int> xchecks_bdy = stab_x_bdy_nu(dx, dz);
  std::vector<int> zchecks_bdy = stab_z_bdy_nu(dx, dz);
  
  cout << "X-checks (bulk): " << endl;
  for (auto i = xchecks_bulk.begin(); i != xchecks_bulk.end(); ++i)
    {
      const string str = std::bitset<n>(*i).to_string();
      std::cout << str.substr(str.size()-dx*dz,str.size()) << ' ';
    }
  cout << endl;

  cout << "Z-checks (bulk): " << endl;
  for (auto i = zchecks_bulk.begin(); i != zchecks_bulk.end(); ++i)
    {
      const string str = std::bitset<n>(*i).to_string();
      std::cout << str.substr(str.size()-dx*dz,str.size()) << ' ';
    }
  cout << endl<<endl;

  
  cout << "X-checks (boundary): " << endl;
  for (auto i = xchecks_bdy.begin(); i != xchecks_bdy.end(); ++i)
    {
      const string str = std::bitset<n>(*i).to_string();
      std::cout << str.substr(str.size()-dx*dz,str.size()) << ' ';
    }
  cout << endl;

  cout << "Z-checks (boundary): " << endl;
  for (auto i = zchecks_bdy.begin(); i != zchecks_bdy.end(); ++i)
    {
      const string str = std::bitset<n>(*i).to_string();
      std::cout << str.substr(str.size()-dx*dz,str.size()) << ' ';
    }
  cout << endl<<endl;

  cout <<"Logical X:" << endl;
  {
    const string str = std::bitset<n>(logical_x_nu(dx, dz)).to_string();
    std::cout << str.substr(str.size()-dx*dz,str.size()) << ' ';
  }

  cout << endl;
  
  cout <<"Logical Z:" << endl;
  {
    const string str = std::bitset<n>(logical_z_nu(dx, dz)).to_string();
    std::cout << str.substr(str.size()-dx*dz,str.size());
    cout << endl;
  }
  
}
