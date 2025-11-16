#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	next_idx = 0;
	num_contacts = 0;
}

void PhoneBook::add_contact() {
	std::string f = get_field("First name: ");
	std::string l = get_field("Last name: ");
	std::string n = get_field("Nickname: ");
	std::string d = get_field("Darkest secret: ");
	std::string p;

	while (true) {
		p = get_field("Phone number: ");
		bool valid = true;
		for (size_t i = 0; i < p.size(); i++) {
			if (!std::isdigit((p[i]))) {
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
	if (num_contacts < 8)
		num_contacts++;
	std::cout << "Contact added!" << std::endl;
}

void PhoneBook::search_contact() {
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;

	for (int i = 0; i < num_contacts; i++) {
		std::string fn = contacts[i].getName();
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
	if (num_contacts == 0) {
		std::cout << "             No contact available\n";	
		std::cout << " -------------------------------------------" << std::endl;
		return;
	}
	std::cout << " -------------------------------------------" << std::endl;
	display_info();
}

void PhoneBook::display_info() {
	std::string input;
	std::cout << "Enter index to view details: ";
	if (!std::getline(std::cin, input)) {
		std::cout << "\nEOF detected." << std::endl;
		exit(0);
	}
	
	if (input.length() != 1 || !std::isdigit(input[0])) {
		std::cout << "Invalid index.\n";
		return;
	}
	int idx = input[0] - '0';
	if (idx < 1 || idx > num_contacts) {
		std::cout << "Invalid index.\n";
		return;
	}

	Contact c = contacts[idx - 1];
	std::cout << "First name: " << c.getName() << std::endl;
	std::cout << "Last name: " << c.getLast() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Darkest secret: " << c.getSecret() << std::endl;
	std::cout << "Phone number: " << c.getPhone() << std::endl;
}

bool get_input(const std::string &prompt, std::string &out) {
	std::cout << prompt;
	if (!std::getline(std::cin, out)) {
		std::cout << "\nEOF detected." << std::endl;
		exit(0);
	}
	return !out.empty();
}

std::string get_field(const std::string &prompt) {
	std::string input;
	while (true) {
		if (get_input(prompt, input) && !input.empty())
			return input;
		std::cout << "Input cannot be empty, try again!" << std::endl;
	}
}
