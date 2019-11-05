#include "SumaModulo.h"

void SumaModulo::addModulo()
{
	for (int i = 0; i < 8; i++)
	{
		this->vector_bool.emplace_back((sum >> i) & 1);
	}
}

void SumaModulo::check(unsigned int x)
{
	// zrobić na przesunięciach bitowych 
	// pentla 
	auto modulo = this->vector_bool[vector_bool.size() - 8] + this->vector_bool[vector_bool.size() - 7] * 2 + this->vector_bool[vector_bool.size() - 6] * 4 + this->vector_bool[vector_bool.size() - 5] * 8 +
		this->vector_bool[vector_bool.size() - 4] * 16 + this->vector_bool[vector_bool.size() - 3] * 32 + this->vector_bool[vector_bool.size() - 2] * 64 + this->vector_bool[vector_bool.size() - 1] * 128;
	//std::cout << modulo << std::endl;
	calculateModulo(x);
	if (this->sum == modulo)
		std::cout << "Valid!" << std::endl;
	else
		std::cout << "Invalid!" << std::endl;
}

void SumaModulo::calculateModulo(unsigned int x)
{
	this->sum = 0;
	for (auto i = 0; i < this->vector_bool.size(); i += 8)
	{
		 sum += (this->vector_bool[0 + i] + this->vector_bool[1 + i] * 2 + this->vector_bool[2 + i] * 4 + this->vector_bool[3 + i] * 8 +
			this->vector_bool[ 4 + i] * 16 + this->vector_bool[ 5 + i] * 32 + this->vector_bool[6 + i] * 64 + this->vector_bool[7 + i] * 128) % x;
	}
	
	sum %= x;

	//std::cout << sum << std::endl;
}
