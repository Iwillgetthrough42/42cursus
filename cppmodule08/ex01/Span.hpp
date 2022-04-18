#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
    public:
        Span();
        ~Span();
        Span(unsigned int N);
        Span(Span const &other);
        Span &operator=(Span const &other);
        void addNumber(int number);
        void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
        int shortestSpan() const;
        int longestSpan() const;
    private:
        std::vector<int> span;

};

#endif