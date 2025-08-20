// Andrew Nguyen
// 8/18/2025
// Chapter 1 Assignment.

#include <ctime>
#include <fstream>
#include "input.h"
// #include "Statistics.h"
#include <iostream>
#include <vector>


a
using namespace std;

char menuOption();
void configureMenu(); // accepts statistics class
void insertMenu(); // accepts statistics class
void deleteMenu(); // accepts statistics class

int main(void)
{
	// display the information

	do
	{

		system("cls");
		// display the menu
		switch (toupper(menuOption()))
		{
		case '0': exit(1); break;
		case '1': // configuring dataset
		{
			// display the configure subMenu
			configureMenu();
			break;
		}
		case '2': // insert value into the dataset
		{
			insertMenu();
			break;
		}
		case '3': // delete value from the dataset
		{
			deleteMenu();
			break;
		}
		case 'A': // find minimum
		{
			break;
		}
		}
		cout << "\n\n";
		system("pause");
	} while (true);
	return EXIT_SUCCESS;
}

// PreCondition: N/A
// PostCondition: displays the menu and returns the user's input as a char
char menuOption()
{
	// display the menu
	cout << "\n\tDescriptive Statistics Calculator Main Menu";
	cout << "\n\t" << string(110, 205);

	cout << "\n\t 0. Exit";
	cout << "\n\t 1. Configure Dataset to Sample or Polulation";
	cout << "\n\t 2. Insert sort value(s) to the Dataset";
	cout << "\n\t 3. Delete value(s) from the Dataset";
	cout << "\n\t" << string(110, 196);

	cout << "\n\t A. Find Minimum                   N. Find Outliers";
	cout << "\n\t B. Find Maximum                   O. Find Sum of Squares";
	cout << "\n\t C. Find Range                     P. Find Mean Absolute Deviation";
	cout << "\n\t D. Find Size                      Q. Find Root Mean Square";
	cout << "\n\t E. Find Sum                       R. Find Standard Error of Mean";
	cout << "\n\t F. Find Mean                      S. Find Skewness";
	cout << "\n\t G. Find Median                    T. Find Kurtosis";
	cout << "\n\t H. Find Mode(s)                   U. Find Kurtosis Excess";
	cout << "\n\t I. Find Standard Deviation        V. Find Coefficient of Variation";
	cout << "\n\t J. Find Variance                  W. Find Relative Standard Deviation";
	cout << "\n\t K. Find Midrange                  X. Display Frequency Table";
	cout << "\n\t L. Find Quartiles                 Y. Display ALL statical results";
	cout << "\n\t M. Find Interquartile Range       Z. Output ALL statical results to text file";
	cout << "\n\t" << string(110, 205);

	return inputChar("\n\tOption: ", "0123ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

// PreCondition: N/A
// PostCondition: display the submenu to configure the type
void configureMenu()
{
	do
	{
		system("cls");
		// submenu
		cout << "\n\tIn statistics, Population refers to the entire group of data";
		cout << "\n\tpoints that a study is interested in, while a Sample is a";
		cout << "\n\tsubset of that population that is actually used in the study.";

		cout << "\n\n\tConfigure Data Set Menu";
		cout << "\n\t" << string(110, 205);
		cout << "\n\t\tA. Sample";
		cout << "\n\t\tB. Population";
		cout << "\n\t" << string(110, 196);
		cout << "\n\t\tR. Return";
		cout << "\n\t" << string(110, 205);

		switch (toupper(inputChar("\n\t\tOption: ", "ABR")))
		{
		case 'A': // switch to sample
		{
			cout << "\n\tData Set configured for Sample.";
			break;
		}
		case 'B': // switch to population
		{
			cout << "\n\tData Set configured for Population.";
			break;
		}
		case 'R': // return
		{
			cout << "\n\tNo Change to Dataset";
			return;
		}
		default: // invalid option
		{
			cout << "\n\tERROR: Invalid Option.";
			break;
		}
		}
		cout << "\n\n";
		system("pause");
	} while (true);
}

// PreCondition: N/A
// PostCondition: display the submenu to insert values
void insertMenu()
{
	do
	{
		system("cls");
		// submenu
		cout << "\n\tInsert (sort) Dataset Menu";
		cout << "\n\t" << string(110, 205);
		cout << "\n\t\tA. Insert a value";
		cout << "\n\t\tB. Insert a specified number of random values";
		cout << "\n\t\tC. Read data from file and insert values";
		cout << "\n\t" << string(110, 196);
		cout << "\n\t\tR. Return";
		cout << "\n\t" << string(110, 205);

		switch (toupper(inputChar("\n\t\tOption: ", "ABCR")))
		{
		case 'A': // insert a value
		{
			int value = inputInteger("\n\tSpecify an integer value to be inserted into the dataset: ");
			// insert into the dynamic array

			cout << "\n\t" << value << " has been inserted.";
			break;
		}
		case 'B': // insert random number of specified values
		{
			// get the number of random values to insert
			int numOfValues = inputInteger("\n\tSpecify a number of values to be randomly generated into the dataset: ", true);

			// insert the random values into the dynamic array

			cout << "\n\tCONFIRMATION: Inserted " << numOfValues << " random value(s) into the Dataset.";
			break;
		}
		case 'C': // read from a file
		{
			// int sizeBefore = 
			//  get the file name
			string fileName = inputString("\n\tEnter the file to read from: ", true);

			// read from the file and insert

			// cout << "\n\t" << size after - sizeBefore << " element(s) have been read and inserted into the Dataset " <<
			//	" from " << fileName << ".";
			break;
		}
		case 'R': return;
		default: // invalid option
		{
			cout << "\n\tERROR: Invalid Option.";
			break;
		}
		}
		cout << "\n\n";
		system("pause");
	} while (true);
}

// PreCondition: N/A
// PostCondition: display the submenu to delete values
void deleteMenu()
{
	do
	{
		system("cls");
		// submenu
		cout << "\n\tDelete Dataset Menu";
		cout << "\n\t" << string(110, 205);
		cout << "\n\t\tA. Delete a Value";
		cout << "\n\t\tB. Delete a Range of Values";
		cout << "\n\t\tC. Delete All Values";
		cout << "\n\t" << string(110, 196);
		cout << "\n\t\tR. Return";
		cout << "\n\t" << string(110, 205);
		switch (toupper(inputChar("\n\t\tOption: ", "ABCR")))
		{
		case 'A': // delete a value
		{
			// could check if the arrray is populated, but we don't have to

			bool found = true;
			int instances = 0;

			// get the number to delete
			int numToDelete = inputInteger("\n\tSpecify an integer value to find and be deleted from the Dataset: ");
			char choice = inputChar("\n\tDelete *-all elements or 1-one element found with value " +
				to_string(numToDelete) + "? ", "*1");

			// loop through the array and if the value matches, deleteAt(i)
			// change found to true, 
			// cout << "\n\tCONFIRMATION: One element " << numToDelete << " has been found and deleted.
			// if one, break after first removal,

			if (!found)
				cout << "\n\tERROR: No element " << numToDelete << " has been found and deleted.";
			else
			{
				cout << "\n\tCONFIRMATION: All " << " instance(s) of element (" << numToDelete <<
					") have been found and deleted."; // have to put in # of recurrences/ frequency of the value
			}
			break;
		}
		case 'B': // delete range of values
		{
			vector<int> valuesDeleted;
			// get the range of values
			int startValue = inputInteger("\n\tSpecify a starting integer value to be deleted from the Dataset: ");
			int endValue = inputInteger("\n\tSpecify an ending integer value to be deleted from the Dataset: ");

			// loop through the array
			// if value At(i) between the range, 

			break;
		}
		case 'C': // delete all values
		{
			// delete the dataset

			cout << "\n\tDataset has been purged of all elements.";
			break;
		}
		case 'R': return;
		default:
		{
			cout << "\n\tERROR: Invalid option.";
			break;
		}
		}
		cout << "\n\n";
		system("pause");
	} while (true);
}