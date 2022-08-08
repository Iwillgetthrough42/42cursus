#include "vector.hpp"
#include "utility.hpp"
#include <vector>

int main()
{
	/*
    ft::vector<int> vec(5, 0);
     for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = 10*i;
    }
    ft::vector<int>::iterator it=vec.erase(vec.begin(), vec.begin() + 2);
    ft::vector<int> v(5, -1);
    vec.insert(vec.begin() + 2, v.begin(), v.begin() + 2);*/
    //std::cout << *it << std::endl;
    /*for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }*/
    ft::vector<int> v(5, 0);
    ft::vector<int>vec(v.begin(), v.end());
    vec.assign(100, 1);
    ft::vector<int>::reverse_iterator it = v.rend() + 1;
}
