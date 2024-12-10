#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>

void dfs_recursive(std::vector<std::string>& map, size_t x, size_t y, std::set<std::pair<int, int>>& reachable_list)
{
	if (map[x][y] == '9')
	{
		reachable_list.insert({x, y});
		return;
	}

	int result = 0;
	if (x > 0 && map[x - 1][y] == map[x][y] + 1)
		dfs_recursive(map, x - 1, y, reachable_list);
	if (x < map.size() - 1 && map[x + 1][y] == map[x][y] + 1)
		dfs_recursive(map, x + 1, y, reachable_list);
	if (y > 0 && map[x][y - 1] == map[x][y] + 1)
		dfs_recursive(map, x, y - 1, reachable_list);
	if (y < map[0].size() - 1 && map[x][y + 1] == map[x][y] + 1)
		dfs_recursive(map, x, y + 1, reachable_list);
	return;
}

int main(void)
{
	std::ifstream file;
	file.open("input");

	std::vector<std::string> map;
	std::string input;
	long long total = 0;
	while(getline(file, input))
		map.push_back(input);
	
	for (size_t i = 0 ; i < map.size(); i++)
	{
		size_t position = map[i].find('0', 0);
		while (position != std::string::npos)
		{
			std::set<std::pair<int, int>> reachable_list;
			dfs_recursive(map, i, position, reachable_list);
			total += reachable_list.size();
			std::cout << "Position: " << reachable_list.size() << std::endl;
			position = map[i].find('0', position + 1);
		}
	}
	std::cout << total << std::endl;
}