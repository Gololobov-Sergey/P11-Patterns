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