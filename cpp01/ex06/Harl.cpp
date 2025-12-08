#include "Harl.hpp"

void Harl::debug() {
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";

}

void Harl::info() {
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning() {
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free.\n" ;
    std::cout << "I’ve been coming for years, whereas you started working here just last month.\n\n";
}

void Harl::error() {
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level) {
    int index = -1;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*funcs[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            index = i;
            break;
        }
    }
    switch (index) {
        case 0:
            (this->*funcs[0])();
        case 1:
            (this->*funcs[1])();
        case 2:
            (this->*funcs[2])();
        case 3:
            (this->*funcs[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
}