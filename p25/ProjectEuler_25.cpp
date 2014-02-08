#include <iostream>
#include <vector>

std::vector<int> addLongHand(std::vector<int> a, std::vector<int> b);

int main()
{
	std::vector<std::vector<int>> fibs;

	std::vector<int> f1 = {1};
	std::vector<int> f2 = {1};
	
	fibs.push_back(f1);
	fibs.push_back(f2);

	
	while (fibs.back().size() < 1000)
		fibs.push_back(addLongHand(fibs[fibs.size()-2], fibs[fibs.size() -1]));

	std::cout << fibs.size() << std::endl;
	
	return 0;
}

std::vector<int> addLongHand(std::vector<int> a, std::vector<int> b)
{

	//Pad with zeros
	if (b.size() > a.size())
		a.insert(a.begin(), b.size() - a.size(), 0);

	int overflow = 0;
	for (int i = b.size() - 1; i >= 0; i--)
	{
		int sum = b[i] + a[i] + overflow;
		overflow = 0;

		if (sum > 9)
		{
			int fn = sum / 10;
			int sn = sum % 10;

			b[i] = sn;

			if (i != 0)
			{
				overflow = fn;
			}
			else
			{
				b.insert(b.begin(), fn);
			}

		}
		else
		{
			b[i] = sum;
		}

	}

	return b;
}