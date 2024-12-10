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
	file.open("input");

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

	for (auto& key: instances)
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

				std::pair<int, int> node_1;
				std::pair<int, int> node_2;
				
				node_1 = std::make_pair(x1 - vec_x, y1 - vec_y);
				node_2 = std::make_pair(x2 + vec_x, y2 + vec_y);
				

				if (node_1.first >= 0 && node_1.first < map.size() && node_1.second >= 0 && node_1.second < map[node_1.first].size())
					nodes.insert(node_1);
				if (node_2.first >= 0 && node_2.first < map.size() && node_2.second >= 0 && node_2.second < map[node_2.first].size())
					nodes.insert(node_2);
			}
		}
	}
	std::cout << nodes.size() << std::endl;
}