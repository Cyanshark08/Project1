#include "ConsoleApp.h"

ConsoleApp::ConsoleApp()
	: m_AppState(EAppState::Intro)
{}

void ConsoleApp::ManageAppState()
{
	switch (m_AppState)
	{
	case EAppState::Intro:
		printf("\n\tWhat are descriptive statistics?");
		printf("\n\n\tDescriptive statistics summarize certain aspects of a data set (Sample or Population)");
		printf("\n\tusing numeric calculations.");
		printf("\n\n\thttps://www.calculatorsoup.com/calculators/statistics/descriptivestatistics.php");
		printf("\n\n");
		system("pause");
		break;

	case EAppState::Running:
		DisplayMenu();
		break;

	case EAppState::Closed:
		this->Clean();
		break;
	}
}

void ConsoleApp::DisplayMenu() const
{

	switch (m_MenuState)
	{
	case EMenuState::Main:
		
		break;

	case EMenuState::Insert:
		break;

	case EMenuState::Delete:

		break;

	case EMenuState::Configure:

		break;

	default:

		break;
	}
}

EAppState ConsoleApp::GetState() const
{
	return m_AppState;
}

void ConsoleApp::Clean()
{
	m_DataSet.Clean();
}
