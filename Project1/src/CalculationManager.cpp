#include "CalculationManager.h"
#include <sstream>
#include <map>
#include <iomanip>

std::string CalculationManager::GetFrequencyTable(const DynamicDataSet& p_DataSet) const
{
    std::stringstream ss;
    std::map<int32_t, size_t> frequencies;

    for (size_t i = 0; i < p_DataSet.GetCount(); i++)
    {
        if (frequencies.find(p_DataSet[i]) != frequencies.end())
            frequencies[p_DataSet[i]]++;
        else
            frequencies[p_DataSet[i]] = 1ui64;
    }

    ss << "\n\t" << std::setw(7) << "Val" << std::setw(7) << "Freq" << std::setw(12) << "Freq (%)" ;

    for (const auto& frequencyPair : frequencies)
        ss << "\n\t" << std::setw(7) << frequencyPair.first << std::setw(7) << frequencyPair.second << std::setw(10) << ((float)frequencyPair.second / (float)p_DataSet.GetCount()) * 100.f << "%";

    return ss.str();

}

CalculationManager::CalculationManager()
	: m_CalcIndex(ECalculationIndex::Min),
	m_Config(ECaluclatorConfig::Population)
{}

void CalculationManager::SetConfig(ECaluclatorConfig p_NewConfig)
{
    m_Config = p_NewConfig;
}

void CalculationManager::SetCalcIndex(ECalculationIndex p_NewIndex)
{
    m_CalcIndex = p_NewIndex;
}

ECalculationIndex CalculationManager::GetCalcIndex() const
{
    return m_CalcIndex;
}

ECaluclatorConfig CalculationManager::GetCalcConfig() const
{
	return m_Config;
}

float CalculationManager::FindMin(const DynamicDataSet& p_DataSet) const
{
	float result = 0;

	if (m_Config == ECaluclatorConfig::Population)
	{
		//result code for population
	}
	else if (m_Config == ECaluclatorConfig::Sample)
	{
		//result code for sample
	}

	return result;
}

float CalculationManager::FindMax(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindRange(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindSize(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindSum(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindMean(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindMedian(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

DynamicDataSet CalculationManager::FindModes(const DynamicDataSet& p_DataSet) const
{
	return DynamicDataSet();
}

float CalculationManager::FindStandardDeviation(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindVariance(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindMidRange(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

std::tuple<float, float, float> CalculationManager::FindQuartiles(const DynamicDataSet& p_DataSet) const
{
	return std::tuple<float, float, float>();
}

float CalculationManager::FindQuartile(EQuartile p_QuartileNum, const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindInterquartileRange(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

DynamicDataSet CalculationManager::FindOutliers(const DynamicDataSet& p_DataSet) const
{
	return DynamicDataSet();
}

float CalculationManager::FindSumOfSquares(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindMeanAbsoluteDeviation(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindRootMeanSquare(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindStandardErrorOfMean(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindSkewness(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindKurtosis(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindKurtosisExcess(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindCoefficientOfVariation(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindRelativeStandardDeviation(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

std::string CalculationManager::GetCalculationResultAsString(ECalculationIndex p_CalculationIndex, const DynamicDataSet& p_DataSet) const
{
	std::stringstream ss;

#ifndef WIDTH
	#define WIDTH 40
#endif

    switch (m_CalcIndex)
    {
	case ECalculationIndex::Min:
		ss << "\n\tMinimum" << std::setw(WIDTH) << " : " << FindMin(p_DataSet);
		break;

	case ECalculationIndex::Max:
		ss << "\n\tMaximum" << std::setw(WIDTH) << " : " << FindMax(p_DataSet);
		break;

	case ECalculationIndex::Range:
		ss << "\n\tRange" << std::setw(WIDTH) << " : " << FindRange(p_DataSet);
		break;

	case ECalculationIndex::Size:
		ss << "\n\tSize" << std::setw(WIDTH) << " : " << FindSize(p_DataSet);
		break;

	case ECalculationIndex::Sum:
		ss << "\n\tSum" << std::setw(WIDTH) << " : " << FindSum(p_DataSet);
		break;

	case ECalculationIndex::Mean:
		ss << "\n\tMean" << std::setw(WIDTH) << " : " << FindSize(p_DataSet);
		break;

	case ECalculationIndex::Median:
		ss << "\n\tMedian" << std::setw(WIDTH) << " : " << FindMedian(p_DataSet);
		break;

	case ECalculationIndex::Mode:
		ss << "\n\tModes" << std::setw(WIDTH) << " : " << FindModes(p_DataSet).to_string();
		break;

	case ECalculationIndex::SDeviation:
		ss << "\n\tStandard Deviation" << std::setw(WIDTH) << " : " << FindStandardDeviation(p_DataSet);
		break;

	case ECalculationIndex::Variance:
		ss << "\n\tVariance" << std::setw(WIDTH) << " : " << FindVariance(p_DataSet);
		break;

	case ECalculationIndex::MidRange:
		ss << "\n\tMid Range" << std::setw(WIDTH) << " : " << FindMidRange(p_DataSet);
		break;

	case ECalculationIndex::Quartiles:
	{
		ss << "\n\tQuartiles" << std::setw(WIDTH) << " : ";
		auto quartiles = FindQuartiles(p_DataSet);
		ss << "Quartile #" << 1 << " : " << std::get<0>(quartiles) << "\n\t" << std::setw(WIDTH) << " : ";
		ss << "Quartile #" << 2 << " : " << std::get<1>(quartiles) << "\n\t" << std::setw(WIDTH) << " : ";
		ss << "Quartile #" << 3 << " : " << std::get<2>(quartiles);
	}
		break;

	case ECalculationIndex::IQRange:
		ss << "\n\tInterquartile Range" << std::setw(WIDTH) << " : " << FindInterquartileRange(p_DataSet);
		break;

	case ECalculationIndex::Outliers:
		ss << "\n\tOutliers" << std::setw(WIDTH) << " : " << FindOutliers(p_DataSet).to_string();
		break;

	case ECalculationIndex::SumOfSquares:
		ss << "\n\tSum Of Squares" << std::setw(WIDTH) << " : " << FindSumOfSquares(p_DataSet);
		break;

	case ECalculationIndex::MADeviation:
		ss << "\n\tMean Absolute Deviation" << std::setw(WIDTH) << " : " << FindMeanAbsoluteDeviation(p_DataSet);
		break;

	case ECalculationIndex::RMSquare:
		ss << "\n\tRoot Mean Square" << std::setw(WIDTH) << " : " << FindRootMeanSquare(p_DataSet);
		break;

	case ECalculationIndex::SErrorOfMean:
		ss << "\n\tStandard Error Of Mean" << std::setw(WIDTH) << " : " << FindStandardErrorOfMean(p_DataSet);
		break;

	case ECalculationIndex::Skewness:
		ss << "\n\tSkewness" << std::setw(WIDTH) << " : " << FindSkewness(p_DataSet);
		break;

	case ECalculationIndex::Kurtosis:
		ss << "\n\tKurtosis" << std::setw(WIDTH) << " : " << FindKurtosis(p_DataSet);
		break;

	case ECalculationIndex::KurtosisExcess:
		ss << "\n\tKurtosis Excess" << std::setw(WIDTH) << " : " << FindKurtosisExcess(p_DataSet);
		break;

	case ECalculationIndex::COVariation:
		ss << "\n\tCoefficient Of Variation" << std::setw(WIDTH) << " : " << FindCoefficientOfVariation(p_DataSet);
		break;

	case ECalculationIndex::RelSDeviation:
		ss << "\n\tRelative Standard Deviation" << std::setw(WIDTH) << " : " << FindRelativeStandardDeviation(p_DataSet);
		break;
    }

    return ss.str();
}

std::string CalculationManager::PrintAllStatistics(const DynamicDataSet& p_DataSet) const
{
	return std::string();
}

void CalculationManager::PrintStatisticsToFile(const std::string& p_FileName, const DynamicDataSet& p_DataSet) const
{
}
