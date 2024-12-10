#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

bool obtainable(long long value, long long current, std::vector<long long>& numbers, int index)
{
	if (current > value)
		return false;
	if (index == numbers.size())
		return (current == value);
	
	if (obtainable(value, current + numbers[index], numbers, index + 1))
		return true;
	if (current > 0 && obtainable(value, current * numbers[index], numbers, index + 1))
		return true;
	return false;
}

int main(void)
{
	std::ifstream file;
	file.open("input");

	std::string current;
	unsigned long long total = 0;
	while (getline(file, current))
	{
		std::string value_str;
		std::stringstream sstream(current);
		getline(sstream, value_str, ':');
		long long value = atoll(value_str.c_str());
		std::vector<long long> numbers;
		//std::cout << current << std::endl;
		//std::cout << value << ": ";
		while (true)
		{
			long long tmp = -1;
			sstream >> tmp;
			if (tmp == -1)
				break;
			// std::cout << tmp << " ";
			numbers.push_back(tmp);
		}
		// std::cout << std::endl;
		if (obtainable(value, 0, numbers, 0))
			total += value;
	}
	std::cout << total << std::endl;
}