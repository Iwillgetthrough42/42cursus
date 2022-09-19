#include "vector.hpp"
#include <vector>
#include <typeinfo>
#include <iostream>

int main()
{
	ft::vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
                vec.push_back(i);
        }
        std::cout << * (vec.end() - 1) << std::endl;
        /*vec.erase(vec.end() - 2, vec.end() - 1);
        for (int i = 0; i < vec.size(); i++)
        {
                std::cout << vec[i] << std::endl;
        }*/

}
