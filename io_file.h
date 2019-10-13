#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

class io_file
{
public:
	void generate_errors(double procent);
	void get_file_contents(const char* filename);
	void set_file_contents(const char* filename);
	void show_bits();
	std::vector<bool> vector_bool;
};
