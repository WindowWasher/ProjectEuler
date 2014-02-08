#include <iostream>
#include <utility>

int main()
{

	enum days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	days day = Tuesday;
	int sundays = 0;

	for(int i = 1901; i <= 2000; i++)
	{
		if(i % 4 == 0)
		{
			if(i % 100 == 0)
			{
				if(i % 400 == 0)
					months[1] = 29;
			}
			else
			{
				months[1] = 29;
			}
		}

		for(int j = 0; j < 12; j++)
		{
			for(int k = 0; k < months[j]; k++)
			{
				if(k == 0 && day == Sunday)
				{
					sundays++;
				}

				switch(day)
				{
				case Monday:
					day = Tuesday;
					break;
				case Tuesday:
					day = Wednesday;
					break;
				case Wednesday:
					day = Thursday;
					break;
				case Thursday:
					day = Friday;
					break;
				case Friday:
					day = Saturday;
					break;
				case Saturday:
					day = Sunday;
					break;
				case Sunday:
					day = Monday;
					break;
				}
			}
		}

		months[1] = 28;
	}


	std::cout << sundays << std::endl;
	return 0;
}