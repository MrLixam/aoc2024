#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <tuple>
#include <set>

int main(void)
{
	std::ifstream file;
	file.open("input.txt");

	std::map<char, std::vector<std::tuple<int, int>>> instances;
	std::vector<std::string> map;
	std::string input;
	while(getline(file, input))
	{
		map.push_back(input);
	}
	for(size_t it = 0; it < map.size(); it++)
	{
		std::string current = map[it];
		for (size_t i = 0; i < current.size(); i++)
		{
			if (current[i] == '.')
				continue;
			instances[current[i]].push_back(std::make_tuple(it, i));
		}
	}

	std::set<std::pair<int, int>> nodes;

	for (auto key: instances)
	{
		std::vector<std::tuple<int, int>> value = key.second;
		for (size_t i = 0; i < value.size(); i++)
		{
			for (size_t j = i + 1; j < value.size(); j++)
			{
				auto [x1, y1] = value[i];
				auto [x2, y2] = value[j];

				int vec_x = x2 - x1;
				int vec_y = y2 - y1;

				int x = x1 + vec_x, y = y1 + vec_y;
				while (x >= 0 && x < map.size() && y >= 0 && y < map[x].size())
				{
					nodes.insert(std::make_pair(x, y));
					x += vec_x;
					y += vec_y;
				}
				x = x2 - vec_x;
				y = y2 - vec_y;
				while (x >= 0 && x < map.size() && y >= 0 && y < map[x].size())
				{
					nodes.insert(std::make_pair(x, y));
					x -= vec_x;
					y -= vec_y;
				}
			}
		}
	}
	std::cout << nodes.size() << std::endl;
}