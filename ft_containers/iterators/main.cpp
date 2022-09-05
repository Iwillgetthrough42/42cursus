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
        ft::map<int,int> first;

        first[0]=10;
        first[1]=30;
        first[2]=50;
        //first[3]=70;
        ft::map<int, int> mp(first.begin(), first.end());
        //typedef typename ft:: Node<int, int> Node;
}
