#pragma once

#include "Quadrilateral.h"

class Rectangle : public Quadrilateral 
{
	public:
		Rectangle(double a, double b);
		void PrintInfo() const override;
};