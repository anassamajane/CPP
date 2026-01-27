#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "========== FORM CREATION ==========\n";
    try
    {
        Form tax("TaxForm", 50, 30);
        std::cout << tax << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n========== INVALID FORM ==========\n";
    try
    {
        Form bad("BadForm", 0, 200);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n========== SIGN SUCCESS ==========\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        Form contract("Contract", 10, 5);

        std::cout << boss << "\n";
        std::cout << contract << "\n";

        boss.signForm(contract);

        std::cout << contract << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n========== SIGN FAILURE ==========\n";
    try
    {
        Bureaucrat intern("Intern", 150);
        Form secret("SecretForm", 50, 20);

        std::cout << intern << "\n";
        std::cout << secret << "\n";
        intern.signForm(secret);

        std::cout << secret << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}
