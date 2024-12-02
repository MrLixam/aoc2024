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

int main(void)
{
	std::ifstream file;
	file.open("input.txt");

	int valid = 0;
	std::string current;
	while(getline(file, current))
	{
		std::stringstream sstream(current);
		std::cout << current << std::endl;
		std::vector<int> list;
		while (!sstream.eof())
		{
			int n;
			sstream >> n;
			std::cout << n << std::endl;
			list.push_back(n);
		}
		bool down = false;
		bool up = false;

		std::vector<int>::iterator it;
		for (it = list.begin(); it != list.end(); it++)
		{
			if (std::next(it) == list.end())
				continue;
			int next = *std::next(it);
			if (next < *it)
			{
				down = true;
				std::cout << "next smaller that current" << std::endl;
				std::cout << next << " < " << *it << std::endl;
			}
			if (next > *it)
			{
				up = true;
				std::cout << "next bigger that current" << std::endl;
				std::cout << next << " > " << *it << std::endl;
			}
			if (next == *it)
			{
				std::cout << "equal numbers" << std::endl;
				break;
			}
			if (up && down)
			{
				std::cout << "inverse directions" << std::endl;
				break;
			}
			if (abs(*it, next) > 3)
			{
				std::cout << "gap too big" << std::endl;
				break;
			}
		}
		if (it == list.end())
			valid++;
	}
	std::cout << valid;
}