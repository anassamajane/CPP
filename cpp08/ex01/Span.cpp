#include "Span.hpp"
#include <algorithm>

Span::Span() : _capacity(0)
{
}

Span::Span(unsigned int N) : _capacity(N)
{
}

Span::Span(const Span &other) : _capacity(other._capacity), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _capacity)
        throw SpanFullException();
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int shortest = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++)
    {
        unsigned int span = sorted[i] - sorted[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();
    
    std::vector<int>::const_iterator min;
    std::vector<int>::const_iterator max;

    min = std::min_element(_numbers.begin(), _numbers.end());
    max = std::max_element(_numbers.begin(), _numbers.end());

    return *max - *min;
}

const char *Span::SpanFullException::what() const throw()
{
    return "Span is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to calculate span";
}