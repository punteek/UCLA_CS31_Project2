// Prateek Singh
// Project 2, Due: 10/15/2015 9:00 pm
// Professor Smallberg

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int units;
	string title;
	double price;
	string premium;


	// Get input from user

	cout << "Units sent: ";
	cin >> units;

	cin.ignore(1000, '\n');

	cout << "Title: ";
	getline(cin, title);

	cout << "Base price: ";
	cin >> price;

	cin.ignore(1000, '\n');

	cout << "Premium item? (y/n): ";
	cin >> premium;

	// output for all error cases

	if (units < 0)
	{
		cout << "The number of units sent must be nonnegative." << endl;
	}

	else if (title == "")
	{
		cout << "You must enter a title." << endl;
	}

	else if (price < 0)
	{
		cout << "The base price must be nonnegative." << endl;
	}

	else if (premium != "y" && premium != "n")
	{
		cout << "You must enter y or n." << endl;
	}

	// calculations, based on decreasing the value of the variable "units"
	// after each segment

	else
	{

		double royalty;

		if (units - 400 >= 0)
		{
			royalty = 400 * price * 0.09;
			units = units - 400;
		}

		else
		{
			royalty = units * price * 0.09;
			units = 0;
		}

		if (units - 800 >= 0)
		{
			if (premium == "n")
			{
				royalty = royalty + (800 * price * 0.13);
				units = units - 800;
			}

			else
			{
				royalty = royalty + (800 * price * 0.16);
				units = units - 800;
			}
		}

		else
		{
			if (premium == "n")
			{
				royalty = royalty + (units * price * 0.13);
				units = 0;
			}

			else
			{
				royalty = royalty + (units * price * 0.16);
				units = 0;
			}
		}

		if (units > 0)
		{
			royalty = royalty + (units * price * 0.14);
		}

		// clean up answer

		cout.setf(ios::fixed);
		cout.precision(2);

		// final answer

		cout << "---" << endl;
		cout << title << " earned" << " $" << royalty << " in royalties." << endl;
	}
}