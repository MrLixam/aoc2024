#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

struct my_file {
	std::string id;
	size_t start;
	size_t len;
};

size_t find_space(size_t start, size_t length, std::vector<std::string>& disk)
{
	size_t free_length = 0;
	size_t valid_index = std::string::npos;
	size_t current_index = 0;
	for (size_t i = 0; i < start; i++)
	{
		if (disk[i] == ".")
		{
			if (free_length == 0)
				current_index = i;
			free_length++;
			if (free_length >= length)
			{
				valid_index = current_index;
				break;
			}
		}
		else
			free_length = 0;
	}
	return (valid_index);
}

void move_file(std::vector<std::string>& disk, my_file& file, size_t index)
{
	for (size_t i = 0; i < file.len; i++)
	{
		disk[index + i] = file.id;
	}

	for (size_t i = file.start; i < file.start + file.len; i++)
	{
		disk[i] = ".";
	}
	file.start = index;
}

void printVector(const std::vector<std::string>& vec)
{
	for (const auto& str : vec)
		std::cout << str << " ";
	std::cout << std::endl;
}

int main(void)
{
	std::ifstream file("input.txt");
	std::string line;
	getline(file, line);

	std::vector<std::string> disk;
	std::vector<my_file> files;
	size_t id = 0;
	for (size_t i = 0; i < line.size(); i++)
	{
		int times = line[i] - '0';
		if (i % 2 == 0)
		{
			std::string number = std::to_string(id);
			size_t start = disk.size();
			for (int j = 0; j < times; j++)
				disk.push_back(number);
			files.push_back({number, start, (size_t)times});
			id++;
		}
		else
			for (int j = 0; j < times; j++)
				disk.push_back(".");
	}
	
	for (std::vector<my_file>::reverse_iterator it = files.rbegin(); it != files.rend(); it++)
	{
		my_file file = *it;
		size_t new_index = find_space(file.start, file.len, disk);
		if (new_index != std::string::npos)
			move_file(disk, *it, new_index);
	}

	unsigned long long value = 0;
	for (size_t i = 0; i < disk.size(); i++)
	{
		if (disk[i] == ".")
			continue;
		int tmp = atol(disk[i].c_str());
		value += i * tmp;
	}
	std::cout << value << std::endl;
}