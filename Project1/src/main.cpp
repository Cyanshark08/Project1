#include "DynamicDataSet.h"
#include "CalculationManager.h"

int main()
{
	DynamicDataSet t;
	t.InsertRandom(50);

	printf("%s", t.to_string().c_str());
	printf("%s", CalculationManager::GetFrequencyTable(t).c_str());
}