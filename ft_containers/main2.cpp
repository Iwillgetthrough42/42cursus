#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <iostream>

#include "containers/vector.hpp"
#include "containers/map.hpp"
#include "containers/set.hpp"
#include "containers/stack.hpp"

#ifdef STDSTL
    #define TESTED_NAMESPACE std
#else
    #define TESTED_NAMESPACE ft
#endif

void vector_test()
{
    clock_t start;
    
    start = std::clock();
   std::cout << "**************** vector *****************" << std::endl;
   TESTED_NAMESPACE::vector<int> vec(10, 1);
   TESTED_NAMESPACE::vector<int> v(vec);
   TESTED_NAMESPACE::vector<int> vect;
   for (int i = 0; i < 10; i++)
   {
    vect.push_back(i);
   }
   TESTED_NAMESPACE::vector<int> vv(vect.begin(), vect.end());
   vv.erase(vv.begin(), vv.begin() + 2);
   std::cout << "size: " << vv.size() << std::endl;
   std::cout << "capacity: " << vv.capacity() << std::endl;
   for (size_t i = 0; i < vv.size(); i++)
   {
    std::cout << "[" << i << "]" << vv[i] << std::endl;
   }
   std::cout <<"time for vector is: " << std::clock() - start << std::endl;
}

void stack_test()
{
    clock_t start;

    start = std::clock();
    std::cout << "**************** stack ****************" << std::endl;
    TESTED_NAMESPACE::stack<int> stk;
    std::cout <<"is empty: " <<  stk.empty() << std::endl;
    stk.push(1);
    stk.push(42);
    stk.push(35);
    stk.push(100);
    stk.pop();
    std::cout << "added some elements " << std::endl;
    std::cout <<"is empty: " << stk.empty() << std::endl;
    std::cout << "size is: " << stk.size() << std::endl;
    std::cout << "time for stack is: " << std::clock() - start << std::endl;
}

void map_test()
{
    std::cout << "************MAP*************" << std::endl;
    clock_t start = std::clock();
    TESTED_NAMESPACE::map<int, int> mp;
    for (int i = 0; i < 20; i++)
    {
        mp.insert(TESTED_NAMESPACE::make_pair<int, int>(i, 20 - i));
    }
    TESTED_NAMESPACE::map<int, int> other(mp.begin(), mp.end());
    other.erase(other.begin());
    for (TESTED_NAMESPACE::map<int, int>::iterator it \
    =other.begin(); it != other.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    std::cout << "size is: " << other.size() << std::endl;
    std::cout << "isempty: " << other.empty() << std::endl;
    std::cout << "time for map is: " << std::clock() - start << std::endl;
}

void test_set()
{
    std::cout << "*************SET************" << std::endl;
    clock_t start = std::clock();
    TESTED_NAMESPACE::set<int> Set;
    TESTED_NAMESPACE::set<int>::iterator it;

    for (int i = 0; i < 25; i++)
    {
        Set.insert(i);
    }
    it = Set.find(15);
    std::cout<< *it << std::endl;
    Set.erase(Set.begin(), ++(++Set.begin()));
    for (it = Set.begin(); it != Set.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "size is: " << Set.size() << std::endl;
    std::cout << "is empty: "  << Set.empty() << std::endl;
    std::cout << "set time is:  " << std::clock() - start << std::endl;
}

int main()
{
    vector_test();
    stack_test();
    map_test();
    test_set();
}