#pragma once
#include <iostream>


using namespace std;



class Pizza
{
	string name;

public:
	Pizza(string name) : name(name) {}

	virtual~Pizza() {}

	string getName() { return name; }

	virtual int getPrice() = 0;
};



class ItalianPizza : public Pizza
{
public:
	ItalianPizza() : Pizza("Італійська піцца") 	{ }

	virtual int getPrice() override
	{
		return 100;
	}
};


class PizzaDecorator : public Pizza
{
protected:
	Pizza* pizza;

public:
	PizzaDecorator(string nameWrapper, Pizza* pizza) : 
		Pizza(nameWrapper), pizza(pizza)
	{

	}
};


class Tomato : public PizzaDecorator
{
public:
	Tomato(Pizza* pizza) : 
		PizzaDecorator(pizza->getName() + ", з томатами", pizza) {}

	virtual int getPrice() override
	{
		return pizza->getPrice() + 20;
	}
};


class Cheese : public PizzaDecorator
{
public:
	Cheese(Pizza* pizza) :
		PizzaDecorator(pizza->getName() + ", з сиром", pizza) {}

	virtual int getPrice() override
	{
		return pizza->getPrice() + 30;
	}
};



class Becon : public PizzaDecorator
{
public:
	Becon(Pizza* pizza) :
		PizzaDecorator(pizza->getName() + ", з беконом", pizza) {}

	virtual int getPrice() override
	{
		return pizza->getPrice() + 50;
	}
};



//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Pizza* pizza = new ItalianPizza();
//	pizza = new Tomato(pizza);
//	pizza = new Becon(pizza);
//	pizza = new Tomato(pizza);
//	pizza = new Cheese(pizza);
//
//
//	cout << "Pizza : " << pizza->getName() << endl;
//	cout << "Price : " << pizza->getPrice() << endl;
//
//}