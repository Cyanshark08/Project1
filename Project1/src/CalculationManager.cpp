#include "CalculationManager.h"
#include <sstream>
#include <map>
#include <iomanip>

std::string CalculationManager::GetFrequencyTable(const DynamicDataSet& p_DataSet)
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
