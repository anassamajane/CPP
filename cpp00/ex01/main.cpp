#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook pb;
	std::string command;

	std::cout << "Please enter: ADD or SEARCH or EXIT\n";
	while (true)
	{
		std::cout << "Enter Command: ";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEOF" << std::endl;
			break;
		}
		if (command == "ADD")
			pb.add_contact();
		else if (command == "SEARCH")
			pb.search_contact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}

