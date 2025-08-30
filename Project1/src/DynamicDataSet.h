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

	//Default Constructor
	DynamicDataSet() = default;

	/*
	* PreCondition: Another DynamicDataSet is passed 
	* 
	* PostCondition: Deep copy the values of the other DynamicDataSet
	* @param Valid DynamicDataSet is passed
	* @return Copied DynamicDataSet
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
	* PostCondition: Inserts tokens from [s] as long as they remain valid integers; returns num of integers read
	* @param Name of File to read from
	* @return Number of elements read from file
	* 
	* NOTE: This function utilizes .txt files
	* that separate + or - integer values with a
	* ' ' (space) delimiter
	*/
	size_t InsertFromFile(const std::string& p_FileName);

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

	/* 
	* PreCondition: p_InitialIndex and p_FinalIndex must be valid indices within the Dataset
	* 
	* PostConditon: Return a data set with numbers between p_InitialIndex and p_FinalIndex
	* @param The Initial and Final Index of the SubSet
	* @return A Data Set with the values between the Initial and Final Index
	*/
	DynamicDataSet GetSubSet(size_t p_InitialIndex, size_t p_FinalIndex) const;

	/*
	* PreCondition: LowerBound and UpperBound must be positive float values within the set. Valid Boolean statements to determine
	* if the lowerBound and UpperBound will be included in the data set.
	* 
	* PostCondition: Return a data set with numbers between (or including) the Lowerbound and UpperBound
	* @param The LowerBound and UpperBound of the data set. Boolean statements to include the LowerBound and UpperBound
	* @return a data set containing values between the LowerBound and UpperBound (or including them too)
	*/
	DynamicDataSet GetSubSet(float p_LowerBound, bool p_IncludeLower, size_t p_UpperBound, bool p_IncludeUpper) const;

	/*
	* PreCondition: Condition to determine if the element should be included in the dataset
	* 
	* PostCondition: Return a data set with all values that meet the condition
	* @param The condition to insert elements into the data set
	* @return A data set with all elements that meet the condition
	*/
	DynamicDataSet GetSubSet(bool (*p_ElementCondition)(float)) const;

	/*
	* PreCondition: Condition to determine if the element at the index should be included in the dataset
	* 
	* PostCondition: Return a data set with all the values that meet the condition
	* @param The condition to insert elements into the dataset
	* @return A data set containing all elements that meet the condition
	*/
	DynamicDataSet GetSubSet(bool (*p_IndexCondition)(size_t)) const;

	/* Get the Amount of Elements in the Set
	* @return The Amount of Elements in the Set
	*/
	size_t GetCount() const;

	/* Determine if the dataset is empty
	* @return true if the size = 0, otherwise return false
	* 
	*/
	bool IsEmpty() const;

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

	bool isEven() const;

	bool isOdd() const;


	std::string to_string(size_t p_Width, bool p_IgnoreInitialLine) const;

	std::string to_string(size_t p_Width, size_t p_LineWidth, bool p_IgnoreInitialLine) const;

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

