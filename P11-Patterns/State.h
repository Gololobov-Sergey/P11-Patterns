#pragma once
#include <iostream>


using namespace std;

class Water;

class IStateWater
{
public:
	virtual ~IStateWater() {}
	virtual void heat(Water* w) = 0;
	virtual void frost(Water* w) = 0;
};


class Water
{
	IStateWater* state;

public:


	Water(IStateWater* state)
		: state(state)
	{
	}

	void setState(IStateWater* state)
	{
		if (this->state)
			delete this->state;
		this->state = state;
	}

	void heat()
	{
		//......
		state->heat(this);
		//......
	}

	void frost()
	{
		state->frost(this);
	}

};



class SolidWaterState : public IStateWater
{
public:
	virtual void heat(Water* w) override;

	virtual void frost(Water* w) override
	{
		cout << "Продовжуємо охолоджувати лід" << endl;
	}
};


class LiquidWaterState : public IStateWater
{
public:
	virtual void heat(Water* w) override;

	virtual void frost(Water* w) override
	{
		cout << "Вода перетворюється в лід" << endl;
		w->setState(new SolidWaterState);
	}
};


class SteamWaterState : public IStateWater
{
public:
	virtual void heat(Water* w) override
	{
		cout << "Продовжуємо нагрівати пару" << endl;
	}

	virtual void frost(Water* w) override
	{
		cout << "Пара конденсується у воду" << endl;
		w->setState(new LiquidWaterState);
	}
};

void SolidWaterState::heat(Water* w)
{
	cout << "Лід плавиться і стає водою" << endl;
	w->setState(new LiquidWaterState);
}


void LiquidWaterState::heat(Water* w)
{
	cout << "Вода перетворюється на пару" << endl;
	w->setState(new SteamWaterState);
}


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Water* water = new Water(new LiquidWaterState);
//
//	water->frost();
//	water->frost();
//	water->frost();
//	water->frost();
//
//	water->heat();
//	water->heat();
//	water->heat();
//	water->heat();
//
//}