#include "../containers/node.hpp"
#include "../containers/pair.hpp"
#include "../containers/map.hpp"

namespace ft
{
}
int main()
{
        ft::pair<const int, int> pr(5, 5);
        ft::map<const int, int> mp;
        mp.insert(pr);
        //typedef typename ft::Node<int, int> Node;
}
