#include "../include/qsim.hpp"
#include "../include/pauli_product.hpp"
#include <cmath>
#include <stdlib.h>


using namespace std;

// Applies a Pauli operator i^{xz} X^xZ^z to the k'th qubit to the state psi.
// This algorithm takes at most 2^n complex number multiplications.
void apply_pauli_fast(int k, bool x, bool z, cx_dvec &psi)
{
  int d;
  d = psi.size();
  if (pow(2,k) >= d)
    {
      throw "Qubit index out of range.";
    }
  if (z)
    {
      if (x)
	{
	  for (int i=0; i<d; i++)
	    {
	      if ((i & ( 1 << k )) >> k == 0)
		{
		  cx_double temp1, temp2;
		  temp1 = psi[i] * cx_double(0.0, 1.0);
		  temp2 = psi[(1<<k)|i] * cx_double(0.0, -1.0);
		  psi[i] = temp2;
		  psi[(1<<k)|i] = temp1;
		}
	    }
	}
      else
	{
	  for (int i=0; i<d; i++)
	    {
	      if ((i & ( 1 << k )) >> k == 1)
		{
		  psi[i] *= -1.0;
		}
	    }
	}
    }
  else
    {
      if (x)
	{
	  for (int i=0; i<d; i++)
	    {
	      if ((i & ( 1 << k )) >> k == 0)
		{
		  cx_double temp1, temp2;
		  temp1 = psi[i];
		  temp2 = psi[(1<<k)|i];
		  psi[i] = temp2;
		  psi[(1<<k)|i] = temp1;
		}
	    }
	}
    }

}

// Apply exp(iPθ) to psi, where P = i^{x·z}(⨂_k X_k^(x_k)) (⨂_k Z_k^(z_k))
void apply_ppr(unsigned int x, unsigned int z, double theta, cx_dvec &psi)
{
  int d;
  d = psi.size();
  cx_double c, s;
  c = cos(theta);
  s = sin(theta);
  //  cx_double csc;
  //  csc = 1.0 / cos(theta);
  bool* not_changed = new bool[(1<<25)];
  fill_n(not_changed, (1<<25), true);

  for (int y=0; y<d; y++)
    {
      if (not_changed[y])
	{
	  
	    unsigned int xz = __builtin_popcount(x&z);
	    unsigned int yz = __builtin_popcount(y&z);
	    
	    cx_double phase1, phase2;

	    switch((1 + xz + 2*(yz+xz))%4)
	      {
	      case 0:
		phase1 = cx_double(1.0, 0.0);
		break;
	      case 1:
		phase1 = cx_double(0.0, 1.0);
		break;
	      case 2:
		phase1 = cx_double(-1.0, 0.0);
		break;
	      case 3:
		phase1 = cx_double(0.0, -1.0);
		break;
	      }
	    
	    switch((1 + xz + 2 * yz)%4)
	      {
	      case 0:
		phase2 = cx_double(1.0, 0.0);
		break;
	      case 1:
		phase2 = cx_double(0.0, 1.0);
		break;
	      case 2:
		phase2 = cx_double(-1.0, 0.0);
		break;
	      case 3:
		phase2 = cx_double(0.0, -1.0);
		break;
	      }
	    cx_double temp1, temp2;
	    temp1 = psi[y] * c + psi[y^x] * s * phase1;
	    temp2 = psi[y^x] * c + psi[y] * s * phase2;
	    psi[y] = temp1;
	    psi[y^x] = temp2;

	    //psi[y] *= c; psi[y] += s * phase1 * psi[y^x];
	    //psi[y^x] += s * phase2 * psi[y];
	    //psi[y^x] *= csc;

	    not_changed[y] = false; not_changed[y^x] = false;
	}
      
    }
  delete[] not_changed;
}

// Measure Pauli Product operator (fast)
double measure_pp(unsigned int x, unsigned int z, cx_dvec &psi)
{
  int d;
  d = psi.size();
  unsigned int bits, n_temp = (d < 0) ? -d : d;
  for(bits = 0; n_temp != 0; ++bits) n_temp >>= 1;
  unsigned int n_q = bits - 1;

  cx_double mysum = 0.0;
  for (int y=0; y<d; y++)
    {
      unsigned int xz = __builtin_popcount(x&z);
      unsigned int yz = __builtin_popcount(y&z);
      cx_double phase;
      switch((xz + 2*yz)%4)
	{
	case 0:
	  phase = cx_double(1.0, 0.0);
	  break;
	case 1:
	  phase = cx_double(0.0, 1.0);
	  break;
	case 2:
	  phase = cx_double(-1.0, 0.0);
	  break;
	case 3:
	  phase = cx_double(0.0, -1.0);
	  break;
	}
      mysum += psi[y] * conj(psi[y^x]) * phase;
    }
  return real(mysum);
}
