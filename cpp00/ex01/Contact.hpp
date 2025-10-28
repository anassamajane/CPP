#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	std::string phone_number;

public:
	void set(std::string f, std::string l, std::string n, std::string d, std::string p);
	std::string getName();
	std::string getLast();
	std::string getNickname();
	std::string getSecret();
	std::string getPhone();
};

#endif
