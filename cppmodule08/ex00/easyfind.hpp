#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
template<typename T>

int easyfind(T &container, int param)
{
   typename T::iterator it;

    it = std::find(container.begin(), container.end(), param);
    if (it == container.end())
        throw std::out_of_range("no such element");
    return (it - container.begin());
}

#endif