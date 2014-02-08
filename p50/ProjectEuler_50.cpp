#include <iostream>
#include <vector>
#include <cmath>

static const int SIZE = 1000000;

std::vector<int> getPrimes(int highVal);

int main()
{
	std::cout << "Starting getPrimes" << std::endl;
	std::vector<int> primes = getPrimes(SIZE);
	std::cout << "Ending getPrimes" << std::endl;

	int primesCount = 0;
	int p = 0;
	
	for (int i = 0; i < primes.size(); i++)
	{
		int tempPrimeCount = 0;
		int count = 0;

		if (primes[i] == 1)
		{
			for (int j = i; j < primes.size(); j++)
			{
				if (primes[count] == 1)
				{
					if (tempPrimeCount > primesCount)
					{
						primesCount = tempPrimeCount;
						p = count;
					}

				}
				if (primes[j] == 1)
				{
					tempPrimeCount++;
					count += j;
				}

				if (count >= SIZE)
					break;
			}
		}
	}
	
	
	std::cout << p << std::endl;

	return 0;
}

std::vector<int> getPrimes(int highVal)
{
	std::vector<int> primes(highVal, 0);

	for (int i = 2; i < highVal; i++)
	{
		if (primes[i] == 0)
			primes[i] = 1;

		int c = 2;
		int mul = i * c;

		while (mul < highVal)
		{
			primes[mul] = -1;
			c++;
			mul = i * c;
		}
		
	}


	return primes;

}
