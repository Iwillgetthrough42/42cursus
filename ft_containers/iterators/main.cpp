#include "../containers/node.hpp"
#include "../containers/pair.hpp"
#include "../containers/map.hpp"
#include <vector>
#include <map>

namespace ft
{
}
int main()
{
        std::map<int,int> first;

        first[0]=10;
        first[1]=30;
        first[2]=50;
        first[3]=70;
        first[4]=20;
        first[5] = 5;

        std::cout << first[2] << std::endl;
        /*ft::map<int,int>::iterator it = first.begin();
        ft::map<int,int>::iterator ite = first.end();
        ft::map<int, int> mp(it, ite);*/

        //typedef typename ft:: Node<int, int> Node;
}
