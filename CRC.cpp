#include "CRC.h"

void CRC::add_CRC_key(std::vector<bool> key)
{
	std::vector<bool> temp = XOR_calculation(key);
	vector_bool.insert(vector_bool.end(), temp.begin(), temp.end());
	this->CRC_key.insert(CRC_key.begin(), temp.begin(), temp.end());
}

void CRC::check(std::vector<bool> key)
{
	std::vector<bool> temp = XOR_calculation(key);
	if (temp == CRC_key)
		std::cout << "Valid!\n";
	else
		std::cout << "Invalid!\n";
}


std::vector<bool> CRC::XOR_calculation(std::vector<bool> key)
{
	std::vector<bool> temp = vector_bool;
	for (int i = 0; i < key.size() - 1; i++)
	{
		temp.emplace_back(0);
	}
	for (int i = 0; temp.size() + 1 > i + key.size(); i++)
	{
		if (temp[i])
		{
			for (int j = 0; j < key.size(); j++)
			{
				if ((temp[i + j] && key[j]) || (!temp[i + j] && !key[j]))
				{
					temp[i + j] = 0;
				}
				else
				{
					temp[i + j] = 1;
				}
			}
		}
	}
	temp.erase(temp.begin(), temp.end() - key.size() + 1);
	return temp;
}
