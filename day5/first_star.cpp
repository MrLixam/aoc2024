#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

int main(void)
{
	std::ifstream file;
	file.open("input.txt");

	std::map<int, std::vector<int>> rules_map;

	std::string input;
	while(true)
	{
		getline(file, input);

		if (input.length() != 5)
			break;
		
		std::string first = input.substr(0, 2);
		std::string second = input.substr(3, 2);
		rules_map[atol(second.c_str())].push_back(atol(first.c_str()));
	}

	long long val = 0;
	while(getline(file, input))
	{
		std::vector<int> list;
		std::stringstream sstream(input);
		while(!sstream.eof())
		{
			std::string list_input;
			int n = 0;
			getline(sstream, list_input, ',');
			n = atol(list_input.c_str());
			if (n > 9)
				list.push_back(n);
		}
		bool rule = false;
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (find(rules_map[list[i]].begin(), rules_map[list[i]].end(), list[j]) == rules_map[list[i]].end())
				{
					rule = true;
					break;
				}
			}
			if (rule)
				break;
		}
		if (!rule)
		{
			val += list[list.size() / 2];
		}
	}
	std::cout << val << std::endl;
}