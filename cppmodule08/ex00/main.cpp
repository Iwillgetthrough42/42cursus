#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(4);
    try
    {
       int found =  easyfind(vec, 0);
        std::cout << found << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}