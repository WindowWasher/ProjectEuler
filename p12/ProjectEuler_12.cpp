#include <iostream>
#include <vector>


static const int MAX_DIVS = 500;

int main()
{
	std::vector<int> triangleNums;

	triangleNums.push_back(1);

	int numDivs = 0;

	int max = 0;

	while(numDivs <= MAX_DIVS)
	{

		//std::cout << triangleNums.back()  << std::endl << " " << numDivs << std::endl;
		if(numDivs > max)
		{
			max = numDivs;
			std::cout << max << std::endl;
		}
		numDivs = 0;


		triangleNums.push_back(triangleNums[triangleNums.size() - 1] + triangleNums.size() + 1);
		
		int highVal = triangleNums.back();

		for(int i = 1; i < highVal; i++)
		{
			if(triangleNums.back() % i == 0)
			{
				if(i != triangleNums.back() / i)
					numDivs+=2;
				else
					numDivs++;

				highVal = triangleNums.back() / i;

			}
		}

	}

	std::cout << triangleNums.back() << std::endl;


	return 0;
}