#pragma once
#include "CalculationManager.h"
#include "DynamicDataSet.h"

enum class EAppState
{
	Intro,
	Running,
	Closed
};

class ConsoleApp
{
public:
	ConsoleApp();
	void DisplayAppMenu();
	void DisplaySubMenu();
	EAppState GetState() const;
	~ConsoleApp();

private:
	CalculationManager m_CManager;
	DynamicDataSet m_DataSet;
	EAppState m_AppState;

};

