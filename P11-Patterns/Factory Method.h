#pragma once
#include <iostream>


using namespace std;


class Transport
{
public:
	virtual ~Transport() {}
	virtual void delivery(string adress) = 0;
	virtual string getType() = 0;
};


class Truck : public Transport
{
public:
	virtual void delivery(string adress) override
	{
		cout << "Вантаж доставлено наземним шляхом за адресою " << adress << endl;
	}
	virtual string getType() override
	{
		return "Створено вантажівку. ";
	}
};


class Ship : public Transport
{
public:
	virtual void delivery(string adress) override
	{
		cout << "Вантаж доставлено морем у порт " << adress << endl;
	}
	virtual string getType() override
	{
		return "Створено корабель. ";
	}
};


class SpaceShip : public Transport
{
public:
	virtual void delivery(string adress) override
	{
		cout << "Вантаж доставлено на планету " << adress << endl;
	}
	virtual string getType() override
	{
		return "Створено космічний корабель. ";
	}
};


class Creator
{
public:
	virtual ~Creator() {}

	virtual Transport* createTransport() = 0;

	Transport* create()
	{
		Transport* transport = this->createTransport();
		cout << transport->getType();
		return transport;
	}
};


class TruckCreator : public Creator
{
public:
	virtual Transport* createTransport() override
	{
		return new Truck();
	}
};


class ShipCreator : public Creator
{
public:
	virtual Transport* createTransport() override
	{
		return new Ship();
	}
};


class SpaceShipCreator : public Creator
{
public:
	virtual Transport* createTransport() override
	{
		return new SpaceShip();
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	/*Creator* creator = new TruckCreator();
//	Transport* tr1 = creator->create();
//	tr1->delivery("IT STEP Academy");
//	cout << endl;
//
//	creator = new ShipCreator();
//	Transport* tr2 = creator->create();
//	tr2->delivery("Миколаїв");
//	cout << endl;
//
//	creator = new SpaceShipCreator();
//	Transport* tr3 = creator->create();
//	tr3->delivery("Марс");*/
//
//
//	Creator* creator = nullptr;
//	cout << "1 - Вантажівка, 2 - Корабель, 3 - Космічний корабель :";
//	int n;
//	cin >> n;
//	switch (n)
//	{
//	case 1: creator = new TruckCreator(); break;
//	case 2: creator = new ShipCreator(); break;
//	case 3: creator = new SpaceShipCreator(); break;
//	}
//
//	Transport* tr = creator->create();
//	tr->delivery("кудись...");
//}