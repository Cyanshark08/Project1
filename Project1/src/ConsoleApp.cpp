#include "ConsoleApp.h"

ConsoleApp::ConsoleApp()
	: m_AppState(EAppState::Intro)
{}

void ConsoleApp::DisplayAppMenu()
{
	//TODO: Move Menu Here
}

void ConsoleApp::DisplaySubMenu()
{
	//TODO: idk
}

EAppState ConsoleApp::GetState() const
{
	return m_AppState;
}

ConsoleApp::~ConsoleApp()
{
	m_DataSet.Clean();
}
