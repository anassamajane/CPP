#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

static void printSpanResults(const Span &sp)
{
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
}

static void printNumbers(const std::vector<int> &numbers)
{
    for (std::vector<int>::const_iterator it = numbers.begin();
         it != numbers.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{

    // subject test
    std::cout << "========== Subject Test ==========" << std::endl;

    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    printSpanResults(sp);

  
    // full span
    std::cout << "\n========== Full Span Test ==========" << std::endl;

    try
    {
        sp.addNumber(42);
        std::cout << "ERROR: number was added to a full Span."
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "PASS: " << e.what() << std::endl;
    }

  
    // one element
    std::cout << "\n========== One Element Test ==========" << std::endl;

    Span one(5);
    one.addNumber(42);

    try
    {
        one.shortestSpan();
        std::cout << "ERROR: shortestSpan() should have thrown."
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "PASS shortestSpan(): " << e.what() << std::endl;
    }

    try
    {
        one.longestSpan();
        std::cout << "ERROR: longestSpan() should have thrown."
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "PASS longestSpan(): " << e.what() << std::endl;
    }

   
    // vector
    std::cout << "\n========== Vector Range Test ==========" << std::endl;

    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    std::cout << "Numbers to add: ";
    printNumbers(numbers);

    Span vectorSpan(10);

    try
    {
        vectorSpan.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Successfully added "
                  << numbers.size()
                  << " numbers." << std::endl;

        printSpanResults(vectorSpan);
    }
    catch (const std::exception &e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

 
    // list
    std::cout << "\n========== List Range Test ==========" << std::endl;

    std::list<int> values;

    values.push_back(-100);
    values.push_back(-20);
    values.push_back(0);
    values.push_back(40);
    values.push_back(100);

    Span listSpan(10);

    try
    {
        listSpan.addNumbers(values.begin(), values.end());

        std::cout << "Successfully added "
                  << values.size()
                  << " numbers from a list." << std::endl;

        printSpanResults(listSpan);
    }
    catch (const std::exception &e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    
    // 10000 numbers
    std::cout << "\n========== 10,000 Numbers Test =========="
              << std::endl;

    Span big(10000);

    for (int i = 0; i < 10000; i++)
        big.addNumber(i * 3);

    std::cout << "Added 10,000 numbers successfully." << std::endl;

    std::cout << "Expected shortest span: 3" << std::endl;
    std::cout << "Expected longest span:  29997" << std::endl;

    printSpanResults(big);

    return 0;
}