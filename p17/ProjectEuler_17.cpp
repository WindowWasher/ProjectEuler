#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
	std::fstream file("log.txt");
	std::vector<std::string> numberWords;
	numberWords.push_back("");
	numberWords.push_back("one");
	numberWords.push_back("two");
	numberWords.push_back("three");
	numberWords.push_back("four");
	numberWords.push_back("five");
	numberWords.push_back("six");
	numberWords.push_back("seven");
	numberWords.push_back("eight");
	numberWords.push_back("nine");
	numberWords.push_back("ten");
	numberWords.push_back("eleven");
	numberWords.push_back("twelve");
	numberWords.push_back("thirteen");
	numberWords.push_back("fourteen");
	numberWords.push_back("fifteen");
	numberWords.push_back("sixteen");
	numberWords.push_back("seventeen");
	numberWords.push_back("eighteen");
	numberWords.push_back("nineteen");



	for(int i = 20; i <= 99; i++)
	{

		int hundreads = i / 10;
		int tens = i % 10;
		std::string numberWord;

		
		switch(hundreads)
		{
		case 2:
			numberWord.append("twenty");
			break;
		case 3:
			numberWord.append("thirty");
			break;
		case 4:
			numberWord.append("forty");
			break;
		case 5:
			numberWord.append("fifty");
			break;
		case 6:
			numberWord.append("sixty");
			break;
		case 7:
			numberWord.append("seventy");
			break;
		case 8:
			numberWord.append("eighty");
			break;
		case 9:
			numberWord.append("ninety");
			break;
		}

		switch(tens)
		{
		case 1:
			numberWord.append(numberWords[tens]);
			break;
		case 2:
			numberWord.append(numberWords[tens]);
			break;
		case 3:
			numberWord.append(numberWords[tens]);
			break;
		case 4:
			numberWord.append(numberWords[tens]);
			break;
		case 5:
			numberWord.append(numberWords[tens]);
			break;
		case 6:
			numberWord.append(numberWords[tens]);
			break;
		case 7:
			numberWord.append(numberWords[tens]);
			break;
		case 8:
			numberWord.append(numberWords[tens]);
			break;
		case 9:
			numberWord.append(numberWords[tens]);
			break;
		}

			

		
		numberWords.push_back(numberWord);
	}

	
	for(int i = 100; i <= 1000; i++)
	{
		std::string numberWord;
		if(i >= 100 && i <= 999)
		{
			int hundreads = i / 100;
			int tens = i % 100;

			numberWord.append(numberWords[hundreads]);
			numberWord.append("hundred");
			if(tens != 0)
			{
				numberWord.append("and");
				numberWord.append(numberWords[tens]);
			}
			numberWords.push_back(numberWord);

		}
		else
		{
			numberWords.push_back("onethousand");
		}
	}
	
	int letterCount = 0;



	for(unsigned int i = 1; i < numberWords.size(); i++)
		letterCount += numberWords[i].size();

	//for(unsigned int i = 1; i < numberWords.size(); i++)
		//file << numberWords[i] << std::endl;

	std::cout << letterCount << std::endl;

	return 0;
}