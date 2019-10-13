#pragma once

#include "io_file.h"

class CRC: public io_file
{
public:
	void add_CRC_key(std::vector<bool> key);
	void check(std::vector<bool> key);
private:
	std::vector<bool> XOR_calculation(std::vector<bool> key);
	std::vector<bool> CRC_key;
};

