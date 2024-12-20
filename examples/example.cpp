#include "../include/ProgressBar.hpp"
#include <unistd.h>

unsigned int micros = 1000000; // microseconds to seconds

int main()
{
  ProgressBar foo(100);

  std::cout << "Doing a task" << std::endl;

  for(int i = 0; i <= 100; i++)
  {
    usleep(0.05 * micros); // A delay of 0.1 second(s)

    foo.setPercentage(i);
  }

  for(int j = 0; j <= 100; j++)
  {
    usleep(0.025 * micros); // A delay of 0.1 second(s)
    foo.setPercentage(j);
  }

  std::cout << "Done!" << std::endl;

  return 0;
}
