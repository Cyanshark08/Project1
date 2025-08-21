// Andrew Nguyen
// 8/18/2025
// Chapter 1 Assignment.

#include <ctime>
#include <fstream>
#include "input.h"
#include <iostream>
#include <vector>



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
		
	} while (true);
}