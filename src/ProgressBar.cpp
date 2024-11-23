#include "../include/ProgressBar.hpp"

#include <math.h>

const unsigned int START_INDEX = 2;
const unsigned int MAX_WIDTH = 200;
const char notDoneChar = ' ';
const char doneChar = '=';

/* Defining the constructor */
ProgressBar::ProgressBar(unsigned int totalWidth)
{
  /* Limit width */
  if(totalWidth > MAX_WIDTH)
  {
    width = MAX_WIDTH;
  }
  else
  {
    width = totalWidth;
  }

  setUpBar();
}

void ProgressBar::setUpBar()
{
  bar.clear();
  bar.push_back(' ');
  bar.push_back('[');

  progressBarBlocks = width         // total width that can be used
                      - START_INDEX // first characters
                      - 5;          // last bracket, space, percentage

  for(unsigned int i = START_INDEX; i < (progressBarBlocks + START_INDEX); i++)
  {
    bar.push_back(notDoneChar);
  }

  bar.push_back(']');
}

/* Defining setPercentage */
void ProgressBar::setPercentage(float pct)
{
  /* Update private variable */
  percent = pct;

  /* Calculate number of blocks to complete */
  float blocks_f = (pct / 100) * (float)progressBarBlocks;
  unsigned int blocks_i = (int)roundf(blocks_f);

  /* Limit to prevent overrun */
  if(blocks_i > progressBarBlocks)
  {
    blocks_i = progressBarBlocks;
  }

  // std::cout<<"NEW"<<std::endl;
  // std::cout<<percent<<std::endl;
  // std::cout<<progressBarBlocks<<std::endl;
  // std::cout<<blocks_f<<std::endl;
  // std::cout<<blocks_i<<std::endl;

  /* Fill in bar */
  for(int i = 0; i < blocks_i; i++)
  {
    if((i == (blocks_i - 1)) && (i < (progressBarBlocks-1)))
    {
      bar[START_INDEX + i] = '>';
    }
    else
    {
      bar[START_INDEX + i] = doneChar;
    }
  }

  /* Print whole vector */
  std::cout << '\r';
  for(int j = 0; j < bar.size(); j++)
  {
    std::cout << bar[j] << std::flush;
  }

  displayPercentage();

  /* Catch 100% */
  if(pct >= 100.0)
  {
    endAndReset();
  }
}

/* Displays the percentage beside the bar */
void ProgressBar::displayPercentage()
{
  std::cout << (int)percent << "%";
}

void ProgressBar::endAndReset()
{
  std::cout << std::endl;
  percent = 0;
  setUpBar();
}
