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
	std::vector<int>x = { -1, -1, -1, 0, 0, 1, 1, 1 };
	std::vector<int>y = { -1, 0, 1, -1, 1, -1, 0, 1 };
	std::string search = "XMAS";
	for (size_t col = 0; col < word_search.size(); col++)
	{
		std::string current = word_search[col];

		for (int row = 0; row < current.size(); row++)
		{
			if (current[row] != search[0])
				continue ;
			for (int j = 0; j < 8; j++)
			{
				int current_x = col + x[j];
				int current_y = row + y[j];
				int word_row;

				for (word_row = 1; word_row < search.size(); word_row++)
				{
					if (current_x >= word_search.size() || current_x < 0 || current_y >= current.size() || current_y < 0)
						break;
					if (word_search[current_x][current_y] != search[word_row])
						break;

					current_x += x[j];
					current_y += y[j];
				}

				if (word_row == search.size())
					val++;
			}
		}
	}
	std::cout << val << std::endl;
}