#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        return;
    file << "               ,@@@@@@@," << std::endl;
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `88'" << std::endl;
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    file << "       |o|        | |         | |" << std::endl;
    file << "       | |        | |         | |" << std::endl;
    file << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    file.close();
}