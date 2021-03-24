#include "../include/toric.hpp"
#include <stdlib.h>
#include <vector>

using namespace std;

/* Conventions for the qubit labeling
d=2:

0 1
2 3

d=3:

0 1 2
3 4 5
6 7 8
 
etc.
x-direction:͢͢͢ Left to right
y-direction: Up to down
 */

int coordinate2num(int x, int y, int d)
{
  return x+d*y;
}

int num2x(int n, int d)
{
  return n%d;
}

int num2y(int n, int d)
{
  return n/d;
}

std::vector<int> stab_x_bulk(int d)
{
  std::vector<int> vec;
  for (int x=0; x<d; x++)
    {
      for (int y=0; y<d; y++)
	{
	  if ((y%2==0) && (y+1<d))
	    {
	      if ((x%2==0) && (x+1<d))
		{
		  int n0 = coordinate2num(x,y,d);
		  int n1 = coordinate2num(x+1,y,d);
		  int n2 = coordinate2num(x,y+1,d);
		  int n3 = coordinate2num(x+1,y+1,d);
		  vec.push_back((1<<n0) | (1<<n1) | (1<<n2) | (1<<n3));
		}
	    }
	  else if ((y%2==1) && (y+1<d))
	    {
	      if ((x%2==1) && (x+1<d))
		{
		  int n0 = coordinate2num(x,y,d);
		  int n1 = coordinate2num(x+1,y,d);
		  int n2 = coordinate2num(x,y+1,d);
		  int n3 = coordinate2num(x+1,y+1,d);
		  vec.push_back((1<<n0) | (1<<n1) | (1<<n2) | (1<<n3));
		}
	    }
	}
    }	    

  return vec;
}

std::vector<int> stab_z_bulk(int d)
{
  std::vector<int> vec;
  for (int x=0; x<d; x++)
    {
      for (int y=0; y<d; y++)
	{
	  if ((y%2==0) && (y+1<d))
	    {
	      if ((x%2==1) && (x+1<d))
		{
		  int n0 = coordinate2num(x,y,d);
		  int n1 = coordinate2num(x+1,y,d);
		  int n2 = coordinate2num(x,y+1,d);
		  int n3 = coordinate2num(x+1,y+1,d);
		  vec.push_back((1<<n0) | (1<<n1) | (1<<n2) | (1<<n3));
		}
	    }
	  else if ((y%2==1) && (y+1<d))
	    {
	      if ((x%2==0) && (x+1<d))
		{
		  int n0 = coordinate2num(x,y,d);
		  int n1 = coordinate2num(x+1,y,d);
		  int n2 = coordinate2num(x,y+1,d);
		  int n3 = coordinate2num(x+1,y+1,d);
		  vec.push_back((1<<n0) | (1<<n1) | (1<<n2) | (1<<n3));
		}
	    }
	}
    }	    

  return vec;
}

std::vector<int> stab_x_bdy(int d)
{
  std::vector<int> vec(1);
  return vec;
}

std::vector<int> stab_z_bdy(int d)
{
  std::vector<int> vec(1);
  return vec;
}
