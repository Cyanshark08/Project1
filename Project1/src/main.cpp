#include "ConsoleApp.h"

int main()
{
	// Create app instance
	ConsoleApp app;

	//Loop app until closed
	do
	{
		app.ManageApp();
	} while (app.GetState() != EAppState::Closed);
}