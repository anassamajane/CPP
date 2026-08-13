#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span
{
    private:
        unsigned int _capacity;
        std::vector<int> _numbers;
    
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        template <typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end)
        {
            std::size_t count = std::distance(begin, end);

            if (count > _capacity - _numbers.size())
                throw SpanFullException();
            _numbers.insert(_numbers.end(), begin, end);
        }

        class SpanFullException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif