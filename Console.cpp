#include <string>
#include <iostream>
#include "Console.h"

void Console::clear()
{
	std::cout << "\033[2J";
}

void Console::moveTo(int x, int y)
{
	std::cout << "\033["+ std::to_string(y) + ";" + std::to_string(x) + "H";
}

void Console::textTo(int x, int y, const std::string& texte)
{
	moveTo(x, y);
	std::cout << texte;
}