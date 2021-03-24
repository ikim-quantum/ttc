#include "../include/toric.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Checking that apply_ppr and apply_ppr_slow yields the same result.
int main(int argc, char *argv[])
{

  int d=atoi(argv[1]);
  const int n = 4096;
  
  std::vector<int> xchecks_bulk = stab_x_bulk(d);
  std::vector<int> zchecks_bulk = stab_z_bulk(d);

  

  cout << "X-checks (bulk): " << endl;
  for (auto i = xchecks_bulk.begin(); i != xchecks_bulk.end(); ++i)
    {
      cout << endl;
      const string str = std::bitset<n>(*i).to_string();
      std::cout << str.substr(str.size()-d*d,str.size()) << ' ';
    }
  cout << endl << endl;

  cout << "Z-checks (bulk): " << endl;
  for (auto i = zchecks_bulk.begin(); i != zchecks_bulk.end(); ++i)
    {
      cout << endl;
      const string str = std::bitset<n>(*i).to_string();
      std::cout << str.substr(str.size()-d*d,str.size()) << ' ';
    }
  cout << endl;
}
