#include <iostream>
#include <vector>
#include <string>
static const int MAX_ELE = 1000000;

void recTemp(int &i, std::vector<bool> vb, std::string num);

int main()
{

	std::vector<bool> bVec(10, false);
	std::string num;
	int i = 0;
	recTemp(i, bVec, num);

	return 0;
}

void recTemp(int &i, std::vector<bool> vb, std::string num)
{
	if (i >= MAX_ELE)
		return;
	for (int j = 0; j < vb.size(); j++)
	{
		if (!vb[j])
		{
			vb[j] = true;
			num.append(std::to_string(j));

			if (num.size() == vb.size())			
				++i;
			if (num.size() == vb.size() && i % 100000 == 0)
			std::cout << num << " " << i << std::endl;

			recTemp(i, vb, num);
			
			num.pop_back();
			vb[j] = false;
		}
	}
}