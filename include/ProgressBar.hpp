#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

class ProgressBar
{
	public:
		/* Takes in a char for filling up the bar and the size fo the bar */
		ProgressBar(char notDoneChar, char doneChar, unsigned int size);
		void endAndReset();
		
		/* Fills the bar upto a given number */
		void setPercentage(unsigned int percent);
		
		/* Displays the percentage beside the bar */
		void displayPercentage();

		/* Returns the size of the progress bar */
		unsigned int getSize();

	private:
		unsigned int size = 0;
		unsigned int pos = 1;
		char c;
		char ch;
		std::vector <char> bar;
		void setUpBar();
};
