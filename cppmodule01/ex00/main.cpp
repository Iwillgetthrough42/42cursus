#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony *pony = new Pony(2);
	pony->run();
	pony->eat();
	pony->train();
	delete pony;
}

void ponyOnTheStack()
{
	Pony pony(5);
	pony.run();
	pony.eat();
	pony.train();
}

int main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}