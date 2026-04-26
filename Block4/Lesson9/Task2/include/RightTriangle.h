#pragma once

#include "Triangle.h"

class RightTriangle : public Triangle 
{
	public:
		RightTriangle(double a, double b, double c, double A, double B);
		void PrintInfo() const override;
};