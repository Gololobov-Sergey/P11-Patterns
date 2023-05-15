#pragma once
#include <iostream>


using namespace std;


class ILanguage
{
public:
	virtual~ILanguage() {}
	virtual void build() = 0;
	virtual void execute() = 0;
};


class CPP_Language : public ILanguage
{
public:
	virtual void build()override
	{
		cout << "За допомогою компілятора робимо бінарний файл (*.exe)" << endl;
	}

	virtual void execute()override
	{
		cout << "Запускаємо *.exe файл" << endl;
	}
};


class CSharp_Language : public ILanguage
{
public:
	virtual void build()override
	{
		cout << "За допомогою компілятора Roslin робимо CIL код (*.exe)" << endl;
	}

	virtual void execute()override
	{
		cout << "Запускаємо JIT і компілюємо файл" << endl;
		cout << "Запускаємо *.exe файл" << endl;
	}
};



class Programmer
{
	ILanguage* language;

public:
	virtual ~Programmer() 
	{
		if (this->language)
			delete this->language;
	}

	Programmer(ILanguage* language) : language(language)
	{

	}

	void setLanguage(ILanguage* language)
	{
		if (this->language)
			delete this->language;
		this->language = language;
	}

	void work()
	{
		language->build();
		language->execute();
	}


	virtual void getMoney() = 0;
};



class FreelanceProgrammer : public Programmer
{
public:
	FreelanceProgrammer(ILanguage* language) : Programmer(language)
	{

	}

	virtual void getMoney()override
	{
		cout << "Отримано гроші відразу за виконану роботу" << endl;
	}
};



class OfficeProgrammer : public Programmer
{
public:
	OfficeProgrammer(ILanguage* language) : Programmer(language)
	{

	}

	virtual void getMoney()override
	{
		cout << "Отримано гроші в кінці місяця" << endl;
	}
};




//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Programmer* pr1 = new FreelanceProgrammer(new CPP_Language());
//	pr1->work();
//	pr1->getMoney();
//	cout << endl;
//
//	pr1->setLanguage(new CSharp_Language());
//	pr1->work();
//	pr1->getMoney();
//	cout << endl;
//
//	Programmer* pr2 = new OfficeProgrammer(new CPP_Language());
//	pr2->work();
//	pr2->getMoney();
//	cout << endl;
//
//	pr2->setLanguage(new CSharp_Language());
//	pr2->work();
//	pr2->getMoney();
//
//}