#include <iostream>
#include <vector>

int d(int a);

int main()
{

	int accum = 0;

	for(int a = 2; a < 10000; a++)
	{
		int b = d(a);
		if(a != b)
		{
			int c = d(b);

			if(c == a)
				accum += a;
		}
	}

	std::cout << accum << std::endl;

	return 0;
}

int d(int a)
{
	std::vector<int> resVec;
	resVec.push_back(1);

	int sum = 0;
	int maxDiv = a;

	for(int i = 2; i < maxDiv; i++)
	{
		if( a % i == 0)
		{
			maxDiv = a/i;
			resVec.push_back(i);
			resVec.push_back(maxDiv);

		}
			
	}

	for(int i : resVec)
		sum += i;

	return sum;
}