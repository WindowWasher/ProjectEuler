#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


int main()
{
	std::fstream file("PE18.txt");
	int numberCount = 1;

	std::vector<std::vector<int>> nodes;

	while(!file.eof())
	{
		std::vector<int> tVec;
		int temp;
		for(int i = 0; i < numberCount; i++)
		{
			file >> temp;
			tVec.push_back(temp);
		}

		numberCount++;

		nodes.push_back(tVec);
	}

	file.close();

	for(unsigned int i = nodes.size() - 1; i >= 1; i--)
	{
		for(unsigned int j = 0; j < nodes[i].size() - 1; j++)
		{
			nodes[i-1][j] = std::max(nodes[i-1][j] + nodes[i][j], nodes[i-1][j] + nodes[i][j+1]);
		}
	}

	std::cout << nodes.front().front() << std::endl;
}