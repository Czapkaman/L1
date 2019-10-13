#pragma once
#include <iostream>
#include <vector>

#include "io_file.h"

class BitParzystosci: public io_file
{
public:
	void check();
	void is_it_odd();
private:
	bool odd = 0;
};
