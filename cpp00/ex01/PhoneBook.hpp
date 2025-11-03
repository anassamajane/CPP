#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class Phonebook {
private:
	Contact contacts[8];
	int next_idx;
	int num_contacts;

public:
	Phonebook();
	void add_contact();
	void search_contact();
	void display_info();
};
#endif
