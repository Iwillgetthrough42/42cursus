#include "vector.hpp"

int main()
{
    ft::vector<int> vec(5, 0);
    vec.insert(vec.begin() + 2, 3);
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}