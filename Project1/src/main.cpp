/*
* Collaborators: 
* - Andrew Nguyen
* - Jaime Gutierrez
* - Landon Mendoza
* 
* Date: 8/30/2025
* 
* Project: Statistics Calculator with implemented Statistic functions & DynamicDataSet (dynamic array) data structure
* 
*/

#include "ConsoleApp.h"

int main()
{
	// Create app instance
	ConsoleApp app;

	// Loop app until closed
	do
	{
		app.ManageApp();
	} while (app.GetState() != EAppState::Closed);
}