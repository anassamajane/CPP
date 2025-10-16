#include <cctype>
#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	int	idx;
	int	j;

	idx = 0;
	j = 1;
	while (j < ac)
	{
		idx = 0;
		while (av[j][idx])
		{
			if (islower(av[j][idx]))
			{
				av[j][idx] -= 32;
				std::cout<<(av[j][idx]);
			}
			else
				std::cout<<av[j][idx];
			idx++;
		}
		j++;
	}
	if (ac == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return 1;
	}
	std::cout<<"\n";
}


