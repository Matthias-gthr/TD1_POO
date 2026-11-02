#include "FlapDisplay.h"
#include <string>
#include <vector>

FlapDisplay::FlapDisplay(int size)
{
	modules.resize(size);
}

void FlapDisplay::displayMessage(std::string message)
{
    for (int i = 0; i < modules.size(); i++)
	{
        if (i < message.length()) 
        {
            unsigned char ch = static_cast<unsigned char>(message[i]);
            modules[i].display(ch);
        }

		else
		{
			modules[i].display(' ');
		}
	}
}

std::string FlapDisplay::currentDisplay()
{
	std::string texte = "";

	for (int i = 0; i < modules.size(); i++)
	{
		texte += modules[i].currentSign();
	}

	return texte;
}

bool FlapDisplay::update()
{
	bool atLeastOneChange = false;

	for (int i = 0; i < modules.size(); i++)
	{
		bool move = modules[i].update();

		if (move == true)
		{
			atLeastOneChange = true;
		}
	}

	return atLeastOneChange;
}