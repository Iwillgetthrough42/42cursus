#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span()
{
    this->span.reserve(0);
}

Span::Span(unsigned int N)
{
    this->span.reserve(N);
}

Span::~Span()
{

}

Span::Span(Span const &other)
{
    this->span.reserve(other.span.capacity());
    this->span = other.span;
}

Span &Span::operator=(Span const &other)
{
    this->span.reserve(other.span.capacity());
    this->span = other.span;
    return (*this);
}

 void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    while (first != last)
    {
        addNumber(*first);
        first++;
    }
}

void Span::addNumber(int number)
{
    if (this->span.size() == this->span.capacity())
        throw std::runtime_error("not enough space");
    this->span.push_back(number);
    std::sort(this->span.begin(), this->span.end());
}


int Span::shortestSpan() const
{
    if (this->span.size() < 2)
        throw std::logic_error("not enough numbers");
   int min = this->span[1] - this->span[0];
   for (unsigned int i = 2; i < this->span.size(); i++)
   {
       if (this->span[i] - this->span[i-1] < min)
            min = this->span[i] - this->span[i-1];
   }
   return (min);
}

int Span::longestSpan() const
{
    if (this->span.size() < 2)
        throw std::logic_error("not enough numbers");
    return (this->span.back() - this->span.front());
}