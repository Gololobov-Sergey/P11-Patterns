#pragma once
#include <iostream>
#include <stack>


using namespace std;



class Strategy
{
public:
	virtual~Strategy() {}

	virtual float getTime(float length) = 0;
};


class OnFootStrategy : public Strategy
{
public:

	virtual float getTime(float length) override
	{
		return length / 5.0;
	}
};


class OnBusStrategy : public Strategy
{
public:

	virtual float getTime(float length) override
	{
		return length / 20.0 + 0.2;
	}
};


class OnAutoStrategy : public Strategy
{
public:

	virtual float getTime(float length) override
	{
		return length / 50.0 + 0.1;
	}
};


class Navigator
{
	Strategy* strategy = nullptr;

public:

	void setStrategy(Strategy* strategy)
	{
		if (this->strategy)
			delete strategy;
		this->strategy = strategy;
	}

	void getRoute(float length)
	{
		////
		cout << "Time: " << strategy->getTime(length) << " hour" << endl;
		////
	}
};