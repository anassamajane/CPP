#include "Utils.hpp"

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
