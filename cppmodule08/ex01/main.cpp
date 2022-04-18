#include "Span.hpp"
#include <iostream>

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6); // 3 6 9 11 17
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::vector<int> vec;
        Span s(100020);
        for (int i = 0; i < 10000; i++)
        {
            vec.push_back(i);
        }
        s.addNumber(vec.begin(), vec.end());
        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}