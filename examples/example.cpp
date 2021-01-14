#include "../include/progress_bar.hpp"
#include <unistd.h>

unsigned int micros = 1000000; // microseconds to seconds

int main()
{
	progressBar foo('.', '#', 30); 

	std::cout << "Doing a task" << std::endl;

	for(int i = 0; i < 29; i++)
	{
		usleep(0.1 * micros); // A delay of 0.1 second(s)
		foo.fillUp();
		foo.displayInfo("One");
		foo.displayInfo("Two");
	}

	foo.end();

	std::cout << "Done!" << std::endl;

	return 0;
}