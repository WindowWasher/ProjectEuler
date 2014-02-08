#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	std::fstream file("PE13.txt");

	std::vector<std::vector<int>> numVec;

	while(!file.eof())
	{	
		std::vector<int> tempVec;
		int tempNum;
		for(int i = 0; i < 50; i++)
		{
			file >> tempNum;
			tempVec.push_back(tempNum);
		}
		numVec.push_back(tempVec);
	}


	int overflow = 0;
	std::vector<int> resVec(50, 0);



	for(int i = 0; i < numVec.size(); i++)
	{
		overflow = 0;
		for(int j = resVec.size() - 1; j >= 0; j--)
		{
			std::vector<int> tempVec(resVec.size() - 50, 0);

			for(int k = 0; k < numVec[i].size(); k++)
				tempVec.push_back(numVec[i][k]);

			if(resVec.size() != tempVec.size())
			{
				std::cout << "Error" << std::endl;
				return 1;
			}

			int val = tempVec[j] + resVec[j] + overflow;
			overflow = 0;

			if(val >= 10)
			{
				overflow = 1;
				int d2 = val % 10;

				resVec[j] = d2;

				if(j == 0)
					resVec.insert(resVec.begin(), overflow, 1);
			}
			else
			{
				resVec[j] = val;
			}


		}
	}



	for(int i : resVec)
		std::cout << i;
	std::cout << std::endl;

	return 0;
}