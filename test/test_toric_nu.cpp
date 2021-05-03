#include "../include/toric.hpp"
#include "../include/stabilizer.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Checking that apply_ppr and apply_ppr_slow yields the same result.
int main(int argc, char *argv[])
{

  int dx=atoi(argv[1]);
  int dz=atoi(argv[2]);
  const int n = 4096;

  std::vector<Stabilizer> xchecks_bulk = stab_x_bulk_nu(dx, dz);
  std::vector<Stabilizer> zchecks_bulk = stab_z_bulk_nu(dx, dz);

  std::vector<Stabilizer> xchecks_bdy = stab_x_bdy_nu(dx, dz);
  std::vector<Stabilizer> zchecks_bdy = stab_z_bdy_nu(dx, dz);
  
  cout << "X-checks (bulk) " << endl;
  for (auto s: xchecks_bulk)
    {
      cout << "(x,y)=(" << s.x << ","<<s.y << ")"<< endl;
      int i = s.bitrep;
      print_surface(dx, dz, i);
      cout << endl;
    }

  cout << "Z-checks (bulk) " << endl;
  for (auto s: zchecks_bulk)
    {
      cout << "(x,y)=(" << s.x << ","<<s.y << ")"<< endl;
      int i = s.bitrep;
      print_surface(dx, dz, i);
      cout << endl;
    }

  cout << "X-checks (boundary) " << endl;
  for (auto s: xchecks_bdy)
    {
      cout << "(x,y)=(" << s.x << ","<<s.y << ")"<< endl;
      int i = s.bitrep;
      print_surface(dx, dz, i);
      cout << endl;
    }

  cout << "Z-checks (boundary) " << endl;
  for (auto s: zchecks_bdy)
    {
      cout << "(x,y)=(" << s.x << ","<<s.y << ")"<< endl;
      int i = s.bitrep;
      print_surface(dx, dz, i);
      cout << endl;
    }

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

  cout <<"Generating random bit string" << endl;
  int mystring = rand()%(1<<(dx*dz));
  const string mystring_str = std::bitset<n>(mystring).to_string();
  std::cout<<"Mystring="<<mystring_str.substr(mystring_str.size() - dx*dz, mystring_str.size())<<endl;
  
  std::vector<Stabilizer> syndromes_x = measure_stab_x(dx, dz, mystring);
  cout << "X-checks (bulk): " << endl;
  for (auto s: syndromes_x)
    {
      std::cout << "Location=(" << s.x <<","<<s.y <<")"<< endl;
      std::cout << s.parity << endl;
    }

  std::vector<Stabilizer> syndromes_z = measure_stab_z(dx, dz, mystring);
  cout << "Z-checks (bulk): " << endl;
  for (auto s: syndromes_z)
    {
      std::cout << "Location=(" << s.x <<","<<s.y <<")"<< endl;
      std::cout << s.parity << endl;
    }
  
}
