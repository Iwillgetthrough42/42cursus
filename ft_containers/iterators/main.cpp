#include "../containers/node.hpp"
#include "../containers/pair.hpp"
#include "../containers/map.hpp"
#include <vector>
#include <map>
#include <list>

namespace ft
{
}
int main()
{
        std::list<ft::pair<const int, int>> lst;
        //std::list<std::pair<const int, int>>::iterator it = lst.begin();
        //std::list<std::pair<const int, int>>::iterator ite = lst.end();
        for (int i = 0; i < 7; i++ )
                lst.push_back(ft::pair<const int, int>(i, i));
        ft::map<const int, int> mp(lst.begin(), lst.end());

       //ft::map<const int, int> mp2(mp.begin(), mp.end());
        mp.erase(mp.begin(), ++(++(++mp.begin())));
        ft::map<const int, int>::iterator it = mp.begin();
        ft::map<const int, int>::iterator ite = mp.end();
        while (it != ite)
        {
                std::cout << (*it).first << std::endl;
                it++;
        }

}
