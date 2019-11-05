#include "io_file.h"

void io_file::generate_errors(double procent)
{
	std::vector<int> temp;
	srand(time(NULL));
	bool skip = 0;
	int x = 0;
	int errors = 0;
	int number_of_errors = this->vector_bool.size() * procent * 0.01f;
	while (number_of_errors > errors)
	{
		x = rand() % this->vector_bool.size();
		for (auto& v : temp)
		{
			if (v == x)
			{
				skip = 1;
				break;
			}
		}
		if (!skip)
		{
			errors++;
			temp.push_back(x);
			if (this->vector_bool[x])
			{
				this->vector_bool[x] = 0;
			}
			else
			{
				this->vector_bool[x] = 1;
			}
		}
		skip = 0;
	}
	std::cout << "Number of errors generated: " << number_of_errors << std::endl;
}

void io_file::get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		this->vector_bool.reserve(contents.size());
		for (auto& v : contents)
		{
			for (int i = 0; i < 8; i++)
			{
				this->vector_bool.emplace_back((v >> i) & 1);
			}
		}
		return;
	}
	throw(errno);
}

void io_file::set_file_contents(const char* filename)
{
	std::ofstream myfile(filename);
	if (myfile.is_open())
	{
		for (auto v : this->vector_bool)
			myfile << v;
		myfile.close();
		return;
	}
	throw(errno);
}

void io_file::show_bits()
{
	std::cout << '\n';
	for (auto i = 0; i < this->vector_bool.size(); i++)
	{
		if (i > 2 && i % 8 == 0)
			std::cout << " ";
		std::cout << this->vector_bool[i];
	}
	std::cout << '\n';
}
