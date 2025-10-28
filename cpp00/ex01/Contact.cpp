#include "Contact.hpp"

void Contact::set(std::string f, std::string l, std::string n, std::string d, std::string p) {
	first_name = f;
	last_name = l;
	nickname = n;
	darkest_secret = d;
	phone_number = p;
}

std::string Contact::getName() {
	return first_name;
}

std::string Contact::getLast() {
	return last_name;
}

std::string Contact::getNickname() {
	return nickname;
}

std::string Contact::getSecret() {
	return darkest_secret;
}

std::string Contact::getPhone() {
	return phone_number;
}
