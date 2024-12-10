#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

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
	long long iterations = 0;
	while(true)
	{
		if (x + direction_x < 0 || x + direction_x >= map.size())
			break;
		if (y + direction_y < 0 || y + direction_y >= map[x].size())
			break;
		if (map[x + direction_x][y + direction_y] == '#')
		{
			int newX = direction_y;
			int newY = -direction_x;

			direction_x = newX;
			direction_y = newY;
		}
		else
		{
			if (map[x + direction_x][y + direction_y] == '.')
				iterations++;
			map[x][y] = 'X';
			map[x + direction_x][y + direction_y] = '^';
			x = x+direction_x;
			y = y+direction_y;
		}
		std::cout << x << " " << y << std::endl;
	}
	iterations++;
	std::cout << iterations << std::endl;
}