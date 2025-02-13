//Function Program for CISP 1020
//Sept 9th, 2023
//Program accepts user input scores and outputs the total scores in ascending order and gives the average.

#include <iostream>
#include <iomanip>

using namespace std;

void readData(double*, int);
void sortA(double*, int);
double calAverage(double*, int);
void displaySorted(double*, int, double);

int main()
{
	double* numTest = 0;
	double avrg = 0;
	int count;

	//Get the number of test scores you wish to average and put in order
	cout << "How many test scores are you entering? ";
	cin >> count;

	//Dynamically allocate an array large enough to hold that many scores
	numTest = new double[count];
	
	readData(numTest, count);

	sortA(numTest, count);

	avrg = calAverage(numTest, count);

	displaySorted(numTest, count, avrg);

	return 0;
}

//Function to read the data
void readData(double* testscores, int length)
{
	cout << "Enter each of the scores.\n";
	for (int i = 0; i < length; i++)
	{
		do
		{
			cout << "Score #" << (i + 1) << ": ";
			cin >> *(testscores + i);

			if (*(testscores + i) < 0)
			{
				cout << "Scores must be greater than 0.\n"
					<< "Re-enter ";
			}

		} while (*(testscores + i) < 0);
	}
}

//Function to sort the data
void sortA(double* testscores, int length)
{
	int startscan, minIndex;
	double minValue;

	for (startscan = 0; startscan < (length - 1); startscan++)
	{
		minIndex = startscan;
		minValue = *(testscores + startscan);
		for (int i = startscan + 1; i < length; i++)
		{
			if (*(testscores + i) < minValue)
			{
				minValue = *(testscores + i);
				minIndex = i;
			}
		}
		*(testscores + minIndex) = *(testscores + startscan);
		*(testscores + startscan) = minValue;
	}
}

//Function to calculate the average
double calAverage(double* testscores, int length)
{
	double Total = 0;

	for (int i = 0; i < length; i++)
	{
		Total += *(testscores + i);
	}

	return Total / length;
}

//Function to display scores
void displaySorted(double* testinfo,int testscores, double avrg)
{
	cout << "Test Score Info: " << endl;
	cout << "Number of scores: " << testscores << endl;
	cout << "Scores in ascending-order: "<< endl;
	for (int i = 0; i < testscores; i++)
	{
		cout << "#" << (i + 1) << ": " << *(testinfo + i) << endl;
	}
	cout << fixed << showpoint << setprecision(2);
	cout << "Average score: " << avrg << endl;
}
