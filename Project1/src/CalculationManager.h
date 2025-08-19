#pragma once
#include "DynamicDataSet.h"

// hello there
enum class ECaluclatorState
{
	Population,
	Sample
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
	static float FindMin(const DynamicDataSet& p_DataSet);
	static float FindMax(const DynamicDataSet& p_DataSet);
	static float FindRange(const DynamicDataSet& p_DataSet);
	static float FindSize(const DynamicDataSet& p_DataSet);
	static float FindSum(const DynamicDataSet& p_DataSet);
	static float FindMean(const DynamicDataSet& p_DataSet);
	static float FindMedian(const DynamicDataSet& p_DataSet);
	static DynamicDataSet FindMode(const DynamicDataSet& p_DataSet);
	static float FindStandardDeviation(const DynamicDataSet& p_DataSet);
	static float FindVariance(const DynamicDataSet& p_DataSet);
	static float FindMidRange(const DynamicDataSet& p_DataSet);
	static std::tuple<float, float, float> FindQuartiles(const DynamicDataSet& p_DataSet);
	static float FindInterquartileRange(const DynamicDataSet& p_DataSet);
	static DynamicDataSet FindOutliers(const DynamicDataSet& p_DataSet);
	static float FindSumOfSquares(const DynamicDataSet& p_DataSet);
	static float FindMeanAbsoluteDeviation(const DynamicDataSet& p_DataSet);
	static float FindRootMeanSquare(const DynamicDataSet& p_DataSet);
	static float FindStandardErrorOfMean(const DynamicDataSet& p_DataSet);
	static float FindSkewness(const DynamicDataSet& p_DataSet);
	static float FindKurtosis(const DynamicDataSet& p_DataSet);
	static float FindKurtosisExcess(const DynamicDataSet& p_DataSet);
	static float FindCoefficientOfVariation(const DynamicDataSet& p_DataSet);
	static float FindRelativeStandardDeviation(const DynamicDataSet& p_DataSet);
	static std::string GetFrequencyTable(const DynamicDataSet& p_DataSet);

private:
	static ECaluclatorState s_State;

};

