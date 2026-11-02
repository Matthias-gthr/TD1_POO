#include "FlapModule.h"

FlapModule::FlapModule()
{
    // Support uppercase A-Z, lowercase a-z, space and a fallback symbol (178)
    availableSign.resize(54);

    int i = 0;

    for (unsigned char c = 'A'; c <= 'Z'; c++)
    {
        availableSign[i] = c;
        i++;
    }

    availableSign[i++] = ' ';
    availableSign[i++] = 178;

    signToDisplay = 178;

    currentSignIndex = static_cast<int>(availableSign.size()) - 1;
}


unsigned char FlapModule::currentSign() 
{
	return availableSign[currentSignIndex];
}

void FlapModule::display(unsigned char value)
{
	bool found = false;

	for (int i = 0; i < availableSign.size(); i++)
	{
        if (availableSign[i] == value)
        {
            found = true;
        }
	}

	if (found == true)
	{
		signToDisplay = value;
	}

	else
	{
		signToDisplay = 178;
	}
}

bool FlapModule::update()
{
	if (availableSign[currentSignIndex] == signToDisplay)
	{
		return false;
	}

	currentSignIndex++;

    if (currentSignIndex >= static_cast<int>(availableSign.size()))
    {
        currentSignIndex = 0;
    }

	return true;
}