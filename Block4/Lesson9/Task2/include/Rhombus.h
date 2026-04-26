#pragma once

#include "Parallelogram.h"

class Rhombus : public Parallelogram 
{
	public:
		Rhombus(double side, double A, double B);
		void PrintInfo() const override;
};