#pragma once
#include <string>
#include <iostream>

class Console
{
public:

	void clear();
	void moveTo(int x, int y);
	void textTo(int x, int y, const std::string& texte);


};