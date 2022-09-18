#include "../containers/node.hpp"
#include "../containers/pair.hpp"
#include "../containers/map.hpp"
#include "../containers/vector.hpp"
#include <vector>
#include <map>
#include <list>
#include <iostream>

namespace ft
{
}
int main()
{
        std::list<int> lst;
        //std::list<std::pair<const int, int>>::iterator it = lst.begin();
        //std::list<std::pair<const int, int>>::iterator ite = lst.end();
        for (int i = 0; i < 7; i++ )
                lst.push_back(i);
        ft::vector<int> vec(2, 1);
        vec.insert(vec.begin() + 1, lst.begin(), lst.end());
        vec.erase(vec.begin(), vec.end());

}
