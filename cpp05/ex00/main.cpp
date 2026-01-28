#include "Bureaucrat.hpp"

int main() 
{
    std::cout << "========== VALID ==========\n";
    try
    {
        Bureaucrat a("Jack", 102);
        std::cout << a << "\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n========== INVALID ==========\n";
    try
    {
        Bureaucrat b("Bad", 0);    
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat c("Worse", 151);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << "\n========== INCREMENT ==========\n";
    try
    {
        Bureaucrat d("Trump", 2);
        std::cout << d << "\n";
        d.incrementGrade();
        std::cout << d << "\n";
        d.incrementGrade();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << "\n========== DECREMENT ==========\n";
    try
    {
        Bureaucrat f("Bob", 149);
        std::cout << f << "\n";
        f.decrementGrade();
        std::cout << f << "\n";
        f.decrementGrade();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}