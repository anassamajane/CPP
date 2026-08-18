#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

class RPN
{
    private:
        std::stack<int> _stack;
    
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int evaluate(const std::string &expression);

        class InvalidExpressionException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif