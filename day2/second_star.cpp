#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

int abs(int first, int second)
{
	return(first > second ? first - second : second - first);
}

bool is_safe(bool direction, int current, int next)
{
	if (current == next)
		return (false);
	bool current_direction = current < next ? 0 : 1;
	if (current_direction != direction)
		return (false);
	
	int difference = abs(current, next);
	if (abs(current, next) > 3)
		return (false);
	return (true);
}

bool test_list(std::vector<int> list)
{
	bool direction = list[0] < list[1] ? 0 : 1;

	std::vector<int>::iterator it;
	for (it = list.begin(); std::next(it) != list.end(); it++)
	{
		if (!is_safe(direction, *it, *std::next(it)))
		{
			return (false);
		}
	}
	return (true);
}

int main(void)
{
	std::ifstream file;
	file.open("input");

	int valid = 0;
	std::string current;
	while(getline(file, current))
	{
		std::stringstream sstream(current);
		std::vector<int> list;
		while (!sstream.eof())
		{
			int n;
			sstream >> n;
			//std::cout << n << std::endl;
			list.push_back(n);
		}
		if (test_list(list))
		{
			valid++;
			continue;
		}
		for (int i = 0; i < list.size(); i++)
		{
			std::vector<int> copy;
			std::copy(list.begin(), list.end(), std::back_inserter(copy));
			copy.erase(copy.begin() + i);
			if (test_list(copy))
			{
				valid++;
				break;
			}
		}
	}
	std::cout << valid;
}