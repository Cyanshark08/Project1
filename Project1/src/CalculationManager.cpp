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

std::string CalculationManager::GetCalculationResultAsString(ECalculationIndex p_CalculationIndex, const DynamicDataSet& p_DataSet) const
{
	std::stringstream ss;

#define WIDTH 40

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

		break;

	case ECalculationIndex::Mean:

		break;

	case ECalculationIndex::Median:

		break;

	case ECalculationIndex::Mode:

		break;

	case ECalculationIndex::SDeviation:

		break;

	case ECalculationIndex::Variance:

		break;

	case ECalculationIndex::MidRange:

		break;

	case ECalculationIndex::Quartiles:

		break;

	case ECalculationIndex::IQRange:

		break;

	case ECalculationIndex::Outliers:

		break;

	case ECalculationIndex::SumOfSquares:

		break;

	case ECalculationIndex::MADeviation:

		break;

	case ECalculationIndex::RMSquare:

		break;

	case ECalculationIndex::SErrorOfMean:

		break;

	case ECalculationIndex::Skewness:

		break;

	case ECalculationIndex::Kurtosis:

		break;

	case ECalculationIndex::KurtosisExcess:

		break;

	case ECalculationIndex::COVariation:

		break;

	case ECalculationIndex::RelSDeviation:

		break;
    }

    return ss.str();
}
