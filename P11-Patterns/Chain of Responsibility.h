#pragma once
#include <iostream>


using namespace std;



class Handler
{
protected:

	Handler* nextHandler;

public:
	Handler(Handler* h) : nextHandler(h) {}

	virtual void sendPayment(int sum) = 0;
};



class HClient
{
	Handler* handler;

public:
	HClient(Handler* h) : handler(h) {}

	void pay(int sum)
	{
		if (handler)
			handler->sendPayment(sum);
	}
};


class EconomistHandler : public Handler
{
public:
	EconomistHandler(Handler* h) : Handler(h) {}

	virtual void sendPayment(int sum) override
	{
		if (sum < 1000)
		{
			cout << "Платіж проведено економістом" << endl;
		}
		else
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
	}
};


class BuchgalterHandler : public Handler
{
public:
	BuchgalterHandler(Handler* h) : Handler(h) {}

	virtual void sendPayment(int sum) override
	{
		if (sum < 5000)
		{
			cout << "Платіж проведено бухгалтером" << endl;
		}
		else
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
	}
};


class DirectorHandler : public Handler
{
public:
	DirectorHandler(Handler* h) : Handler(h) {}

	virtual void sendPayment(int sum) override
	{
		if (sum < 10000)
		{
			cout << "Платіж проведено директором" << endl;
		}
		else
		{
			cout << "Завелика сума, потрібна рада директорів, а зараз її немає" << endl;
		}
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	//HClient* client = new HClient(new EconomistHandler(new BuchgalterHandler(new DirectorHandler(nullptr))));
//	HClient* client = new HClient(new EconomistHandler(new DirectorHandler(nullptr)));
//	client->pay(1500);
//
//}