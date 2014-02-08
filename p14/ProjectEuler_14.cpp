#include <iostream>
static const int MAX_NUM = 999999;

int main()
{

	int max_terms = 0;
	long int max_num = 0;

	for(int i = 1; i < MAX_NUM; i++)
	{
		int count = 1;
		long int n = i; //This number could get very large.

		while(n != 1)
		{
			if(n % 2 == 0)
				n = n/2;
			else
				n = n*3+1;

			count++;
		}

		if(count > max_terms)
		{
			max_terms = count;
			max_num = i;

			

		}

	}


	std::cout << max_terms << std::endl;
	std::cout << max_num << std::endl;
	std::cout << "Finished" << std::endl;
	return 0;
}