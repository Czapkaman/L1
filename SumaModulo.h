#pragma once

#include "io_file.h"
class SumaModulo :
	public io_file
{
public:
	void addModulo();
	void check(unsigned int x);
	void calculateModulo(unsigned int x);
private:
	unsigned int sum;
};

