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
	Configure
};

class ConsoleApp
{
public:
	ConsoleApp();
	void ManageAppState();
	void DisplayMenu() const;
	EAppState GetState() const;
	void Clean();

private:
	CalculationManager m_CManager;
	DynamicDataSet m_DataSet;
	EAppState m_AppState;
	EMenuState m_MenuState;

};

