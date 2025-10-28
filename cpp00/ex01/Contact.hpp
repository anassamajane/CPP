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
	void set(std::string f, std::string l, std::string n, std::string d, std::string p)
	{
		first_name = f;
		last_name = l;
		nickname = n;
		darkest_secret = d;
		phone_number = p;
	}
	std::string getName() {
		return (first_name);
	}
	std::string getLast() {
		return (last_name);
	}
	std::string getNickname() {
		return (nickname);
	}
	std::string getSecret() {
		return (darkest_secret);
	}
	std::string getPhone() {
		return (phone_number);
	}
};
#endif
