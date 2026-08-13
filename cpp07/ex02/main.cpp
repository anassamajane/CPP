#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "========== Default Constructor ==========\n";

    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;

    std::cout << "\n========== Constructor with Size ==========\n";

    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";

    std::cout << "\n";

    std::cout << "\n========== Copy Constructor ==========\n";

    Array<int> copy(numbers);

    copy[0] = 999;

    std::cout << "Original: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";

    std::cout << "\nCopy: ";

    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";

    std::cout << "\n";

    std::cout << "\n========== Assignment Operator ==========\n";

    Array<int> assign;

    assign = numbers;

    assign[1] = 555;

    std::cout << "Original: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";

    std::cout << "\nAssigned: ";

    for (unsigned int i = 0; i < assign.size(); i++)
        std::cout << assign[i] << " ";

    std::cout << "\n";

    std::cout << "\n========== Const Array ==========\n";

    const Array<int> constArray(numbers);

    for (unsigned int i = 0; i < constArray.size(); i++)
        std::cout << constArray[i] << " ";

    std::cout << "\n";

    std::cout << "\n========== Out of Bounds ==========\n";

    try
    {
        std::cout << numbers[100] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: index out of bounds." << std::endl;
    }

    std::cout << "\n========== std::string ==========\n";

    Array<std::string> words(3);

    words[0] = "Hello";
    words[1] = "World";
    words[2] = "!";

    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << " ";

    std::cout << "\n";

    return 0;
}