#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <string>

void separator(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("Subject Test");

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Elements: ";

    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << std::endl;

    std::stack<int> standardStack(mstack);

    std::cout << "std::stack top: "
              << standardStack.top() << std::endl;


    separator("Iterator Traversal");

    MutantStack<int> numbers;

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    numbers.push(40);
    numbers.push(50);

    std::cout << "Elements: ";

    for (MutantStack<int>::iterator iter = numbers.begin();
         iter != numbers.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;


    separator("Iterator Modification");

    MutantStack<int>::iterator modify = numbers.begin();

    *modify = 999;

    std::cout << "After modifying first element: ";

    for (MutantStack<int>::iterator iter = numbers.begin();
         iter != numbers.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;


    separator("Const Iterator");

    const MutantStack<int> constNumbers(numbers);

    MutantStack<int>::const_iterator cit = constNumbers.begin();
    MutantStack<int>::const_iterator cite = constNumbers.end();

    std::cout << "Const elements: ";

    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }

    std::cout << std::endl;


    separator("Copy Constructor");

    MutantStack<int> copy(numbers);

    std::cout << "Original: ";

    for (MutantStack<int>::iterator iter = numbers.begin();
         iter != numbers.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    std::cout << "Copy: ";

    for (MutantStack<int>::iterator iter = copy.begin();
         iter != copy.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    copy.push(1000);

    std::cout << "Original size: "
              << numbers.size()
              << std::endl;

    std::cout << "Copy size: "
              << copy.size()
              << std::endl;


    separator("Assignment Operator");

    MutantStack<int> assigned;

    assigned = numbers;

    std::cout << "Assigned: ";

    for (MutantStack<int>::iterator iter = assigned.begin();
         iter != assigned.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    assigned.push(2000);

    std::cout << "Original size: "
              << numbers.size()
              << std::endl;

    std::cout << "Assigned size: "
              << assigned.size()
              << std::endl;


    separator("std::list Comparison");

    MutantStack<int> mutant;

    mutant.push(1);
    mutant.push(2);
    mutant.push(3);
    mutant.push(4);
    mutant.push(5);

    std::list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    std::cout << "MutantStack: ";

    for (MutantStack<int>::iterator iter = mutant.begin();
         iter != mutant.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    std::cout << "std::list:    ";

    for (std::list<int>::iterator iter = list.begin();
         iter != list.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;


    separator("String Test");

    MutantStack<std::string> words;

    words.push("Hello");
    words.push("from");
    words.push("MutantStack");

    std::cout << "Words: ";

    for (MutantStack<std::string>::iterator iter = words.begin();
         iter != words.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    std::cout << "Top: "
              << words.top()
              << std::endl;

    return 0;
}