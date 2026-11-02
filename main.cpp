#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "Console.h"
#include "FlapModule.h"
#include "FlapDisplay.h"

int main()
{
	/*
	std::cout << "Chargement en cours." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Chargement termine." << std::endl;

	std::cout << "Chargement en cours" << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		int numDots = (i % 3) + 1;

		for (int j = 0; j < numDots; j++)
			std::cout << ".";

		std::cout << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::cout << "Chargement termine." << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		std::cout << "\rChargement en cours   \rChargement en cours";
		int numDots = (i % 3) + 1;

		for (int j = 0; j < numDots; j++)
			std::cout << ".";

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::cout << std::endl;

	std::cout << "Chargement termine." << std::endl;

	Console console;

	console.textTo(2, 2, "Bonjour");
	std::this_thread::sleep_for(std::chrono::seconds(4));
	console.clear();
	
	Console console;

	console.clear();

	FlapModule monModule;

	monModule.display('H');

	bool isRunning = true;

	while (isRunning == true)
	{
		unsigned char lettre = monModule.currentSign();

		std::string texte = "";
		texte += lettre;

		console.textTo(10, 0, texte);
		isRunning = monModule.update();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	*/
	Console console;
	console.clear();

	FlapDisplay myPanel(30);

	myPanel.displayMessage("BIENVENUE A POLYTECH");

	bool running = true;
	while (running == true)
	{
		console.textTo(5, 5, myPanel.currentDisplay());

		running = myPanel.update();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	std::this_thread::sleep_for(std::chrono::seconds(3));

	return 0;
}