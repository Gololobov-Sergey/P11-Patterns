#pragma once
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Visitor;

class IFigure
{
public:

	virtual void print() = 0;
	virtual void accept(Visitor* v) = 0;
};

class Point : public IFigure
{

public:

	int x, y;

	Point(int x, int y)
		: x(x), y(y)
	{
	}

	virtual void print() override
	{
		cout << "Point: X = " << x << ", Y = " << y << endl;
	}

	virtual void accept(Visitor* v) override;

};


class Circle : public IFigure
{

public:

	int x, y, r;

	Circle(int x, int y, int r)
		: x(x), y(y), r(r)
	{
	}

	virtual void print() override
	{
		cout << "Circle: X = " << x << ", Y = " << y << ", R = " << r << endl;
	}

	virtual void accept(Visitor* v) override;

};

class Rect : public IFigure
{

public:

	int w, h;

	Rect(int w, int h)
		: w(w), h(h)
	{
	}

	virtual void print() override
	{
		cout << "Rectangle: W = " << w << ", H = " << h << endl;
	}

	virtual void accept(Visitor* v) override;

};


class Visitor
{
public:
	virtual void visit(Point* p) = 0;
	virtual void visit(Circle* c) = 0;
	virtual void visit(Rect* r) = 0;
};


class HTMLExportVisitor : public Visitor
{
	string path;

public:


	HTMLExportVisitor(const string& path)
		: path(path)
	{
	}

	virtual void visit(Point* p) override
	{
		string res = "<table border=\"1\"><tr><td>Point</td><td>";
		res += "X = " + to_string(p->x) + ", Y = " + to_string(p->y) +
			"</td></tr></table>";
		ofstream out(path, ios::app);
		out << res << endl;
		out.close();
	}

	virtual void visit(Circle* c)
	{
		string res = "<table border=\"1\"><tr><td>Circle</td><td>";
		res += "X = " + to_string(c->x) + ", Y = " + to_string(c->y) + ", R = " + to_string(c->r) +
			"</td></tr></table>";
		ofstream out(path, ios::app);
		out << res << endl;
		out.close();
	}

	virtual void visit(Rect* r)
	{
		string res = "<table border=\"1\"><tr><td>Rectangle</td><td>";
		res += "W = " + to_string(r->w) + ", H = " + to_string(r->h) +
			"</td></tr></table>";
		ofstream out(path, ios::app);
		out << res << endl;
		out.close();
	}

};


void Point::accept(Visitor* v)
{
	v->visit(this);
}

void Circle::accept(Visitor* v)
{
	v->visit(this);
}

void Rect::accept(Visitor* v)
{
	v->visit(this);
}


class TXTExportVisitor : public Visitor
{
	string path;

public:


	TXTExportVisitor(const string& path)
		: path(path)
	{
	}

	virtual void visit(Point* p) override
	{
		string res = " Point: X = " + to_string(p->x) + ", Y = " + to_string(p->y);
		ofstream out(path, ios::app);
		out << res << endl;
		out.close();
	}

	virtual void visit(Circle* c)
	{
		string res = "Circle: X = " + to_string(c->x) + ", Y = " + to_string(c->y) + ", R = " + to_string(c->r);
		ofstream out(path, ios::app);
		out << res << endl;
		out.close();
	}

	virtual void visit(Rect* r)
	{
		string res = "Rectangle: W = " + to_string(r->w) + ", H = " + to_string(r->h);
		ofstream out(path, ios::app);
		out << res << endl;
		out.close();
	}

};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	IFigure* arr[] = { new Point(12, 34), new Circle(23, 45, 56), new Rect(32, 65) };
//	for (auto& f : arr)
//	{
//		f->print();
//	}
//
//	//Visitor* toHTML = new HTMLExportVisitor("index.html");
//	Visitor* toTXT = new TXTExportVisitor("figures.txt");
//	for (auto& f : arr)
//	{
//		f->accept(toTXT);
//	}
//
//}