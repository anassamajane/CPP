#include "PhoneBook.hpp"
#include "Utils.hpp"

Phonebook::Phonebook() {
	next_idx = 0;
}

void Phonebook::add_contact() {
	std::string f = get_field("First name: ");
	std::string l = get_field("Last name: ");
	std::string n = get_field("Nickname: ");
	std::string d = get_field("Darkest secret: ");
	std::string p;

	while (true) {
		p = get_field("Phone number: ");
		bool valid = true;
		for (size_t i = 0; i < p.size(); i++) {
			if (!std::isdigit(static_cast<unsigned char>(p[i]))) {
				std::cout << "Phone number must contain only digits!\n";
				valid = false;
				break;
			}
		}
		if (valid)
			break;
	}
	contacts[next_idx].set(f, l, n, d, p);
	next_idx = (next_idx + 1) % 8;
	std::cout << "Contact added!" << std::endl;
}

void Phonebook::search_contact() {
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;

	for (int i = 0; i < 8; i++) {
		std::string fn = contacts[i].getName();
		if (fn.empty())
			continue;
		std::string ln = contacts[i].getLast();
		std::string nn = contacts[i].getNickname();

		if (fn.length() > 10) fn = fn.substr(0, 9) + ".";
		if (ln.length() > 10) ln = ln.substr(0, 9) + ".";
		if (nn.length() > 10) nn = nn.substr(0, 9) + ".";

		std::cout << "|         " << i + 1 << "|"
		          << std::setw(10) << fn << "|"
		          << std::setw(10) << ln << "|"
		          << std::setw(10) << nn << "|" << std::endl;
	}
	std::cout << " -------------------------------------------" << std::endl;
}
