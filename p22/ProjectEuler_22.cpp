#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

int main()
{
	std::vector<std::string> names;
	std::fstream file("PE22.txt");

	while(!file.eof())
	{
		std::string temp;
		file >> temp;

		names.push_back(temp);
	}

	std::sort(names.begin(), names.end(), [](std::string i, std::string j){return i < j;});

	int total = 0;

	for(unsigned int i = 0; i < names.size(); i++)
	{
		int wordScore = 0;
		for(unsigned int j = 0; j < names[i].size(); j++)
		{
			wordScore += names[i][j] - 64;
		}
		total += wordScore * (i + 1);
	}
		

	std::cout << total << std::endl;

	return 0;
}