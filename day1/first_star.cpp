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
		int n;
		is >> n;
		first.push_back(n);
		is >> n;
		second.push_back(n);
	}
	file.close();
	std::sort(first.begin(), first.end());
	std::sort(second.begin(), second.end());

	long long result;
	std::vector<int>::iterator first_it = first.begin();
	std::vector<int>::iterator second_it = second.begin();
	
	while(first_it != first.end())
	{
		result += abs(*first_it, *second_it);
		first_it++;
		second_it++;
	}
	std::cout << result << std::endl;
	return (0);
}