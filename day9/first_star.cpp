#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

void printVector(const std::vector<std::string>& vec)
{
	for (const auto& str : vec)
		std::cout << str << std::endl;
}

int main(void)
{
	std::ifstream file;
	file.open("input.txt");

	std::string line;
	std::vector<std::string> disk;
	getline(file, line);
	size_t id = 0;
	for (size_t i = 0; i < line.size(); i++)
	{
		int times = line[i] - '0';
		if (i % 2 == 0)
		{
			std::string number = std::to_string(id);
			for (int j = 0; j < times; j++)
			{
				disk.push_back(number);
			}
			id++;
		}
		else
		{
			for (int j = 0; j < times; j++)
			{
				disk.push_back(".");
			}
		}
	}
	std::string list = ".";
	while (true)
	{
		std::vector<std::string>::iterator number;
		for (auto it = disk.rbegin(); it != disk.rend(); it++)
		{
			if (*it != ".")
			{
				number = it.base();
				number--;
				break;
			}
		}
		break;
	}
	unsigned long long value = 0;
	for (size_t i = 0; disk[i] != "."; i++)
	{
		int tmp = atol(disk[i].c_str());
		value += i * tmp;
	}
	std::cout << value << std::endl;
}