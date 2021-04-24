#include "../include/toric.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Checking that apply_ppr and apply_ppr_slow yields the same result.
int main(int argc, char *argv[])
{

  int d=atoi(argv[1]);
  const int n = 4096;

  
  std::vector<std::tuple<int, int, int>> xchecks_bulk = stab_x_bulk(d);
  std::vector<std::tuple<int, int, int>> zchecks_bulk = stab_z_bulk(d);

  std::vector<std::tuple<int, int, int>> xchecks_bdy = stab_x_bdy(d);
  std::vector<std::tuple<int, int, int>> zchecks_bdy = stab_z_bdy(d);
  
  cout << "X-checks (bulk) " << endl;
  for (auto v: xchecks_bulk)
    {
      cout << "(x,y)=(" << std::get<0>(v) << ","<<std::get<1>(v) << ")"<< endl;
      int i = std::get<2>(v);
      const string str = std::bitset<n>(i).to_string();
      std::cout << str.substr(str.size()-d*d,str.size()) << endl;
      cout << endl;
    }

  cout << "Z-checks (bulk) " << endl;
  for (auto v: zchecks_bulk)
    {
      cout << "(x,y)=(" << std::get<0>(v) << ","<<std::get<1>(v) << ")"<< endl;
      int i = std::get<2>(v);
      const string str = std::bitset<n>(i).to_string();
      std::cout << str.substr(str.size()-d*d,str.size()) << endl;
      cout << endl;
    }

  cout << "X-checks (boundary) " << endl;
  for (auto v: xchecks_bdy)
    {
      cout << "(x,y)=(" << std::get<0>(v) << ","<<std::get<1>(v) << ")"<< endl;
      int i = std::get<2>(v);
      const string str = std::bitset<n>(i).to_string();
      std::cout << str.substr(str.size()-d*d,str.size()) << endl;
      cout << endl;
    }

  cout << "Z-checks (boundary) " << endl;
  for (auto v: zchecks_bdy)
    {
      cout << "(x,y)=(" << std::get<0>(v) << ","<<std::get<1>(v) << ")"<< endl;
      int i = std::get<2>(v);
      const string str = std::bitset<n>(i).to_string();
      std::cout << str.substr(str.size()-d*d,str.size()) << endl;
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
