#pragma once
#include "DynamicDataSet.h"

// hello there
enum class ECaluclatorConfig
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
	OutputResults = 'Z'
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

	void SetConfig(ECaluclatorConfig p_NewConfig);
	void SetCalcIndex(ECalculationIndex p_NewIndex);

	ECalculationIndex GetCalcIndex() const;

//Calculation Methods
	float FindMin(const DynamicDataSet& p_DataSet);
	float FindMax(const DynamicDataSet& p_DataSet);
	float FindRange(const DynamicDataSet& p_DataSet);
	float FindSize(const DynamicDataSet& p_DataSet);
	float FindSum(const DynamicDataSet& p_DataSet);
	float FindMean(const DynamicDataSet& p_DataSet);
	float FindMedian(const DynamicDataSet& p_DataSet);
	DynamicDataSet FindMode(const DynamicDataSet& p_DataSet);
	float FindStandardDeviation(const DynamicDataSet& p_DataSet);
	float FindVariance(const DynamicDataSet& p_DataSet);
	float FindMidRange(const DynamicDataSet& p_DataSet);
	std::tuple<float, float, float> FindQuartiles(const DynamicDataSet& p_DataSet);
	float FindQuartile(EQuartile p_QuartileNum, const DynamicDataSet& p_DataSet);
	float FindInterquartileRange(const DynamicDataSet& p_DataSet);
	DynamicDataSet FindOutliers(const DynamicDataSet& p_DataSet);
	float FindSumOfSquares(const DynamicDataSet& p_DataSet);
	float FindMeanAbsoluteDeviation(const DynamicDataSet& p_DataSet);
	float FindRootMeanSquare(const DynamicDataSet& p_DataSet);
	float FindStandardErrorOfMean(const DynamicDataSet& p_DataSet);
	float FindSkewness(const DynamicDataSet& p_DataSet);
	float FindKurtosis(const DynamicDataSet& p_DataSet);
	float FindKurtosisExcess(const DynamicDataSet& p_DataSet);
	float FindCoefficientOfVariation(const DynamicDataSet& p_DataSet);
	float FindRelativeStandardDeviation(const DynamicDataSet& p_DataSet);
	std::string GetFrequencyTable(const DynamicDataSet& p_DataSet);

private:
	ECaluclatorConfig m_Config;
	ECalculationIndex m_CalcIndex;

};

