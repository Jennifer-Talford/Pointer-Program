#include <iostream>
// provides manipulators that can be used to format the output of your streams (change width, direction (left/right), etc)
#include <iomanip>
// powerful tool for strings; allows you to perform various operations such as concatenation,search,and manip of text data (aka alter info)
#include <string>
// allows you to read data from files
#include <fstream>
// provides a wide range of functions for arrays, vectors, and lists
#include <algorithm>
using namespace std;

// groups together variables of different data types under a single name. It is similar to a class, but with the default access being public
typedef struct
{
	string name;
	double testScore;
}	Records;

//Define variables
// * pointer, points to specific point in memory
Records* TestScores;
double average;
int numTest;
int numb;

void readData(Records*, int, int);
void displayUnsorted(Records*, int, int);
void selectSort(Records*, int);
double avgScore(Records*, int);
void displaySorted(Records*, int, int); 

int main()
{ 
	//Reads file
	readData(TestScores, numb, numTest);

	//Get the number of test scores you wish to average and put in order
	cout << "How many test scores do you wish to enter?" << endl;
	cin >> numTest;
	cout << endl;

	//Dynamically allocate an array large enough to hold that many scores
	// new does create a new array
	TestScores = new Records[numTest];

	//Function to display unsorted data
	displayUnsorted(TestScores, numb, numTest);

	//Display the results
	selectSort(TestScores, numTest);

	//Calculates average
	average = avgScore(TestScores, numTest);

	//Sorts and displays
	displaySorted(TestScores, numb, numTest);

	return 0;
}

//Function to read the data
void readData(Records* TestScores, int numb, int numTest)
{
	string readfileprompt;
	string linerec;
	const int Studentnames = 20;
	bool looper = false;

	cout << "Would you like to read existing file? Please type 'Yes' or 'No' using uppercase: " << endl;
	cin >> readfileprompt;

	//If yes, opens and reads data from .txt doc
	if (readfileprompt == "Yes" or readfileprompt == "yes")
	{
		int avg;
		int sumvar = 0;
		int arr[24];
		int len = sizeof(arr) / sizeof(arr[0]);
		int scores[24];
		int totscores = 1;
		string names[24];
		string linerec;

		ifstream studentinfo("StudentData.txt");

		//Function to read the data
		for (int index = 0; index < Studentnames; index++)
		{
			int namesindex = 0;
			int scoresindex = 0;

			while (getline(studentinfo, linerec))
			{
				cout << "Unsorted data: " << endl;
				cout << linerec << endl;
				
				// char data type used to store a single character
				char name[9];
				char score[3];
				int nameindex = 0;
				int scoreindex = 0;

				for (int index = 0; index < linerec.size(); index++)
				{
					int results = isalpha(linerec[index]);

					//check to see if alphabet char
					if (isalpha(linerec[index]) < 0)
					{
						name[nameindex] = linerec[index];
						nameindex++;
					}

					//check if number
					else if (isdigit(linerec[index]) == 1)
					{
						score[scoreindex] = linerec[index];
						scoreindex++;
					}

					else //Captures other info from string besides letter or number such as " " or ?, etc
					{

					}
				}
				names[namesindex] = name;
				namesindex++;

				scores[scoresindex] = atoi(score); //atoi takes string/char to integer
				scoresindex++;

			}

		}
		for (int totscoreindex = 0; totscoreindex < 24; totscoreindex++)
		{
			totscores = scores[totscoreindex];
		}

		avg = 20 / totscores;
		
		cout << "Sorted Data: " << endl << "Names: " << names << " and scores: " << scores << endl;
		cout << "Average is: " << avg << endl;
	}

	else if (readfileprompt == "No" or readfileprompt == "no")
	{
		cout << endl << "Please continue: " << endl;
		looper = true;
	}
	
	else
	{
		cout << "Invalid response. Please enter valid option." << endl;
	}
}

//Function to display unsorted data
void displayUnsorted(Records* TestScores, int numb, int numTest)
{
	//Get the test scores
	cout << "Enter the test scores below." << endl;
	for (numb = 0; numb < numTest; numb++)
	{
		//Display score
		cout << "Student Name " << (numb + 1) << ": ";
		cin >> (TestScores + numb)->name;
		cout << "Test Score " << (numb + 1) << ": ";
		cin >> TestScores[numb].testScore;
		// Input validation. Only numbers between 0-100
		while ((TestScores + numb)->testScore < 0 || (TestScores + numb)->testScore>99)
		{
			cout << "You must enter a scores that non-negative" << endl;
			cout << "Please enter again: ";
			cin >> TestScores[numb].testScore;
		}
	}

	return;
}

//Function to sort the data
void selectSort(Records* arr, int size)
{
	int startScan;
	int minIndex;
	double minElem;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minElem = (arr + startScan)->testScore;
		for (int index = startScan; index < size; index++)
		{
			if ((arr + index)->testScore < minElem)
			{
				minElem = (arr + index)->testScore;
				minIndex = index;
			}
		}
		if (minIndex != startScan)
		{
			Records temp = arr[minIndex];
			arr[minIndex] = arr[startScan];
			arr[startScan] = temp;
		}
	}
}

//Function to calculate the average
double avgScore(Records* arr, int size)
{
	double total = 0;
	double average;
	int numTest;

	for (int count = 0; count < size; count++)
	{
		total += (arr + count)->testScore;
	}
	average = total / size;

	return average;
}

//Function to display sorted data
void displaySorted(Records* TestScores, int numb, int numTest)
{
	//Display the Test Scores in ascending order
	cout << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "The test scores, in ascending order, are: " << endl;
	for (numb = 0; numb < numTest; numb++)
	{
		cout << (TestScores + numb)->name << " has a test score of: " << (TestScores + numb)->testScore << endl;
	}
	//Display the average of the test scores
	cout << endl << "The average test score is: " << average << endl;

	//Free dynamically allocated memory
	delete[] TestScores;

	TestScores = 0;
}
