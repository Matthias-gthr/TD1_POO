#pragma once
#include <vector>
#include <string>

#include "FlapModule.h"

class FlapDisplay
{
private:
	std::vector <FlapModule> modules;

public:

	FlapDisplay(int size);
	void displayMessage(std::string message);
	std::string currentDisplay();
	bool update();
};

