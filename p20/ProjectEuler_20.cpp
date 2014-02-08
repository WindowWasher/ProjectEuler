#include <iostream>
#include <vector>
#include <assert.h>

std::vector<int> multLongWay(std::vector<int> a, std::vector<int> b);

int main()
{
	std::vector<int> a = {1,0,0};
	std::vector<int> b = { 9,9 };
	std::vector<int> res = multLongWay(a, b);

	for (int i = 98; i >= 1; i--)
	{
		if (i >= 10)
		{
			int fn = i / 10;
			int sn = i % 10;
			std::vector<int> temp = { fn, sn };
			res = multLongWay(res, temp);

		}
		else
		{
			std::vector<int> temp = { i };
			res = multLongWay(res, temp);
		}
	}

	int count = 0;
	int c = 0;
	for (int i : res)
	{
		std::cout << i;
		count += i;
		c++;
	}
	std::cout << "\n" << count << " " << c << std::endl;

	return 0;
}

std::vector<int> multLongWay(std::vector<int> a, std::vector<int> b)
{
	std::vector<std::vector<int>> resVecs;

	for (int i = b.size()-1; i >= 0; i--)
	{
		std::vector<int> res(a.size(), 0);
		int overflow = 0;
		for (int j = a.size() - 1; j >= 0; j--)
		{
			int iRes = b[i] * a[j] + overflow;
			overflow = 0;

			if (iRes >= 10)
			{
				int fd = iRes / 10;
				int sd = iRes % 10;

				res[j] = sd;

				if (j != 0)
					overflow = fd;
				else
					res.insert(res.begin(), fd);
				
			}
			else
			{
				res[j] = iRes;
			}
		}

		resVecs.push_back(res);
	}

	

	//Shift the vectors according to the rules of long hand multiplication.
	for (int i = 1; i < resVecs.size(); i++)
	{
		for (int j = 0; j < i; j++)
			resVecs[i].push_back(0);
		while(resVecs[i].size() > resVecs[i - 1].size())
		{
			resVecs[i - 1].insert(resVecs[i-1].begin(), 0);
		}
	}

	for (int i = 0; i < resVecs.size() - 1; i++)
	{
		if (resVecs[i].size() == resVecs[i + 1].size())
		{
			int overflow = 0;
			for (int j = resVecs[i].size() - 1; j >= 0; j--)
			{
				int sum = resVecs[i][j] + resVecs[i + 1][j] + overflow;
				overflow = 0;

				if (sum >= 10)
				{
					int fn = sum / 10;
					int sn = sum % 10;

					resVecs[i + 1][j] = sn;

					if (j != 0)
						overflow = fn;
					else
						resVecs[i + 1].insert(resVecs[i + 1].begin(), fn);	
				}
				else
				{
					resVecs[i + 1][j] = sum;
				}

			}
		}
		else
		{
			std::cout << "Error" << std::endl;
		}
	}

	return resVecs.back();
}