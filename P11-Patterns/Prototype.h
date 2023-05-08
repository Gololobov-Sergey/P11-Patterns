#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Animal
{
	string name;
	int* age;

public:
	Animal(string name) : name(name) {}

	virtual ~Animal(){}

	string getName() { return name; }

	void setName(string newName) { name = newName; }

	virtual void print() = 0;

	virtual Animal* clone() = 0;
};


class Cat : public Animal
{
	int* mouse;

public:
	Cat(string name, int mouse) : Animal(name) { this->mouse = new int(mouse); }

	virtual~Cat() { delete mouse; }

	virtual void print() override
	{
		cout << "I`m Cat. My name is " << getName() << endl;
		cout << *mouse << endl;
	}

	virtual Animal* clone() override
	{
		return new Cat(*this);
	}
};


class Dog : public Animal
{
	int* bone;

public:
	Dog(string name) : Animal(name) {}

	virtual void print() override
	{
		cout << "I`m Dog. My name is " << getName() << endl;
	}

	virtual Animal* clone() override
	{
		return new Dog(*this);
	}
};



class PrototypeRegistry
{
	vector<Animal*> items;

public:
	void add(Animal* animal) { items.push_back(animal); }
	Animal* getByName(string name)
	{
		for (Animal* a : items)
		{
			if (a->getName() == name)
				return a->clone();
		}
		return nullptr;
	}
};

void method(Animal* animal)
{
	animal->print();
	Animal* an = animal->clone();
	an->print();
}

//int main()
//{
//	Animal* a1 = new Cat("Tom", 5);
//	Animal* a2 = new Cat("Murka", 10);
//	Animal* a3 = new Dog("Sharik");
//	Animal* a4 = new Dog("Bobik");
//
//	Animal* a5 = a4->clone();
//	a5->setName("Tuzik");
//
//	//a4->print();
//	//a5->print();
//
//	PrototypeRegistry pr;
//	pr.add(a1);
//	pr.add(a2);
//	pr.add(a3);
//	pr.add(a4);
//	pr.add(a5);
//
//	pr.getByName("Sharik")->print();
//
//
//
//	Animal* a6 = pr.getByName("Murka");
//
//	delete a2;
//
//	a6->print();
//
//
//
//	//method(a4);
//}