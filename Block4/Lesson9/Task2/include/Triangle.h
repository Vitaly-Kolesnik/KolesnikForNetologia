#pragma once

#include "Figure.h"

class Triangle : public Figure 
{
	protected:
		double a; 
		double b; 
		double c;
		double A;
		double B;
		double C;

	public:
		Triangle(double a, double b, double c, double A, double B, double C);

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

		void PrintSidesAngles() const;
		void PrintInfo() const override;
};