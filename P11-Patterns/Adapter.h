#pragma once
#include <iostream>


using namespace std;


class ITransport
{
public:
	virtual void drive() = 0;
};


class Auto : public ITransport
{
public:
	virtual void drive() override
	{
		cout << "Автівка їде по дорозі" << endl;
	}
};


class Traveler
{
public:
	void travel(ITransport* transport)
	{
		transport->drive();
	}
};


class Camel
{
public:
	void move()
	{
		cout << "Верблюд іде по пустелі" << endl;
	}
};


class CamelAdapter : public ITransport
{
	Camel* camel;

public:
	CamelAdapter(Camel* camel) : camel(camel) {}

	virtual void drive() override
	{
		//
		camel->move();
	}
};

class Horse
{
public:
	void jamp()
	{
		cout << "Кінь скачить по лісу" << endl;
	}
};


class HorseAdapter : public ITransport
{
	Horse* horse;

public:
	HorseAdapter(Horse* horse) : horse(horse) {}

	virtual void drive() override
	{
		horse->jamp();
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Traveler* traveler = new Traveler;
//	traveler->travel(new Auto);
//
//	Camel* camel = new Camel();
//	CamelAdapter* ca = new CamelAdapter(camel);
//	traveler->travel(ca);
//
//	traveler->travel(new HorseAdapter(new Horse));
//}