#include "DynamicDataSet.h"
#include "CalculationManager.h"
#include "ConsoleApp.h"

int main()
{
	ConsoleApp app;

	do
	{
		app.DisplayAppMenu();
	}
	while (app.GetState() != EAppState::Closed);

}