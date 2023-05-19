#pragma once
#include <iostream>
#include <map>

using namespace std;


class HouseFlyweight
{
	string name;
	string pathPictures;
	int floor;

public:
	HouseFlyweight(string name, string pathPictures, int floor):
		name(name), pathPictures(pathPictures), floor(floor)
	{

	}

	void build(int x, int y)
	{
		cout << "Побудовано " << name << " з " << floor << " поверхів, в координатах Х = " <<
			x << ", Y = " << y << endl;
	}

	void info(int x, int y)
	{
		cout << name << " розташований в координатах Х = " << x << ", Y = " << y <<
			" і має картинку " << pathPictures << endl;
	}
};


class House
{
	int x;
	int y;
	HouseFlyweight* house_flyweight;

public:
	House(int x, int y, HouseFlyweight* house) : x(x), y(y), house_flyweight(house) 
	{
		if (house_flyweight)
			house_flyweight->build(x, y);
		else
		{
			x = y = 0;
			cout << "Будинок не побудовано" << endl;
		}
	}

	void info()
	{
		if (house_flyweight)
			house_flyweight->info(x, y);
		else
		{
			cout << "Будинок не було побудовано" << endl;
		}
	}
};



class FlyweightFactory
{
	map<string, HouseFlyweight*> cash;

public:
	FlyweightFactory()
	{
		cash["panel"] = new HouseFlyweight("Панельний будинок", "panel.png", 9);
		cash["brick"] = new HouseFlyweight("Цегляний будинок", "brick.png", 9);
	}

	HouseFlyweight* getHouse(string key)
	{
		if (cash.contains(key))
			return cash[key];
		return nullptr;
	}

};



//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	vector<House*> street;
//
//	FlyweightFactory* ff = new FlyweightFactory();
//
//	for (size_t i = 0; i < 5; i++)
//	{
//		street.push_back(new House(rand() % 10, rand() % 10, ff->getHouse("panel")));
//	}
//	for (size_t i = 0; i < 5; i++)
//	{
//		street.push_back(new House(rand() % 10, rand() % 10, ff->getHouse("brick")));
//	}
//	street.push_back(new House(rand() % 10, rand() % 10, ff->getHouse("beton")));
//
//	cout << endl;
//
//	for (House* h : street)
//	{
//		h->info();
//	}
//
//
//}