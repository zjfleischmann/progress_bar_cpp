#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class ProgressBar
{
public:
  /* Takes in a char for filling up the bar and the width fo the bar */
  ProgressBar(unsigned int totalWidth);

  /* Fills the bar upto a given number */
  void setPercentage(float pct);

  /* Resets the progress bar */
  void endAndReset();

private:
  unsigned int width = 0;
  unsigned int currentProgressPosition = 1;
  unsigned int progressBarBlocks;
  float percent;
  std::vector<char> bar;
  void setUpBar();
  void displayPercentage(); // Displays the percentage beside the bar
};
