#pragma once

#include "Quadrilateral.h"

class Parallelogram : public Quadrilateral 
{
	public:
		Parallelogram(double a, double b, double A, double B);
		void PrintInfo() const override;
};