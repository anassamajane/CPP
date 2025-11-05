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
#endif
