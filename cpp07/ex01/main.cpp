#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(const int &x)
{
    std::cout << x << " ";
}

void increment(int &x)
{
    x++;
}

void printString(const std::string &str)
{
    std::cout << str << " ";
}

int main()
{
    std::cout << "===== Test 1 : Modify int array =====" << std::endl;

    int numbers[] = {1, 2, 3, 4, 5};

    iter(numbers, 5, increment);

    iter(numbers, 5, printInt);

    std::cout << std::endl << std::endl;

    std::cout << "===== Test 2 : Const int array =====" << std::endl;

    const int values[] = {10, 20, 30, 40};

    iter(values, 4, printInt);

    std::cout << std::endl << std::endl;

    std::cout << "===== Test 3 : String array =====" << std::endl;

    std::string words[] = {"Hello", "World", "!"};

    iter(words, 3, printString);

    std::cout << std::endl;

    return 0;
}