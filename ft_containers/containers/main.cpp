#include "vector.hpp"
#include "utility.hpp"
#include <vector>

int main()
{
    ft::vector<int> v(5, 0);
    std::vector<int> vec(5, 0);
    /*ft::vector<int>vec(v.begin(), v.end());
    vec.assign(100, 1);*/
    vec.reserve(5);
    vec.resize(10, 1);
    v.reserve(5);
    v.resize(2, 1);
    vec.resize(2, 2);
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}
