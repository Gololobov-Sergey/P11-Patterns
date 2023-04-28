#include <iostream>

#include "Singleton.h"
#include "Prototype.h"

using namespace std;

void method(Animal* animal)
{
	animal->print();
	Animal* an = animal->clone();
	an->print();
}


int main()
{
	Animal* a1 = new Cat("Tom", 5);
	Animal* a2 = new Cat("Murka", 10);
	Animal* a3 = new Dog("Sharik");
	Animal* a4 = new Dog("Bobik");

	Animal* a5 = a4->clone();
	a5->setName("Tuzik");

	//a4->print();
	//a5->print();

	PrototypeRegistry pr;
	pr.add(a1);
	pr.add(a2);
	pr.add(a3);
	pr.add(a4);
	pr.add(a5);

	pr.getByName("Sharik")->print();

	

	Animal* a6 = pr.getByName("Murka");

	delete a2;

	a6->print();



	//method(a4);
}