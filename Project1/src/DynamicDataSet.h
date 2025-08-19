#pragma once
#include <string>
#include <cstdint>

//Interface class to create exception classes
class ExceptionInterface
{
public:
	std::string Message() const;

private:
	virtual std::string GetExceptionName() const = 0;
	virtual std::string GetExceptionMessage() const = 0;
};

class DynamicDataSet
{

//Public Methods
public:
	DynamicDataSet() = default;

	/*
	* Gets an Element at an Index
	* @param The Index of the Element to Retrieve 
	* @return The Element at the Index
	*/
	int32_t At(size_t p_Index) const;

	/* Inserts a Data Point into the set
	* @param The Data Point to Add
	*/
	void Insert(int32_t p_NewDataPoint);
	
	/*
	* Inserts random values into the set
	* @param Number of Random Values to create
	*/
	void InsertRandom(size_t p_NumOfValues);

	/*
	* Inserts values from a file
	* @param Number of Random Values to create
	* @param
	* NOTE: This function utilizes .txt files
	* hat separate integer values by a
	* ' ' (space) delimiter
	*/
	void InsertFromFile(const std::string& p_FileName);

	/* Deletes an Element at an Index
	* @param The Index of the Element to Delete
	*/
	void DeleteAt(size_t p_Index);

	/* Deletes all elements of a certain value
	* @param The Value of the Elements to Delete
	*/
	void DeleteByValue(int32_t p_Value);

	/*
	* Gets the Frequency of a Value
	* @param The Value to Search for
	* @return The Frequency of a Value
	*/
	size_t NumberOfRecurrences(int32_t p_Value) const;

	/* Get the Amount of Elements in the Set
	* @return The Amount of Elements in the Set
	*/
	size_t GetCount() const;

	/* Get Address of Data Array in Memory
	* @return The Memory Address of Data Array
	*/
	const int32_t* GetAddress() const;

	/* Get Address of Data Array in Memory As String
	* @return The Memory Address of Data Array As a String
	*/
	std::string GetAddressAsString() const;

	/* Return Data Set as String
	* @return The Data Set as a String
	*/
	std::string to_string() const;

	~DynamicDataSet();

//Exception Errors
public:

	// Thrown if the program tries to get an
	// element greater than the size of the array
	class E_OutOfBounds : public ExceptionInterface
	{
	public:
		E_OutOfBounds(size_t p_Index);

	private:
		std::string GetExceptionName() const override;
		std::string GetExceptionMessage() const override;

	private:
		size_t m_Index;
		
	};

	// Thrown if the program tries to operate on
	// an empty (Null) set
	class E_NullSet : public ExceptionInterface
	{
	public:
		E_NullSet();

	private:
		std::string GetExceptionName() const override;
		std::string GetExceptionMessage() const override;
	};

//Overloaded Operators
public:
	int32_t operator[](size_t p_Index) const;
	operator std::string() const;

//Private Members
private:
	int32_t* m_DataPtr = nullptr;
	size_t m_DataCount = 0ui64;

};

