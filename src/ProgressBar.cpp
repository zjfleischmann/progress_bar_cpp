#include "../include/ProgressBar.hpp"

const unsigned int START_INDEX = 2;

/* Defining the constructor */
ProgressBar::ProgressBar(char notDoneChar, char doneChar, unsigned int size)
    : c(doneChar), ch(notDoneChar), size(size)
{
  if(size <= 100)
  {
    size = size;
  }
  else
  {
    size = 100;
  }

  setUpBar();
}

void ProgressBar::setUpBar()
{
  bar.clear();
  bar.push_back(' ');
  bar.push_back('[');
  for(int i = START_INDEX; i < (size + START_INDEX); i++)
  {
    bar.push_back(ch);
  }

  bar.push_back(']');

  pos = START_INDEX;
}

/* Defining setPercentage */
void ProgressBar::setPercentage(unsigned int percent)
{
  pos = 0;
  for(int i = 1; i < percent; i++)
  {
    bar[i] = c;
    std::cout << '\r';
    for(int j = 0; j < bar.size(); j++)
    {
      std::cout << bar[j] << std::flush;
    }
  }
  pos += percent;

  displayPercentage();
}


/* Displays the percentage beside the bar */
void ProgressBar::displayPercentage()
{
  float percent = ((float)pos / (float)(bar.size() - 1)) * 100;
  std::cout << (int)percent << "%";
}

/* Returns the size of the progress bar */
unsigned int ProgressBar::getSize()
{
  return bar.size() - 2;
}

void ProgressBar::endAndReset()
{
  std::cout << std::endl;
  pos = 1;
  setUpBar();
}
