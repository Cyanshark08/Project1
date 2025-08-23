#include "DynamicDataSet.h"
#include <sstream>
#include <random>
#include <fstream>
#include <iomanip>

#ifndef MAX_ARR_ELEMENTS_ACROSS
	#define MAX_ARR_ELEMENTS_ACROSS 15
#endif

//Copy Constructor
DynamicDataSet::DynamicDataSet(const DynamicDataSet& p_Other)
{
	for (size_t i = 0; i < p_Other.GetCount(); i++)
		this->Insert(p_Other[i]);
}

inline int32_t DynamicDataSet::At(size_t p_Index) const
{

	//Check if set is empty
	if (m_DataCount == 0)
		throw E_NullSet();

	//Check if index is out of bounds
	if (p_Index >= m_DataCount)
		throw E_OutOfBounds(p_Index);

	return m_DataPtr[p_Index];
}

//  
// Insertion Sort 
//
inline void DynamicDataSet::Insert(int32_t p_NewDataPoint)
{
	if (m_DataCount == 0)
	{
		m_DataPtr = new int32_t[++m_DataCount];
		m_DataPtr[0] = p_NewDataPoint;
		return;
	}

	int32_t* newData = new int32_t[++m_DataCount];

	// Create iterators
	size_t oldIter = 0;
	size_t newIter = 0;

	// Insert elements into new array until
	// the new data point is <= the last
	// element in the data set
	for (; newIter < m_DataCount; newIter++)
	{
		// Check if at the end of the data set
		// if so, insert new data point
		if(!(oldIter < m_DataCount - 1)) 
		{
			newData[newIter++] = p_NewDataPoint;
			break;
		}

		if (m_DataPtr[oldIter] < p_NewDataPoint)
			newData[newIter] = m_DataPtr[oldIter++];
		else
		{
			newData[newIter++] = p_NewDataPoint;
			break;
		}
	}

	// Add the remaining elements to the set
	for (; newIter < m_DataCount; newIter++)
	{
		newData[newIter] = m_DataPtr[oldIter++];
	}

	delete[] m_DataPtr;
	m_DataPtr = newData;
}

void DynamicDataSet::InsertRandom(size_t p_NumOfValues)
{
	srand(time(NULL));

	for (size_t i = 0; i < p_NumOfValues; i++)
		this->Insert(rand() % 101);

}

void DynamicDataSet::InsertFromFile(const std::string& p_FileName)
{
	std::ifstream fileStream(p_FileName.c_str());

	if(fileStream.fail())
	{
		printf("\n\tERROR: File \"%s\" does not exist", p_FileName.c_str());
		return;
	}

	std::string strBuffer;
	std::string token;

	while (std::getline(fileStream, strBuffer))
	{
		std::istringstream tokenStream(strBuffer);
		while (std::getline(tokenStream, token, ' '))
		{
			for (size_t i = 0; i < token.length(); i++)
			{
				if (!(std::isdigit(token[i]) && token[i] != '-'))
					throw E_InvalidFileFormat(token, p_FileName);
			}
			this->Insert(std::stoi(token));
		}
	}

	fileStream.close();
}

void DynamicDataSet::DeleteAt(size_t p_Index)
{

	if (m_DataCount == 0)
		throw E_NullSet();

	if (p_Index >= m_DataCount)
		throw E_OutOfBounds(p_Index);

	int32_t* newData = new int32_t[--m_DataCount];

	size_t oldIter = 0;
	size_t newIter = 0;
	for (; oldIter < m_DataCount + 1; oldIter++)
	{
		if (oldIter != p_Index)
			newData[newIter++] = m_DataPtr[oldIter];
		else
			continue;
	}

	delete[] m_DataPtr;
	m_DataPtr = newData;

}

size_t DynamicDataSet::DeleteByValue(int32_t p_Value, bool p_DeleteAll)
{
	if (m_DataCount == 0)
		throw E_NullSet();

	size_t count = 0;

	for (size_t i = 0; i < m_DataCount; i++)
	{
		if (m_DataPtr[i] == p_Value)
		{
			count++;
			DeleteAt(i--);
			if (!p_DeleteAll)
				return count;
		}
		

	}

	return count;
}

size_t DynamicDataSet::NumberOfRecurrences(int32_t p_Value) const
{
	if (m_DataCount == 0)
		throw E_NullSet();

	size_t count = 0;

	for (size_t i = 0; i < m_DataCount; i++)
	{
		if (m_DataPtr[i] == p_Value)
			count++;
	}

	return count;
}

size_t DynamicDataSet::GetCount() const
{
	return m_DataCount;
}

const int32_t* DynamicDataSet::GetAddress() const
{
	return m_DataPtr;
}

std::string DynamicDataSet::GetAddressAsString() const
{
	std::stringstream ss;
	ss << "0x" << m_DataPtr;
	return ss.str();
}

std::string DynamicDataSet::to_string() const
{
	std::stringstream ss;
	for (size_t i = 0; i < m_DataCount; i++)
		ss << (i % MAX_ARR_ELEMENTS_ACROSS ? "" : "\n\t") << std::setw(4) << this->At(i) << " ";

	return ss.str();
}

void DynamicDataSet::Clean()
{
	delete[] m_DataPtr;
	m_DataPtr = nullptr;
	m_DataCount = NULL;
}

DynamicDataSet::~DynamicDataSet()
{
	this->Clean();
}


inline DynamicDataSet::operator std::string() const
{
	return this->to_string();
}




int32_t DynamicDataSet::operator[](size_t p_Index) const
{
	return this->At(p_Index);
}

//
//Exception Implementations
//

DynamicDataSet::E_OutOfBounds::E_OutOfBounds(size_t p_Index)
	: m_Index(p_Index)
{}

std::string ExceptionInterface::Message() const
{
	std::stringstream ss;
	ss << "\n\tEXCEPTION ERROR: " << GetExceptionMessage() << "\n\n\t";
	return ss.str();
}

inline std::string DynamicDataSet::E_OutOfBounds::GetExceptionName() const
{
	return "Index Out of Bounds";
}

inline std::string DynamicDataSet::E_OutOfBounds::GetExceptionMessage() const
{
	std::stringstream ss;
	ss << GetExceptionName() << " (Index [" << m_Index << "] Out of Bounds)";
	return ss.str();
}

DynamicDataSet::E_NullSet::E_NullSet()
{}

inline std::string DynamicDataSet::E_NullSet::GetExceptionName() const
{
	return "Empty Set";
}

inline std::string DynamicDataSet::E_NullSet::GetExceptionMessage() const
{
	std::stringstream ss;
	ss << GetExceptionName();
	return ss.str();
}

DynamicDataSet::E_InvalidFileFormat::E_InvalidFileFormat(const std::string& p_InvalidToken, const std::string& p_FileName)
	: m_Token(p_InvalidToken),
	m_FileName(p_FileName)
{}

inline std::string DynamicDataSet::E_InvalidFileFormat::GetExceptionName() const
{
	return "Invalid File Format";
}

inline std::string DynamicDataSet::E_InvalidFileFormat::GetExceptionMessage() const
{
	std::stringstream ss;
	ss << GetExceptionName() << " (File \"" << m_FileName << "\" contained an invalid token \"" << m_Token << "\") - Ensure the file contains only digits delimited by spaces";
	return ss.str();
}
