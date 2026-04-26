#pragma once

#include "Triangle.h"

class EquilateralTriangle : public Triangle 
{
	public:
		EquilateralTriangle(double side);
		void PrintInfo() const override;
};