#pragma once
#include "DynamicDataSet.h"

// hello there
enum class ECalculatorConfig
{
	Population,
	Sample
};

enum class ECalculationIndex
{
	Min = 'A',
	Max = 'B',
	Range = 'C',
	Size = 'D',
	Sum = 'E',
	Mean = 'F',
	Median = 'G',
	Mode = 'H',
	SDeviation = 'I',
	Variance = 'J',
	MidRange = 'K',
	Quartiles = 'L',
	IQRange = 'M',
	Outliers = 'N',
	SumOfSquares = 'O',
	MADeviation = 'P',
	RMSquare = 'Q',
	SErrorOfMean = 'R',
	Skewness = 'S',
	Kurtosis = 'T',
	KurtosisExcess = 'U',
	COVariation = 'V',
	RelSDeviation = 'W',
	FreqTable = 'X',
	DisplayResults = 'Y',
	OutputResultsToFile = 'Z'
};

enum class EQuartile
{
	One,
	Two,
	Three
};

class CalculationManager
{
public:
	/*
	* PreCondition: N/A
	*
	* PostCondition: Initialize the object members
	*/
	CalculationManager();

	/*
	* PreCondition: Calculator configuration is passed
	*
	* PostCondition: change the configuraton to p_NewConfig
	* @param The configuration of the calculator
	*/
	void SetConfig(ECalculatorConfig p_NewConfig);

	/*
	* PreCondition: Index of the calculator is passed
	*
	* PostCondition: set the calculator's index to p_NewIndex
	* @param The index of the calculator
	*/
	void SetCalcIndex(ECalculationIndex p_NewIndex);

	/*
	* PreCondition: N/A
	*
	* PostCondition: Return the calculator's index
	* @return The Calculator's index
	*/
	ECalculationIndex GetCalcIndex() const;

	/*
	* PreCondition: N/A
	*
	* PostCondition: Return the calculator's configuration
	* @return The Calculator's configuration
	*/
	ECalculatorConfig GetCalcConfig() const;

//Calculation Methods

	/*
	* PreCondition: DynamicDataSet object is passed
	* 
	* PostCondition: Return the element at the first index (element with the lowest value)
	* @param The DynamicDataSet to perform calculations on
	* @return The element at the first index
	*/
	float FindMin(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DyanmicDataSet object is passed
	* 
	* PostCondition: Return the element at the last index (element with the greatest value)
	* @param The DynamicDataSet to perform calculations on
	* @return The element at the last index
	*/
	float FindMax(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	* 
	* PostCondition: Return the range
	* @param The DynamicDataSet to perform calculations on
	* @return The Range
	*/
	float FindRange(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	* 
	* PostCondition: Return the number of elements
	* @param The DynamicDataSet to perform calculations on
	* @return The number of elements (size)
	*/
	float FindSize(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	* 
	* PostCondition: Return the sum of all elements
	* @param The DynamicDataSet to perform calculations on
	* @return The sum of all elements
	*/
	float FindSum(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	* 
	* PreCondition: Return the mean (average)
	* @param The DynamicDataSet to perform calculations on
	* @return The mean
	*/
	float FindMean(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	* 
	* PostCondition: Return the median
	* @param The DynamicDataSet to perform calculations on
	* @return The median
	*/
	float FindMedian(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	* 
	* PreCondition: Return a DynamicData Set with the number(s) with the higest frequency (modes)
	* @param The DynamicDataSet to perform calculations on
	* @return A Dynamic DataSet containing the modes
	*/
	DynamicDataSet FindModes(const DynamicDataSet& p_DataSet) const;

	/* 
	* PreCondition: DynamicDataSet object is passed
	* 
	* PostCondition: Return the standard deviation
	* @param The DynamicDataSet to perform calculations on
	* @return The standard deviation
	*/
	float FindStandardDeviation(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the variance
	* @param The DynamicDataSet to perform calculations on
	* @return The variance
	*/
	float FindVariance(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the midrange
	* @param The DynamicDataSet to perform calculations on
	* @return The midrange
	*/
	float FindMidRange(const DynamicDataSet& p_DataSet) const;
	std::tuple<float, float, float> FindQuartiles(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: Quartile (1, 2, or 3) and DynamicDataSet object are passed
	*
	* PostCondition: Return the given quartile
	* @param The DynamicDataSet to perform calculations on
	* @return The Quartile (1, 2, or 3)
	*/
	float FindQuartile(EQuartile p_QuartileNum, const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the interquartile range (range of the quartiles)
	* @param The DynamicDataSet to perform calculations on
	* @return The interquartile range
	*/
	float FindInterquartileRange(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the outliers
	* @param The DynamicDataSet to perform calculations on
	* @return The outliers
	*/
	DynamicDataSet FindOutliers(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the sum of squares
	* @param The DynamicDataSet to perform calculations on
	* @return The sum of squares
	*/
	float FindSumOfSquares(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the mean absolute deviation
	* @param The DynamicDataSet to perform calculations on
	* @return The mean absolute deviation
	*/
	float FindMeanAbsoluteDeviation(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the root mean square
	* @param The DynamicDataSet to perform calculations on
	* @return The root mean square
	*/
	float FindRootMeanSquare(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the standard error of mean
	* @param The DynamicDataSet to perform calculations on
	* @return The standard error of mean
	*/
	float FindStandardErrorOfMean(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the skewness
	* @param The DynamicDataSet to perform calculations on
	* @return The skewness
	*/
	float FindSkewness(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the kurtosis
	* @param The DynamicDataSet to perform calculations on
	* @return The kurtosis
	*/
	float FindKurtosis(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the kurtosis excess
	* @param The DynamicDataSet to perform calculations on
	* @return The kurtosis Excess
	*/
	float FindKurtosisExcess(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the coefficient of variation
	* @param The DynamicDataSet to perform calculations on
	* @return The coefficient of variation
	*/
	float FindCoefficientOfVariation(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return the relative standard deviation
	* @param The DynamicDataSet to perform calculations on
	* @return The relative standard deviation
	*/
	float FindRelativeStandardDeviation(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: DynamicDataSet object is passed
	*
	* PostCondition: Return a string containing the frequency of the values
	* @param The DynamicDataSet to perform calculations on
	* @return A formatted string containing the frequencies
	*/
	std::string GetFrequencyTable(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: User's calculator option and a DynamicDataSet object are passed
	*
	* PostCondition: Return a string containing the result
	* @param The DynamicDataSet to perform calculations on
	* @return A formatted string containing the calculator's result
	*/
	std::string GetCalculationResultAsString(ECalculationIndex p_CalculationIndex, const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: N/A
	*
	* PostCondition: Display all the statistics
	* @param The DynamicDataSet to perform calculations on
	*/
	void PrintAllStatistics(const DynamicDataSet& p_DataSet) const;

	/*
	* PreCondition: File name and DynamicDataSet object are passed
	*
	* PostCondition: Write the statistics to the given file
	* @param The DynamicDataSet to perform calculations on
	*/
	void PrintStatisticsToFile(const std::string& p_FileName, const DynamicDataSet& p_DataSet) const;

public:
	class E_InsufficientData : public ExceptionInterface
	{
	public:
		E_InsufficientData();

	private:
		std::string GetExceptionName() const override;
		std::string GetExceptionMessage() const override;
	};

private:
	ECalculatorConfig m_Config;
	ECalculationIndex m_CalcIndex;

};

