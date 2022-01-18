//Ian Fletcher
//This is all my own work
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//definines all functions
vector<int> getNumbers();
void setPowerball(vector<int>& v);
void showNumbers(const vector<int>& v);

//main function
int main()
{
	srand(time(0));
	//asks the user for an int to see how many sets of numbers will be generated
	int lotCount = 0;
	cout << "How many lottery numbers would you like to see? ";
	cin >> lotCount;
	//creates powerball vector
	vector<int> powerball;
	//runs all functions with powerball for the number of times requested
	for (int i = 0; i < lotCount; i++)
	{
		powerball = getNumbers();
		setPowerball(powerball);
		showNumbers(powerball);
	}
	//creates a boolean and string to control while loop
	bool cont = true;
	string moreLot = "";
	//while loop that runs as long as the user wants it to
	while (cont)
	{
		//asks user if they want to run the code more
		cout << "Would you like to generate more numbers? Yes or No?" << endl;
		cin >> moreLot;
		//sets inputted word to lower case to guarentee the code runs
		for (int i = 0; i < moreLot.length(); i++)
		{
			moreLot[i] = tolower(moreLot[i]);
		}
		//if statement that will continue running the functions if the user enters yes
		//and stops if they answer no
		if (moreLot == "yes")
		{
			cout << "How many lottery numbers would you like to see? ";
			cin >> lotCount;
			for (int i = 0; i < lotCount; i++)
			{
				powerball = getNumbers();
				setPowerball(powerball);
				showNumbers(powerball);
			}
		}
		else if(moreLot == "no")
		{
			break;
		}
	}

	return 0;
}

//getNumbers function
vector<int> getNumbers()
{
	//creates int vector to store values
	vector<int> lottery;
	//generates 5 random numbers between 1 and 69 and adds them to the vector
	for (int i = 0; i < 5; i++)
	{
		lottery.push_back(1 + rand() % 69);
	}
	//creates int to assist in organizing vector
	int tempVal = 0;
	//using nested for loops, will arrange vector from least to greatest and
	//change the value of any duplicate numbers
	for (int i = 1; i < lottery.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (lottery[j] < lottery[j - 1])
			{
				tempVal = lottery[j];
				lottery[j] = lottery[j - 1];
				lottery[j - 1] = tempVal;
			}
			else if (lottery[j] == lottery[j - 1])
			{
				lottery[j] = 1 + rand() % 69;
			}
		}
	}
	//returns the vector lottery
	return lottery;
}

//setPowerball function that takes in an int vector
void setPowerball(vector<int>& v)
{
	//sets the last value of the array to a random number between 1 and 26
	int pb = 1 + rand() % 26;
	v.push_back(pb);
}

//showNumbers funcction that takes in an int vector
void showNumbers(const vector<int>& v)
{
	//for loop that will display results of lottery and powerball number
	for (int i = 0; i < v.size(); i++)
	{
		if (i == 5)
		{
			cout << "PB: " << v[i];
		}
		else
		{
			cout << v[i] << " ";
		}
	}
	cout << "" << endl;
}