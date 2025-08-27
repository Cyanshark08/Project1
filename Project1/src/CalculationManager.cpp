#include "CalculationManager.h"
#include <sstream>
#include <map>
#include <iomanip>
#include <fstream>
#include <cmath>

#ifndef WIDTH_1
	#define WIDTH_1 30
#endif 


#ifndef WIDTH_2
	#define WIDTH_2 40
#endif

std::string CalculationManager::GetFrequencyTable(const DynamicDataSet& p_DataSet) const
{
	if (p_DataSet.GetCount() <= 1)
		throw CalculationManager::E_InsufficientData();

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

	ss << "\n\t";

    return ss.str();

}

CalculationManager::CalculationManager()
	: m_CalcIndex(ECalculationIndex::Min),
	m_Config(ECalculatorConfig::Sample)
{}

void CalculationManager::SetConfig(ECalculatorConfig p_NewConfig)
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

ECalculatorConfig CalculationManager::GetCalcConfig() const
{
	return m_Config;
}

float CalculationManager::FindMin(const DynamicDataSet& p_DataSet) const
{
	return p_DataSet[0];
}

float CalculationManager::FindMax(const DynamicDataSet& p_DataSet) const
{
	return p_DataSet[p_DataSet.GetCount() - 1];
}

float CalculationManager::FindRange(const DynamicDataSet& p_DataSet) const
{
	return p_DataSet[p_DataSet.GetCount() - 1] - p_DataSet[0];
}

float CalculationManager::FindSize(const DynamicDataSet& p_DataSet) const
{
	return p_DataSet.GetCount();
}

float CalculationManager::FindSum(const DynamicDataSet& p_DataSet) const
{
	float sum = 0.f;

	for (size_t i = 0; i < p_DataSet.GetCount(); i++)
		sum += p_DataSet[i];

	return sum;
}

float CalculationManager::FindMean(const DynamicDataSet& p_DataSet) const
{
	return FindSum(p_DataSet) / FindSize(p_DataSet);
}

float CalculationManager::FindMedian(const DynamicDataSet& p_DataSet) const
{
	float median = 0;
	size_t position = 0;

	if (p_DataSet.GetCount() % 2 != 0) // odd number of elements
	{
		// find the middle of the array
		position = p_DataSet.GetCount() / 2;
		median = p_DataSet.At(position);
	}
	else // even number of elements
	{
		// determine the average of the two middle elements
		position = (p_DataSet.GetCount()) / 2;
		median = (p_DataSet.At(position - 1) + p_DataSet.At(position)) / 2.0;
	}

	return median;
}

DynamicDataSet CalculationManager::FindModes(const DynamicDataSet& p_DataSet) const
{
	DynamicDataSet modes;

	// <digit, frequency> 
	std::map<int32_t, size_t> frequencies;

	// get the frequencies
	for (size_t i = 0, count = p_DataSet.GetCount(); i < count; i++)
	{
		if (frequencies.find(p_DataSet[i]) != frequencies.end())
			frequencies[p_DataSet[i]]++;
		else
			frequencies[p_DataSet[i]] = 1ui64;
	}

	int32_t highestFrequency = 0;
	// find the highest frequency
	for (auto it = frequencies.begin(); it != frequencies.end(); it++)
	{
		// update highestFrequency
		if (it->second > highestFrequency)
			highestFrequency = it->second;
	}

	// insert the numbers with the highest frequency 
	for (auto it = frequencies.begin(); it != frequencies.end(); it++)
	{
		if (it->second == highestFrequency)
			modes.Insert(it->first);
	}

	return modes;
}

float CalculationManager::FindStandardDeviation(const DynamicDataSet& p_DataSet) const
{
	float standardDeviation = 0;
	size_t count = p_DataSet.GetCount();
	float sum = FindSumOfSquares(p_DataSet);

	// determine the standardDeviation
	if (m_Config == ECalculatorConfig::Population)
		standardDeviation = std::sqrt(sum / count);

	else if (m_Config == ECalculatorConfig::Sample)
		standardDeviation = std::sqrt(sum / (count - 1));

	return standardDeviation;
}

float CalculationManager::FindVariance(const DynamicDataSet& p_DataSet) const
{
	return std::pow(FindStandardDeviation(p_DataSet), 2.0);
}

float CalculationManager::FindMidRange(const DynamicDataSet& p_DataSet) const
{
	return (FindMin(p_DataSet) + FindMax(p_DataSet)) / 2.0;
}

std::tuple<float, float, float> CalculationManager::FindQuartiles(const DynamicDataSet& p_DataSet) const
{
	return 
	{ 
		FindQuartile(EQuartile::One, p_DataSet), 
		FindQuartile(EQuartile::Two, p_DataSet), 
		FindQuartile(EQuartile::Three, p_DataSet) 
	};
}

float CalculationManager::FindQuartile(EQuartile p_QuartileNum, const DynamicDataSet& p_DataSet) const
{
	float result = -1;

	switch (p_QuartileNum)
	{
	case EQuartile::One:
		result = FindMedian(p_DataSet.GetSubSet(p_DataSet[0], true, FindMedian(p_DataSet), false));
		break;
	case EQuartile::Two:
		result = FindMedian(p_DataSet);
		break;
	case EQuartile::Three:
		result = FindMedian(p_DataSet.GetSubSet(FindMedian(p_DataSet), false, p_DataSet[p_DataSet.GetCount() - 1], true));
		break;
	}

	return result;
}

float CalculationManager::FindInterquartileRange(const DynamicDataSet& p_DataSet) const
{
	return (FindQuartile(EQuartile::Three, p_DataSet) - FindQuartile(EQuartile::One, p_DataSet));
}

DynamicDataSet CalculationManager::FindOutliers(const DynamicDataSet& p_DataSet) const
{
	return DynamicDataSet();
}

float CalculationManager::FindSumOfSquares(const DynamicDataSet& p_DataSet) const
{
	float sumSquares = 0;
	float mean = FindMean(p_DataSet);

	// calculate the summation
	for (size_t i = 0, count = p_DataSet.GetCount(); i < count; i++)
		sumSquares += std::pow(p_DataSet.At(i) - mean, 2.0);

	return sumSquares;
}

float CalculationManager::FindMeanAbsoluteDeviation(const DynamicDataSet& p_DataSet) const
{
	float meanAbsDev = 0;
	float mean = FindMean(p_DataSet);
	float sum = 0;

	// calculate the summation
	for (size_t i = 0, count = p_DataSet.GetCount(); i < count; i++)
	{
		float temp = std::abs(p_DataSet.At(i) - mean);
		sum += temp;
	}
	meanAbsDev = sum / p_DataSet.GetCount();

	return meanAbsDev;
}

float CalculationManager::FindRootMeanSquare(const DynamicDataSet& p_DataSet) const
{
	float rootMeanSq = 0;
	float sum = 0;

	// calculate the summation
	for (size_t i = 0, count = p_DataSet.GetCount(); i < count; i++)
		sum += std::pow(p_DataSet.At(i), 2.0);

	rootMeanSq = std::sqrt(sum / p_DataSet.GetCount());

	return rootMeanSq;
}

float CalculationManager::FindStandardErrorOfMean(const DynamicDataSet& p_DataSet) const
{
	return FindStandardDeviation(p_DataSet) / std::sqrt(p_DataSet.GetCount());
}

float CalculationManager::FindSkewness(const DynamicDataSet& p_DataSet) const
{
	float skewness = 0;
	float count = p_DataSet.GetCount();
	float mean = FindMean(p_DataSet);
	float sum = 0;

	if (m_Config == ECalculatorConfig::Population)
	{ 
		// calculate the summation
		for (size_t i = 0; i < count; i++)
		{
			float temp = std::pow(p_DataSet.At(i) - mean, 3.0);
			sum += temp;
		}

		// determine the skewness
		skewness = sum / (count * (std::pow(FindStandardDeviation(p_DataSet), 3.0)));
	}
	else if (m_Config == ECalculatorConfig::Sample)
	{
		// calculate the summation
		for (size_t i = 0; i < count; i++)
		{
			float temp = std::pow((p_DataSet.At(i) - mean) / FindStandardDeviation(p_DataSet), 3.0);
			sum += temp;
		}

		// determine the skewness
		skewness = (count / ((count - 1) * (count - 2))) * sum;
	}
	return skewness;
}

float CalculationManager::FindKurtosis(const DynamicDataSet& p_DataSet) const
{
	float kurtosis = 0;
	float count = p_DataSet.GetCount();
	float mean = FindMean(p_DataSet);
	float sum = 0;

	if (m_Config == ECalculatorConfig::Population)
	{
		// calculate the summation
		for (size_t i = 0; i < count; i++)
		{
			float temp = std::pow(p_DataSet.At(i) - mean, 4.0);
			sum += temp;
		}

		// determine the kurtosis
		kurtosis = sum / (count * (std::pow(FindStandardDeviation(p_DataSet), 4.0)));
	}
	else if (m_Config == ECalculatorConfig::Sample)
	{
		// calculate the summation 
		for (size_t i = 0; i < count; i++)
		{
			float temp = std::pow((p_DataSet.At(i) - mean) / FindStandardDeviation(p_DataSet), 4.0);
			sum += temp;
		}

		// determine the skewness
		kurtosis = ((count * (count + 1))/ ((count - 1) * (count - 2) * (count - 3))) * sum;
	}
	return kurtosis;
}

float CalculationManager::FindKurtosisExcess(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

float CalculationManager::FindCoefficientOfVariation(const DynamicDataSet& p_DataSet) const
{
	return FindStandardDeviation(p_DataSet) / FindMean(p_DataSet);
}

float CalculationManager::FindRelativeStandardDeviation(const DynamicDataSet& p_DataSet) const
{
	return 0.0f;
}

std::string CalculationManager::GetCalculationResultAsString(ECalculationIndex p_CalculationIndex, const DynamicDataSet& p_DataSet) const
{

	if (p_DataSet.GetCount() <= 1)
		throw CalculationManager::E_InsufficientData();

	std::stringstream ss;

    switch (p_CalculationIndex)
    {
	case ECalculationIndex::Min:
		ss << "\n\t" << std::setw(WIDTH_1) << "Minimum" << std::setw(WIDTH_2) << " : " << FindMin(p_DataSet);
		break;

	case ECalculationIndex::Max:
		ss << "\n\t" << std::setw(WIDTH_1) << "Maximum" << std::setw(WIDTH_2) << " : " << FindMax(p_DataSet);
		break;

	case ECalculationIndex::Range:
		ss << "\n\t" << std::setw(WIDTH_1) << "Range" << std::setw(WIDTH_2) << " : " << FindRange(p_DataSet);
		break;

	case ECalculationIndex::Size:
		ss << "\n\t" << std::setw(WIDTH_1) << "Size" << std::setw(WIDTH_2) << " : " << FindSize(p_DataSet);
		break;

	case ECalculationIndex::Sum:
		ss << "\n\t" << std::setw(WIDTH_1) << "Sum" << std::setw(WIDTH_2) << " : " << FindSum(p_DataSet);
		break;

	case ECalculationIndex::Mean:
		ss << "\n\t" << std::setw(WIDTH_1) << "Mean" << std::setw(WIDTH_2) << " : " << FindMean(p_DataSet);
		break;

	case ECalculationIndex::Median:
		ss << "\n\t" << std::setw(WIDTH_1) << "Median" << std::setw(WIDTH_2) << " : " << FindMedian(p_DataSet);
		break;

	case ECalculationIndex::Mode:
		ss << "\n\t" << std::setw(WIDTH_1) << "Modes" << std::setw(WIDTH_2) << " : " << FindModes(p_DataSet).to_string();
		break;

	case ECalculationIndex::SDeviation:
		ss << "\n\t" << std::setw(WIDTH_1) << "Standard Deviation" << std::setw(WIDTH_2) << " : " << FindStandardDeviation(p_DataSet);
		break;

	case ECalculationIndex::Variance:
		ss << "\n\t" << std::setw(WIDTH_1) << "Variance" << std::setw(WIDTH_2) << " : " << FindVariance(p_DataSet);
		break;

	case ECalculationIndex::MidRange:
		ss << "\n\t" << std::setw(WIDTH_1) << "Mid Range" << std::setw(WIDTH_2) << " : " << FindMidRange(p_DataSet);
		break;

	case ECalculationIndex::Quartiles:
	{
		ss << "\n\t" << std::setw(WIDTH_1) << "Quartiles" << std::setw(WIDTH_2) << " : ";
		auto quartiles = FindQuartiles(p_DataSet);
		ss << "Quartile #" << 1 << " : " << std::get<(size_t)EQuartile::One>(quartiles);
		ss << "\n\t" << std::setw(WIDTH_1) << " " << std::setw(WIDTH_2)  << " " << "Quartile #" << 2 << " : " << std::get<(size_t)EQuartile::Two>(quartiles);
		ss << "\n\t" << std::setw(WIDTH_1) << " " << std::setw(WIDTH_2)  << " " << "Quartile #" << 3 << " : " << std::get<(size_t)EQuartile::Three>(quartiles);
	}
		break;

	case ECalculationIndex::IQRange:
		ss << "\n\t" << std::setw(WIDTH_1) << "Interquartile Range" << std::setw(WIDTH_2) << " : " << FindInterquartileRange(p_DataSet);
		break;

	case ECalculationIndex::Outliers:
		ss << "\n\t" << std::setw(WIDTH_1) << "Outliers" << std::setw(WIDTH_2) << " : " << FindOutliers(p_DataSet).to_string();
		break;

	case ECalculationIndex::SumOfSquares:
		ss << "\n\t" << std::setw(WIDTH_1) << "Sum Of Squares" << std::setw(WIDTH_2) << " : " << FindSumOfSquares(p_DataSet);
		break;

	case ECalculationIndex::MADeviation:
		ss << "\n\t" << std::setw(WIDTH_1) << "Mean Absolute Deviation" << std::setw(WIDTH_2) << " : " << FindMeanAbsoluteDeviation(p_DataSet);
		break;

	case ECalculationIndex::RMSquare:
		ss << "\n\t" << std::setw(WIDTH_1) << "Root Mean Square" << std::setw(WIDTH_2) << " : " << FindRootMeanSquare(p_DataSet);
		break;

	case ECalculationIndex::SErrorOfMean:
		ss << "\n\t" << std::setw(WIDTH_1) << "Standard Error Of Mean" << std::setw(WIDTH_2) << " : " << FindStandardErrorOfMean(p_DataSet);
		break;

	case ECalculationIndex::Skewness:
		ss << "\n\t" << std::setw(WIDTH_1) << "Skewness" << std::setw(WIDTH_2) << " : " << FindSkewness(p_DataSet);
		break;

	case ECalculationIndex::Kurtosis:
		ss << "\n\t" << std::setw(WIDTH_1) << "Kurtosis" << std::setw(WIDTH_2) << " : " << FindKurtosis(p_DataSet);
		break;

	case ECalculationIndex::KurtosisExcess:
		ss << "\n\t" << std::setw(WIDTH_1) << "Kurtosis Excess" << std::setw(WIDTH_2) << " : " << FindKurtosisExcess(p_DataSet);
		break;

	case ECalculationIndex::COVariation:
		ss << "\n\t" << std::setw(WIDTH_1) << "Coefficient Of Variation" << std::setw(WIDTH_2) << " : " << FindCoefficientOfVariation(p_DataSet);
		break;

	case ECalculationIndex::RelSDeviation:
		ss << "\n\t" << std::setw(WIDTH_1) << "Relative Standard Deviation" << std::setw(WIDTH_2) << " : " << FindRelativeStandardDeviation(p_DataSet);
		break;
	case ECalculationIndex::FreqTable:
		ss << "\n\t" << GetFrequencyTable(p_DataSet).c_str() << "\n\t";
		break;
	default:
		ss << "\n\t" << std::setw(WIDTH_1) << "Calculation Index Error: Index [" << (size_t)p_CalculationIndex << "] is out of range!";
    }

    return ss.str();
}

void CalculationManager::PrintAllStatistics(const DynamicDataSet& p_DataSet) const
{
	for (size_t i = (size_t)ECalculationIndex::Min; i <= (size_t)ECalculationIndex::FreqTable; i++)
		printf("\n\t%s", GetCalculationResultAsString((ECalculationIndex)i, p_DataSet).c_str());
}

void CalculationManager::PrintStatisticsToFile(const std::string& p_FileName, const DynamicDataSet& p_DataSet) const
{
	std::ofstream fileStream(p_FileName.c_str());

	if (fileStream.fail())
	{
		printf("\n\tERROR: file \"%s\" not found!", p_FileName.c_str());
		return;
	}

	for (size_t i = (size_t)ECalculationIndex::Min; i <= (size_t)ECalculationIndex::FreqTable; i++)
		fileStream << "\n\t" << GetCalculationResultAsString((ECalculationIndex)i, p_DataSet).c_str() << "\n\t";

	fileStream.close();

}

CalculationManager::E_InsufficientData::E_InsufficientData()
{}

inline std::string CalculationManager::E_InsufficientData::GetExceptionName() const
{
	return "Insufficient Data";
}

std::string CalculationManager::E_InsufficientData::GetExceptionMessage() const
{
	std::stringstream ss;
	ss << GetExceptionName() << " (Data Set must contain at least 2 or more Elements)";
	return ss.str();
}
