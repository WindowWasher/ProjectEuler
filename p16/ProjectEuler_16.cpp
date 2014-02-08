#include <iostream>
#include <vector>

int main()
{

	std::vector<int> longDigit;
	longDigit.push_back(2);

	int overflow = 0;

	for(int i = 0; i < 999; i++)
	{

		for(int j = longDigit.size() - 1; j >= 0; j--)
		{

			int temp = longDigit[j] * 2 + overflow;

			if(temp >= 10)
			{
				int d1 = temp / 10;
				int d2 = temp % 10;

				longDigit[j] = d2;

				if( j != 0)
				{
					overflow = d1;
				}
				else
				{
					longDigit.insert(longDigit.begin(), d1, 1);
					overflow = 0;
				}
			}
			else
			{
				longDigit[j] = temp;
				overflow = 0;
			}

		}

	}

	int count = 0;

	for(int i : longDigit)
		count += i;

	std::cout << count <<  std::endl;

	return 0;
}