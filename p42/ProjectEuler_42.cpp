#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int getWordValue(std::string);
bool isTriangleNum(int num);

int main()
{

	std::fstream file("words.txt");
	if (!file)
	{
		std::cout << "Could not open file" << std::endl;
		return 1;
	}

	std::string word;
	int count = 0;
	while (!file.eof())
	{
		file >> word;
		if (isTriangleNum(getWordValue(word)))
		{
			count++;
		}
	}
	std::cout << count << std::endl;
	return 0;
}

int getWordValue(std::string word)
{
	int wordVal = 0;
	
	for (int i = 0; i < word.size(); i++)
	{
		wordVal += word[i] - 64;
	}

	return wordVal;
}

bool isTriangleNum(int num)
{
	for (int i = 1; (i * (i + 1)) / 2 <= num; i++)
	{
		if ((i * (i + 1)) / 2 == num)
			return true;
	}

	return false;
}