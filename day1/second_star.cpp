#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int abs(int first, int second)
{
	return(first > second ? first - second : second - first);
}

int main(void)
{
	std::ifstream file;
	file.open("input.txt", std::ifstream::in);

	std::string current;
	std::vector<int> first;
	std::vector<int> second;
	while (getline(file, current))
	{
		std::istringstream is(current);
		int n = 0;
		is >> n;
		first.push_back(n);
		is >> n;
		second.push_back(n);
	}

	file.close();
	long long similarity;
	std::vector<int>::iterator it_first = first.begin();

	while(it_first != first.end())
	{
		int value = *it_first;
		it_first++;
		
		std::vector<int>::iterator it = second.begin();

		int count = 0;
		while (it != second.end())
		{
			if (*it == value)
				count++;
			it++;
		}
		similarity += value * count;
	}

	std::cout << similarity;
	return (0);
}