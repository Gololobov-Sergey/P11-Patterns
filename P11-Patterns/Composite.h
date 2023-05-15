#pragma once
#include <iostream>
#include <list>


using namespace std;


class Component
{
protected:
	string name;
	static int n;

public:
	Component(string name) : name(name)	{}

	virtual void print() = 0;
};

int Component::n = 0;

class Directiry : public Component
{
	list<Component*> components;

public:
	Directiry(string name) : Component(name) { 	}

	void add(Component* c) { components.push_back(c); }

	virtual void print() override
	{
		
		for (size_t i = 0; i < n; i++)
		{
			cout << " ";
		}
		n++;
		cout << "[" << name << "]" << endl;
		for (auto c : components)
		{
			c->print();
		}
		n--;
	}
};


class File : public Component
{
public:
	File(string name) : Component(name) { 	}

	virtual void print() override
	{
		n++;
		for (size_t i = 0; i < n; i++)
		{
			cout << " ";
		}
		cout << "-" << name << endl;
		n--;
	}

};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Directiry* diskC = new Directiry("C:\\");
//	Directiry* dir1 = new Directiry("Dir 1");
//	Directiry* dir2 = new Directiry("Dir 2");
//	Directiry* dir3 = new Directiry("Dir 3");
//	File* file1 = new File("File 1");
//	File* file2 = new File("File 2");
//	File* file3 = new File("File 3");
//	File* file4 = new File("File 4");
//	File* file5 = new File("File 5");
//	File* file6 = new File("File 6");
//
//	dir1->add(file1);
//	dir1->add(file2);
//
//	dir3->add(file3);
//	dir3->add(file4);
//
//	dir2->add(dir3);
//	dir2->add(file5);
//	dir2->add(file6);
//
//	diskC->add(dir1);
//	diskC->add(dir2);
//
//	diskC->print();
//}