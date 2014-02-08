#include <iostream>
#include <vector>

int divisorSum(int n);

int main()
{
	std::vector<int> abundentNums;

	std::vector<int> nums;
	long int sum = 0;

	long int tSum = 0;

	for(int i = 1; i < 28123; i++)
	{
		nums.push_back(i);
		tSum += i;
	}

	for(int i = 1; i < 28123; i++)
	{

		int temp = divisorSum(i);

		if(temp > i)
			abundentNums.push_back(i);

	}

	for(unsigned int i = 0; i < abundentNums.size(); i++)
		for(unsigned int j = i; j < abundentNums.size(); j++)
		{
			int t = abundentNums[i] + abundentNums[j] - 1;
			if(t < 28123)
				nums[t] = -1;
			else
				break;
		}
				

	for(int i = 0; i < 28123; i++)
	{
		if(nums[i] != -1)
			sum += nums[i];
	}

	std::cout << sum << std::endl;

	return 0;
}


int divisorSum(int n)
{

	int sum = 1;

	int a = n;

	for(int i = 2; i < a; i++)
	{
		if(n % i == 0)
		{
			if(i != n/i)
			{	
				sum+=i;
				sum+= n/i;
			}
			else
				sum+=i;

			a = n/i;
		}
	}

	return sum;

}