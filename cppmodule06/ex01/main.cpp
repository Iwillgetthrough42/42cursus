#include <iostream>
#include "data.hpp"
#include <stdint.h>

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}


int main()
{
	Data d;
	d.num = 5;
	d.f = 25.3;
	std::cout << &d << std::endl;
	uintptr_t ptr = serialize(&d);
	std::cout << ptr << std::endl;
	Data*p = deserialize(ptr);
	std::cout << p << std::endl;

}