/*
Author: Ryan Stevens
6/1/2016
Language C++

You work for a company that makes cars. The company makes a different color car every day, Monday through Friday. The colors are:
•	Red
•	Orange
•	Yellow
•	Green
•	Blue
•	Purple
•	Black
The colors always follow that same order. For example, if today is Friday and the company is making Blue cars, then that means that yesterday (Thursday) the company was making Green cars, and next Monday the company will be making Purple cars, and so on, ad infinitum.

Assume today is Monday and that the company happens to be making Red cars. The production manager wants a way to know what color car the company will be making X days in the future. Your task is to implement a function named color_of_the_day that accepts the number of days in the future for which to determine the color of the day, and return the name of the color. If the day happens to fall on a weekend, return ‘No Color’.

Examples:
•	color_of_the_day(0)  -> ‘Red’
•	color_of_the_day(1)  -> ‘Orange’
•	color_of_the_day(5)  -> ‘No Color’
•	color_of_the_day(15)  -> ‘Blue’
*/

#include <iostream>
#include <string>

using namespace std;


string color_of_the_day(int day)
{
	string colors[] = { "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Black"}; // Array to store the colors 
	int carColor = 0;
	int weekEnd = 0;
	bool noColor = false;
	for (int i = 0; i < day; i++)
	{
		carColor++;
		weekEnd++;
		
		if ((weekEnd == 5) || (weekEnd == 6))
		{
			carColor--;
			noColor = true;
		}

		if (weekEnd > 6)
		{
			noColor = false;
			weekEnd = 0;
		}
		if (carColor >= 7)
		{
			carColor = 0;
		}
	}
	if (noColor == true)
	{
		return "no color";
	}
	else
	{
		return colors[carColor];
	}
	
}

int main()
{
	int inputDay = 0; // to store the day that we will be looking into.
	string returnedDay; //store the returned day for debugging purposes.
	cout << "Please enter the day you would like: " ;
	cin >> inputDay; 
	while (inputDay <= -1)
	{
		cout << "please input a valid number that is bigger than zero" << endl; // in case they put in negative numbers. This is assuming that we only want to look forward in time.
		cin >> inputDay;
	}

	returnedDay = color_of_the_day(inputDay);	
	cout << "The color of the day is " << returnedDay << "." << endl;
	system("pause");
}