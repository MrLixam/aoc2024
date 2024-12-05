#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

int main(void)
{
	std::ifstream file;
	file.open("input.txt");

	std::vector<std::string> word_search;
	std::string tmp;
	while (getline(file, tmp))
	{
		word_search.push_back(tmp);
	}

	long long val = 0;
	std::vector<int>x = {-1, 0, 1, 0};
	std::vector<int>y = {0, 1, 0, -1};
	for (size_t col = 1; col < word_search.size() - 1; col++)
	{
		std::string current = word_search[col];

		for (int row = 1; row < current.size() - 1; row++)
		{
			if (current[row] != 'A')
				continue ;
			for (int j = 0; j < 4; j++)
			{
				int temp_x = col + x[j];
				int temp_y = row + y[j];
				int word_row;

				if (x[j] != 0)
				{
					char first = word_search[temp_x][temp_y -1];
					char second	= word_search[temp_x][temp_y +1];

					if (first != 'M' || second != first)
						continue;
					
					first = word_search[temp_x + 2 * (x[j] * -1)][temp_y -1];
					second	= word_search[temp_x + 2 * (x[j] * -1)][temp_y +1];

					if (first != 'S' || second != first)
						continue;
					val++;
				}
				else
				{
					char first = word_search[temp_x + 1][temp_y];
					char second	= word_search[temp_x - 1][temp_y];

					if (first != 'M' || second != first)
						continue;
					
					first = word_search[temp_x + 1][temp_y + 2 * (y[j] * -1)];
					second	= word_search[temp_x -1][temp_y + 2 * (y[j] * -1)];

					if (first != 'S' || second != first)
						continue;
					val++;
				}
			}
		}
	}
	std::cout << val << std::endl;
}