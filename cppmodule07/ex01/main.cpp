#include "iter.hpp"
#include <iostream>

void print(int a)
{
	std::cout << a << std::endl;
}

int main()
{
	int arr[] = {1, 5, 6};
	iter<int>(arr, 3, &print);

}