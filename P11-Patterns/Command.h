#pragma once
#include <iostream>
#include <vector>


using namespace std;


class TV
{
public:
	void on() { cout << "TV on" << endl; }
	void off() { cout << "TV off" << endl; }
};



class ICommand
{
public:
	virtual ~ICommand() {}

	virtual void execute() = 0;
};



class TV_on_Command : public ICommand
{
	TV* tv;

public:
	TV_on_Command(TV* tv) : tv(tv) { }

	virtual void execute() override
	{
		tv->on();
	}
};

class TV_off_Command : public ICommand
{
	TV* tv;

public:
	TV_off_Command(TV* tv) : tv(tv) { }

	virtual void execute() override
	{
		tv->off();
	}
};


class Pult
{
	vector<ICommand*> commands;

public:

	void setCommand(ICommand* com)
	{
		commands.push_back(com);
	}

	void pressButton(int num)
	{
		commands[num]->execute();
	}

};


class MicroWave
{

public:

	void start(int time) 
	{
		for (size_t i = 0; i < time; i++)
		{
			cout << "."; 
			Sleep(1000);
		}
		cout << "Eat complete" << endl;
	}
};



class MW_Start_Command : public ICommand
{
	MicroWave* mw;

	int time;

public:

	MW_Start_Command(MicroWave* mw, int time) : mw(mw), time(time) { }

	virtual void execute() override
	{
		mw->start(time);
	}
};

//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	TV* tv = new TV();
//
//	Pult* pult = new Pult();
//
//	pult->setCommand(new TV_on_Command(tv));
//
//	pult->setCommand(new TV_off_Command(tv));
//
//	pult->pressButton(0);
//	pult->pressButton(1);
//
//	MicroWave* mw = new MicroWave();
//
//	pult->setCommand(new MW_Start_Command(mw, 5));
//
//	pult->pressButton(2);
//
//}