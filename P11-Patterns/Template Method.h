#pragma once
#include <iostream>


using namespace std;


class HouseBuilder
{
protected:

	string house = "";

public:
	virtual ~HouseBuilder() {}

	void buildHouse() // Template Method
	{
		buildBasment();
		buildWall();
		buildDoor();
		buildWindow();
		hook();
		buildRoof();
	}

	string info() { return house; }

protected:

	void buildBasment() { house += "Фундамент\n"; }
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow() = 0;

	virtual void hook() {}

	virtual void buildRoof() = 0;

};


class StandartHouse : public HouseBuilder
{
public:
	StandartHouse()
	{
		house += "Стандартний будинок\n";
	}

protected:

	virtual void buildWall() override { house += "Дерев'яні стіни\n"; }

	virtual void buildDoor() override { house += "Звичайні двері\n"; }

	virtual void buildWindow() override { house += "Пластикові вікна\n"; }

	virtual void buildRoof() override { house += "Черепичний дах\n"; }

};


class BrillaintHouse : public HouseBuilder
{
public:
	BrillaintHouse()
	{
		house += "Хрустальний палац\n";
	}

protected:

	virtual void buildWall() override { house += "Хрустальні стіни\n"; }

	virtual void buildDoor() override { house += "Позолочені двері\n"; }

	virtual void buildWindow() override { house += "Рубінові вікна\n"; }

	virtual void hook() override { house += "Мармуровий басейн\n"; }

	virtual void buildRoof() override { house += "Алмазний дах\n"; }

};



//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	HouseBuilder* house1 = new StandartHouse();
//	house1->buildHouse();
//	cout << house1->info() << endl << endl;
//
//	HouseBuilder* house2 = new BrillaintHouse();
//	house2->buildHouse();
//	cout << house2->info() << endl << endl;
//
//}