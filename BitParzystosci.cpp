#include "BitParzystosci.h"

void BitParzystosci::check()
{
	if (odd == this->vector_bool.back())
		std::cout << "Valid!\n";
	else
		std::cout << "Invalid!\n";
}

void BitParzystosci::is_it_odd()
{
	for (auto v : vector_bool)
	{
		if (v) odd ^= odd;
	}
}
