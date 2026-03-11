#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	RPN r;

	try {
		int result = r.evaluate(av[1]);
		std::cout << result << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
