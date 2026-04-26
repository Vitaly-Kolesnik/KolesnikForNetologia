#pragma once

#include "Figure.h"

class Quadrilateral : public Figure 
{
	protected:
		double a; 
		double b; 
		double c; 
		double d;
		double A;
		double B;
		double C;
		double D;

	public:
		Quadrilateral(double a, double b, double c, double d,
					  double A, double B, double C, double D);

		double Get_a() const 
		{ 
			return a; 
		}
		
		double Get_b() const 
		{ 
			return b; 
		}
		
		double Get_c() const 
		{ 
			return c; 
		}
		
		double Get_d() const 
		{ 
			return d; 
		}
		
		double Get_A() const 
		{ 
			return A; 
		}
		
		double Get_B() const 
		{ 
			return B; 
		}
		
		double Get_C() const 
		{ 
			return C; 
		}
		
		double Get_D() const 
		{ 
			return D; 
		}

		void PrintSidesAngles() const;
		void PrintInfo() const override;
};