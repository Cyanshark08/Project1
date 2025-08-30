#pragma once
#include "CalculationManager.h"
#include "DynamicDataSet.h"

enum class EAppState
{
	Intro,
	Running,
	Closed
};

enum class EMenuState
{
	Main,
	Insert,
	Delete,
	Configure,
	Calculator
};

class ConsoleApp
{
public:
	ConsoleApp();

	/*
	* Precondition: None
	* 
	* Postcondition: Manages app instance based on the current App State
	*/
	void ManageApp();

	/*
	* Precondition: None
	*
	* Postcondition: Displays the correct menu based on current Menu State
	*/
	void DisplayMenu();

	/*
	* Precondition: None
	*
	* Postcondition: Returns the current app state (EAppState enum type)
	* 
	* @return Current App State
	*/
	EAppState GetState() const;

	/*
	* Precondition: None
	*
	* Postcondition: Cleans dedicated data set
	*/
	void Clean();

private:
	CalculationManager m_CManager;
	DynamicDataSet m_DataSet;
	EAppState m_AppState;
	EMenuState m_MenuState;

};

