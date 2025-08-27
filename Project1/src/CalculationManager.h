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

	CalculationManager();

	void SetConfig(ECalculatorConfig p_NewConfig);
	void SetCalcIndex(ECalculationIndex p_NewIndex);

	ECalculationIndex GetCalcIndex() const;
	ECalculatorConfig GetCalcConfig() const;

//Calculation Methods

	/*
	* PostCondition: 
	* 
	* PreCondition: 
	* 
	* @param
	* @return
	* 
	*/
	float FindMin(const DynamicDataSet& p_DataSet) const;
	float FindMax(const DynamicDataSet& p_DataSet) const;
	float FindRange(const DynamicDataSet& p_DataSet) const;
	float FindSize(const DynamicDataSet& p_DataSet) const;
	float FindSum(const DynamicDataSet& p_DataSet) const;
	float FindMean(const DynamicDataSet& p_DataSet) const;
	float FindMedian(const DynamicDataSet& p_DataSet) const;
	DynamicDataSet FindModes(const DynamicDataSet& p_DataSet) const;
	float FindStandardDeviation(const DynamicDataSet& p_DataSet) const;
	float FindVariance(const DynamicDataSet& p_DataSet) const;
	float FindMidRange(const DynamicDataSet& p_DataSet) const;
	std::tuple<float, float, float> FindQuartiles(const DynamicDataSet& p_DataSet) const;
	float FindQuartile(EQuartile p_QuartileNum, const DynamicDataSet& p_DataSet) const;
	float FindInterquartileRange(const DynamicDataSet& p_DataSet) const;
	DynamicDataSet FindOutliers(const DynamicDataSet& p_DataSet) const;
	float FindSumOfSquares(const DynamicDataSet& p_DataSet) const;
	float FindMeanAbsoluteDeviation(const DynamicDataSet& p_DataSet) const;
	float FindRootMeanSquare(const DynamicDataSet& p_DataSet) const;
	float FindStandardErrorOfMean(const DynamicDataSet& p_DataSet) const;
	float FindSkewness(const DynamicDataSet& p_DataSet) const;
	float FindKurtosis(const DynamicDataSet& p_DataSet) const;
	float FindKurtosisExcess(const DynamicDataSet& p_DataSet) const;
	float FindCoefficientOfVariation(const DynamicDataSet& p_DataSet) const;
	float FindRelativeStandardDeviation(const DynamicDataSet& p_DataSet) const;

	std::string GetFrequencyTable(const DynamicDataSet& p_DataSet) const;
	std::string GetCalculationResultAsString(ECalculationIndex p_CalculationIndex, const DynamicDataSet& p_DataSet) const;
	void PrintAllStatistics(const DynamicDataSet& p_DataSet) const;
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

