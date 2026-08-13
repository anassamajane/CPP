#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void testVector()
{
    std::cout << "========== VECTOR ==========" << std::endl;

    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(20);
    numbers.push_back(40);

    try
    {
        std::vector<int>::const_iterator it = easyfind(numbers, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "20 not found" << std::endl;
    }

    try
    {
        std::vector<int>::const_iterator it = easyfind(numbers, 40);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "40 not found" << std::endl;
    }

    try
    {
        std::vector<int>::const_iterator it = easyfind(numbers, 99);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "99 not found" << std::endl;
    }
}

void testList()
{
    std::cout << "\n========== LIST ==========" << std::endl;

    std::list<int> numbers;

    numbers.push_back(5);
    numbers.push_back(15);
    numbers.push_back(25);
    numbers.push_back(15);

    try
    {
        std::list<int>::const_iterator it = easyfind(numbers, 15);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "15 not found" << std::endl;
    }

    try
    {
        std::list<int>::const_iterator it = easyfind(numbers, 100);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "100 not found" << std::endl;
    }
}

void testDeque()
{
    std::cout << "\n========== DEQUE ==========" << std::endl;

    std::deque<int> numbers;

    numbers.push_back(100);
    numbers.push_back(200);
    numbers.push_back(300);
    numbers.push_back(200);

    try
    {
        std::deque<int>::const_iterator it = easyfind(numbers, 200);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "200 not found" << std::endl;
    }
}

void testEmptyVector()
{
    std::cout << "\n========== EMPTY VECTOR ==========" << std::endl;

    std::vector<int> numbers;

    try
    {
        std::vector<int>::const_iterator it = easyfind(numbers, 42);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "42 not found" << std::endl;
    }
}

int main()
{
    testVector();
    testList();
    testDeque();
    testEmptyVector();

    return 0;
}