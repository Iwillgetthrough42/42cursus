#include "../containers/node.hpp"
#include "../containers/pair.hpp"
#include "../containers/map.hpp"
#include <vector>
#include <map>
#include <list>
#include <iostream>

namespace ft
{
}
int main()
{
        std::list<ft::pair<const int, int>> lst;
        //std::list<std::pair<const int, int>>::iterator it = lst.begin();
        //std::list<std::pair<const int, int>>::iterator ite = lst.end();
        for (int i = 0; i < 7; i++ )
                lst.push_back(ft::pair<const int, int>(6 - i, i));
        ft::map<const int, int> mp(lst.begin(), lst.end());

       std::cout << (mp.at(0))<< std::endl;

}
