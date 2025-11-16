#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int next_idx;
	int num_contacts;

public:
	PhoneBook();
	void add_contact();
	void search_contact();
	void display_info();
};

bool get_input(const std::string &prompt, std::string &out);
std::string get_field(const std::string &prompt);

#endif
