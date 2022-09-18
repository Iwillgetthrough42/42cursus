#include "vector.hpp"
#include <vector>
#include <typeinfo>

int main()
{
	ft::vector<int> vec(2, 0);

        //ft::vector<int>::const_iterator ite = vec.end();
        std::cout << typeid(ft::vector<int>::iterator::iterator_category).name()<< std::endl;
}
