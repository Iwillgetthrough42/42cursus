#include "../containers/node.hpp"
#include "../containers/pair.hpp"
#include "../containers/map.hpp"
#include "../containers/vector.hpp"
#include "../containers/stack.hpp"
#include <vector>
#include <map>
#include <list>
#include <iostream>

namespace ft
{
}
int main()
{
        ft::stack<int> stk;
        ft::vector<int> deque;
        for (int i = 0; i < 100 * 10000; ++i)
		deque.push_back(i);
	for (int i = 100 * 10000; i < 200 * 10000; ++i)
		stk.push(i);
	ft::stack<int> stack(deque);
        system("leaks a.out");
}
