#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

int check_pos(std::string str, size_t pos)
{
	std::string tmp = str.substr(pos, 12);

	size_t poslast = tmp.find(")");
	if (poslast == tmp.npos)
		return 0;
	std::string actual = tmp.substr(4, poslast - 4);
	std::cout << actual << std::endl;

	if (actual.find(',') == actual.npos)
		return 0;
	std::string first = actual.substr(0, actual.find(','));
	std::string second = actual.substr(actual.find(',') + 1);

	std::cout << first << std::endl << second << std::endl;

	return (atol(first.c_str()) * atol(second.c_str()));
}

int main(void)
{
	std::ifstream file;
	file.open("input.txt");

	std::string str;

	long long result = 0;
	getline(file, str, '\0');
	size_t position = 0;
	size_t position_do = 0, position_dont = 0;

	position_do = str.find("do()");
	position_dont = str.find("don't()");

	if (position_do < position_dont)
	{
		str.erase(position_do, 4);
	}
	while(true)
	{
		position_do = str.find("do()");
		position_dont = str.find("don't()");

		if (position_dont == str.npos)
			break;
		if (position_dont < position_do)
		{
			str.erase(position_dont, position_do + 4 - position_dont);
		}
		else
		{
			str.erase(position_do, 4);
		}
	}
	while (true)
	{
		position = str.find("mul(", position);
		if (position == str.npos)
			break;
		result += check_pos(str, position);
		position++;
	}

	std::cout << result;
}