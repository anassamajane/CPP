#include <cctype>
#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac == 1) {
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++) {
		std::string arg = av[i];
		for (size_t j = 0; j < arg.size(); j++) {
			if (std::isalpha(arg[j]))
				arg[j] = std::toupper(arg[j]);
			std::cout << arg[j];
		}
	}
	std::cout << std::endl;
	return (0);
}


