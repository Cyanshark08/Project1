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
	* 
	* 
	* 
	* 
	*/
	DynamicDataSet(const DynamicDataSet& p_Other);

	/*
	* PreCondition: A positive Index less than the Count
	* 
	* PostCondition: Returns the Element at that Index
	* @param The Index of the Element to Retrieve 
	* @return The Element at the Index
	*/
	int32_t At(size_t p_Index) const;

	/* 
	* PreCondition: An integer value
	* 
	* PostCondition: Inserts the value (sorted) into the data set
	* @param The Data Point to Add
	*/
	void Insert(int32_t p_NewDataPoint);
	
	/*
	* PreCondition: A positive integer value [n]
	* 
	* PostCondition: Inserts [n] random values into the set
	* @param Number of Random Values to create
	*/
	void InsertRandom(size_t p_NumOfValues);

	/*
	* PreCondition: A valid filename [s] as an std::string (ensure valid file format)
	* 
	* PostCondition: Inserts tokens from [s] as long as they remain valid integers
	* @param Number of Random Values to create
	* 
	* NOTE: This function utilizes .txt files
	* that separate + or - integer values with a
	* ' ' (space) delimiter
	*/
	void InsertFromFile(const std::string& p_FileName);

	/* 
	* PreCondition: A + integer value [n] smaller than the Count
	* 
	* PostCondition: Deletes the element at index [n]
	* @param The Index of the Element to Delete
	*/
	void DeleteAt(size_t p_Index);

	/*
	* PreCondition: An integer value [n] and a flag [f] that indicate whether to delete all values of [n] or the first instance of [n]
	* 
	* PostCondition: Returns a positive integer that indicates the amount of instances of [n] deleted
	* @param The Value of the Elements to Delete and a flag indicating whether to delete all values or the first instance
	* @return Number of Instances Deleted
	*/
	size_t DeleteByValue(int32_t p_Value, bool p_DeleteAll);

	/*
	* PreCondition: An integer value [n]
	* 
	* PostCondition: Returns a positive integer that indicates the number of instances of [n]
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

	void Clean();

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

	class E_InvalidFileFormat : public ExceptionInterface
	{
	public:
		E_InvalidFileFormat(const std::string& p_InvalidToken, const std::string& p_FileName);

	private:
		std::string GetExceptionName() const override;
		std::string GetExceptionMessage() const override;

	private:
		std::string m_Token;
		std::string m_FileName;
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

