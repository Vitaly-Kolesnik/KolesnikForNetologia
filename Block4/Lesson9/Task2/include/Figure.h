#pragma once

class Figure 
{
	public:
		virtual ~Figure() = default;
		virtual void PrintInfo() const = 0;
};