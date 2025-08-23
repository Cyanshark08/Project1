#include "ConsoleApp.h"
#include "input.h"

ConsoleApp::ConsoleApp()
	: m_AppState(EAppState::Intro),
	m_MenuState(EMenuState::Main)
{}

void ConsoleApp::ManageAppState()
{
	printf("\n\tCalculator State : %c", (char)m_CManager.GetCalcIndex());

	switch (m_AppState)
	{
	case EAppState::Intro:
		printf("\n\tWhat are descriptive statistics?");
		printf("\n\n\tDescriptive statistics summarize certain aspects of a data set (Sample or Population)");
		printf("\n\tusing numeric calculations.");
		printf("\n\n\thttps://www.calculatorsoup.com/calculators/statistics/descriptivestatistics.php");
		printf("\n\n");
		system("pause");
		system("cls");
		m_AppState = EAppState::Running;
		break;

	case EAppState::Running:
		DisplayMenu();
		break;

	case EAppState::Closed:
		this->Clean();
		break;
	}
}

void ConsoleApp::DisplayMenu()
{
	if (m_AppState == EAppState::Closed)
		return;

	switch (m_MenuState)
	{
	case EMenuState::Main:
		{
			system("cls");
			try
			{
				printf("\n\tData Set :%s\n\t", m_DataSet.to_string().c_str());
			}
			catch (const DynamicDataSet::E_NullSet& e)
			{
				printf("\n\tData Set : This Data Set is Currently NULL (Empty)");
			}
			
			printf("\n\tConfig   : %s\n\t", (m_CManager.GetCalcConfig() == ECaluclatorConfig::Population ? "Population" : "Sample"));
			printf("\n\tDescriptive Statistics Calculator Main Menu");
			printf("\n\t%s", std::string(110, 205).c_str());
			printf("\n\t 0. Exit");
			printf("\n\t 1. Configure Dataset to Sample or Polulation");
			printf("\n\t 2. Insert sort value(s) to the Dataset");
			printf("\n\t 3. Delete value(s) from the Dataset");
			printf("\n\t%s", std::string(110, 196).c_str());
			printf("\n\t A. Find Minimum                   N. Find Outliers");
			printf("\n\t B. Find Maximum                   O. Find Sum of Squares");
			printf("\n\t C. Find Range                     P. Find Mean Absolute Deviation");
			printf("\n\t D. Find Size                      Q. Find Root Mean Square");
			printf("\n\t E. Find Sum                       R. Find Standard Error of Mean");
			printf("\n\t F. Find Mean                      S. Find Skewness");
			printf("\n\t G. Find Median                    T. Find Kurtosis");
			printf("\n\t H. Find Mode(s)                   U. Find Kurtosis Excess");
			printf("\n\t I. Find Standard Deviation        V. Find Coefficient of Variation");
			printf("\n\t J. Find Variance                  W. Find Relative Standard Deviation");
			printf("\n\t K. Find Midrange                  X. Display Frequency Table");
			printf("\n\t L. Find Quartiles                 Y. Display ALL statical results");
			printf("\n\t M. Find Interquartile Range       Z. Output ALL statical results to text file");
			printf("\n\t%s", std::string(110, 205).c_str());

			char choice = Input::inputChar("\n\tOption: ", "0123ABCDEFGHIJKLMNOPQRSTUVWXYZ");
			switch (choice)
			{

			case '0':
				m_AppState = EAppState::Closed;
				return;
			case '1': // configuring dataset
				m_MenuState = EMenuState::Configure;
				break;

			case '2': // insert value into the dataset
				m_MenuState = EMenuState::Insert;
				break;

			case '3': // delete value from the dataset
				m_MenuState = EMenuState::Delete;
				break;
			default:
				m_MenuState = EMenuState::Calculator;
				m_CManager.SetCalcIndex((ECalculationIndex)toupper(choice));
				break;
			}
		}
		break;

	case EMenuState::Insert:
		system("cls");
		// submenu
		printf("\n\tInsert (sort) Dataset Menu");
		printf("\n\t%s", std::string(110, 205).c_str());
		printf("\n\t\tA. Insert a value");
		printf("\n\t\tB. Insert a specified number of random values");
		printf("\n\t\tC. Read data from file and insert values");
		printf("\n\t%s", std::string(110, 196).c_str());
		printf("\n\t\tR. Return");
		printf("\n\t%s", std::string(110, 205).c_str());

		switch (toupper(Input::inputChar("\n\t\tOption: ", "ABCR")))
		{
		case 'A': // insert a value
		{
			int32_t value = Input::inputInteger("\n\tSpecify an integer value to be inserted into the dataset: ");
			m_DataSet.Insert(value);

			printf("\n\t%d has been inserted.", value);
			break;
		}
		case 'B': // insert random number of specified values
		{
			// get the number of random values to insert
			int32_t numOfValues = Input::inputInteger("\n\tSpecify a number of values to be randomly generated into the dataset: ", true);
			m_DataSet.InsertRandom(numOfValues);

			// insert the random values into the dynamic array

			printf("\n\tCONFIRMATION: Inserted %d random value(s) into the Dataset.", numOfValues);
			break;
		}
		case 'C': // read from a file
		{
			// int sizeBefore = 
			//  get the file name
			std::string fileName = Input::inputString("\n\tEnter the file to read from: ", true);

			m_DataSet.InsertFromFile(fileName);

			// read from the file and insert

			// cout << "\n\t" << size after - sizeBefore << " element(s) have been read and inserted into the Dataset " <<
			//	" from " << fileName << ".";
			break;
		}
		case 'R': 
			m_MenuState = EMenuState::Main;
			return;
		default: // invalid option
		{
			printf("\n\tERROR: Invalid Option.");
			break;
		}
		}
		printf("\n\n");
		system("pause");
		break;

	case EMenuState::Delete:
		system("cls");
		// submenu
		printf("\n\tDelete Dataset Menu");
		printf("\n\t%s", std::string(110, 205).c_str());
		printf("\n\t\tA. Delete a Value");
		printf("\n\t\tB. Delete a Range of Values");
		printf("\n\t\tC. Delete All Values");
		printf("\n\t%s", std::string(110, 196).c_str());
		printf("\n\t\tR. Return");
		printf("\n\t%s", std::string(110, 205).c_str());
		switch (toupper(Input::inputChar("\n\t\tOption: ", "ABCR")))
		{
		case 'A': // delete a value
		{
			// could check if the arrray is populated, but we don't have to

			size_t  instances = 0;

			// get the number to delete
			int32_t numToDelete = Input::inputInteger("\n\tSpecify an integer value to find and be deleted from the Dataset: ");
			char choice = Input::inputChar("\n\tDelete *-all elements or 1-one element found with value " +
				std::to_string(numToDelete) + "? ", "*1");

			try
			{
				instances = m_DataSet.DeleteByValue(numToDelete, (choice == '*' ? true : false));
			}
			catch(DynamicDataSet::E_NullSet)
			{

			}
			catch (DynamicDataSet::E_OutOfBounds)
			{

			}
			// loop through the array and if the value matches, deleteAt(i)
			// change found to true, 
			// cout << "\n\tCONFIRMATION: One element " << numToDelete << " has been found and deleted.
			// if one, break after first removal,

			if (!instances)
				printf("\n\tERROR: No element (%d) has been found and deleted.", numToDelete);
			else
			{
				printf("\n\tCONFIRMATION: All %d instance(s) of element (%d) have been found and deleted.", instances, numToDelete); 
				// have to put in # of recurrences/ frequency of the value
			}
			break;
		}
		case 'B': // delete range of values
		{
			DynamicDataSet deletedValues;
			// get the range of values
			size_t startValue = Input::inputInteger("\n\tSpecify a starting integer value to be deleted from the Dataset: ");
			size_t endValue = Input::inputInteger("\n\tSpecify an ending integer value to be deleted from the Dataset: ");

			for (size_t i = startValue; i < endValue; i++)
			{
				deletedValues.Insert(m_DataSet[i]);
				m_DataSet.DeleteAt(i);
			}

			// loop through the array
			// if value At(i) between the range, 

			break;
		}
		case 'C': // delete all values
		{
			// delete the dataset

			printf("\n\tDataset has been purged of all elements.");
			break;
		}
		case 'R': 
			m_MenuState = EMenuState::Main;
			return;
		default:
		{
			printf("\n\tERROR: Invalid option.");
			break;
		}
		}
		printf("\n\n");
		system("pause");
		break;

	case EMenuState::Configure:
		system("cls");
		// submenu
		printf("\n\tIn statistics, Population refers to the entire group of data");
		printf("\n\tpoints that a study is interested in, while a Sample is a");
		printf("\n\tsubset of that population that is actually used in the study.");
		printf("\n\n\tConfigure Data Set Menu");
		printf("\n\t%s", std::string(110, 205).c_str());
		printf("\n\t\tA. Sample");
		printf("\n\t\tB. Population");
		printf("\n\t%s", std::string(110, 196).c_str());
		printf("\n\t\tR. Return");
		printf("\n\t%s", std::string(110, 205).c_str());

		switch (toupper(Input::inputChar("\n\t\tOption: ", "ABR")))
		{
		case 'A': // switch to sample
		{
			printf("\n\tData Set configured for Sample.");
			m_CManager.SetConfig(ECaluclatorConfig::Sample);
			break;
		}
		case 'B': // switch to population
		{
			printf("\n\tData Set configured for Population.");
			m_CManager.SetConfig(ECaluclatorConfig::Population);
			break;
		}
		case 'R': // return
		{
			printf("\n\tNo Change to Dataset");
			m_MenuState = EMenuState::Main;
			return;
		}
		default: // invalid option
		{
			printf("\n\tERROR: Invalid Option.");
			break;
		}
		}
		printf("\n\n");
		system("pause");
		break;

	case EMenuState::Calculator:
		switch (m_CManager.GetCalcIndex())
		{
		case ECalculationIndex::FreqTable:
			m_CManager.GetFrequencyTable(m_DataSet);
			break;

		case ECalculationIndex::DisplayResults:
			m_CManager.PrintAllStatistics(m_DataSet);
			break;

		case ECalculationIndex::OutputResultsToFile:
			
			m_CManager.PrintStatisticsToFile(Input::inputString("\n\tInput the name of the File: ", false), m_DataSet);
			break;

		default:
			printf("\n\t%s\n\t", m_CManager.GetCalculationResultAsString(m_CManager.GetCalcIndex(), m_DataSet).c_str());
		}
		system("pause");
		m_MenuState = EMenuState::Main;
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
