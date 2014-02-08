#include <iostream>
#include <fstream>

static const int MAX_NUM = 21;

int main()
{
	std::fstream file("log.txt");
	long int grid[MAX_NUM];

	for(int i = 0; i < MAX_NUM; i++)
		grid[i] = 1;

	int c = 0;
	while(c < MAX_NUM-1)
	{

		for(int i = 0; i < MAX_NUM; i++)
		{
			long int temp = 0;
			for(int j = i; j < MAX_NUM; j++)
			{
				temp += grid[j];
			}

			grid[i] = temp;
			file << temp << " ";
		}
		c++;
		file << std::endl;
	}


	std::cout << grid[0] << std::endl;

	return 0;
}

