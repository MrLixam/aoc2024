#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <tuple>
#include <chrono>

bool try_iteration(std::vector<std::string>& map, int x, int y)
{
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	int direction = 0;
	int nx, ny;
	std::vector<std::tuple<int, int, int, int>> visited;

	while(true)
	{
		std::tuple<int, int, int, int> current = std::make_tuple(x, y, dx[direction], dy[direction]);
		if (find(visited.begin(), visited.end(), current) != visited.end())
			return true;
		visited.push_back(current);
		while (true)
		{
			nx = x + dx[direction];
			ny = y + dy[direction];

			if (nx < 0 || nx >= 130 || ny < 0 || ny >= 130)
				return false;
			if (map[nx][ny] == '#')
			{
				direction = (direction + 1) % 4;
				break;
			}
			x = nx;
			y = ny;
		}
	}
}

int main(void)
{
	std::ifstream file;
	file.open("input");
	std::vector<std::string> map;

	int direction_x = -1, direction_y = 0;
	int x = -1, y = -1;
	std::string input;
	while(getline(file, input))
	{
		map.push_back(input);
		std::string::iterator it = find(input.begin(), input.end(), '^');
		if (it != input.end())
		{
			x = map.size() - 1;
			y = std::distance(input.begin(), it);
		}
	}
	if (x == -1)
		return 1;
	long long possible = 0;
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j] != '.' || (i == x && j == y))
				continue;
			map[i][j] = '#';
			if (try_iteration(map, x, y))
				possible++;
			map[i][j] = '.';
		}
	}
	std::cout << possible << std::endl;
}
