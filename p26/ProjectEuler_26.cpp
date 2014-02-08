#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

static const int MAX_SIZE = 1000;


/*

To find the number of repeating decimal digits in 1/d, where 1 <= d < 1000.
We take note that the value of d which will contain the most repeating digits will be prime.
Since we are only interested in prime numbers, we can use the sieve of eratosthenes to calculate primes upto 1000.
It is known that if 10 is a primitive root of the prime, then the number of digits before repeating is equal to p - 1, where p is a prime number.

To check whether 10 is a primitive root we must be able to generate all numbers which have a gcd(i, p) = 1, where 1 <= i < p. 
Since the number is prime all numbers [1, p) will have a gcd(i, p) = 1. This means that 10^i % p must generate the same set to be a primitive root. 
Which means that for each value of i, 10^i % p must map to a unique integer value.
Since we are using the mod, we can use modular exponentiation to evualuate the exponenets which can get quite large.

Helpful links

http://en.wikipedia.org/wiki/Repeating_decimal
http://en.wikipedia.org/wiki/Primitive_root_modulo_n
http://en.wikipedia.org/wiki/Modular_exponentiation

*/


std::vector<int> getPrimes(int limit);
int modular_pow(int base, int exp, int mod);
int largestRepeating();

int main()
{
	int d = largestRepeating();
	std::cout << d << std::endl;

	return 0;
}

int largestRepeating()
{
	std::vector<int> primes = getPrimes(MAX_SIZE);

	for (int s = primes.size() - 1; s >= 0; s--)
	{
		if (primes[s] != 1)
			continue;

		std::vector<bool> bVec(s, false);
		bool collision = false;

		for (int i = 0; i < s-1; i++)
		{
			int res = modular_pow(10, i, s);

			if (!bVec[res])
				bVec[res] = true;
			else
			{
				collision = true;
				break;
			}
		}
		
		if (!collision)
			return s;
	}

	return -1;
}

int modular_pow(int base, int exp, int mod)
{
	int res = 1;

	while (exp > 0)
	{
		if (exp % 2 == 1)
			res = (res * base) % mod;
		exp = exp >> 1;
		base = (base * base) % mod;
	}

	return res;
}

std::vector<int> getPrimes(int limit)
{
	std::vector<int> primes(limit, 0);

	for (int i = 2; i < limit; i++)
	{
		if (primes[i] == 0)
			primes[i] = 1;

		int c = 2;
		int mul = i * c;

		while (mul < limit)
		{
			primes[mul] = -1;
			c++;
			mul = i * c;
		}
	}

	return primes;
}
