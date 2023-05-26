#pragma once
#include <iostream>
#include <list>


using namespace std;

class ISubscriber;

class Publisher_Car
{
	list<ISubscriber*> subscribers;

	string model;

	int price;

public:
	

	Publisher_Car(const string& model, int price)
		: model(model), price(price)
	{
	}

	void addSubscriber(ISubscriber* sub)
	{
		subscribers.push_back(sub);
	}

	void removeSubscriber(ISubscriber* sub)
	{
		auto it = find(subscribers.begin(), subscribers.end(), sub);
		if(it != subscribers.end())
			subscribers.remove(sub);
	}

	string getModel() { return model; }

	int getPrice() { return price; }

	void changePrice()
	{
		int p;
		cout << "New price: ";
		cin >> p;
		if (p != price)
		{
			price = p;
			notify();
		}
	}

	void notify();
};


class ISubscriber
{
public:
	virtual ~ISubscriber() {}

	virtual void update(Publisher_Car* car) = 0;
};


class Buyer : public ISubscriber
{
	string name;

public:

	Buyer(string name) : name(name) {}

	virtual void update(Publisher_Car* car) override
	{
		cout << "Повідомленя для " << name << " по автівці " << car->getModel() << endl;
		cout << "Нова ціна: $" << car->getPrice() << endl;

	}
};


void Publisher_Car::notify()
{
	for (ISubscriber* s : subscribers)
	{
		s->update(this);
	}
}


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Publisher_Car* car1 = new Publisher_Car("BMW X11", 100000);
//	Publisher_Car* car2 = new Publisher_Car("Audi A13", 120000);
//
//	ISubscriber* buyer1 = new Buyer("Іщенко Артем Вадимович");
//	ISubscriber* buyer2 = new Buyer("Батенко Анастасія Ігорівна");
//	ISubscriber* buyer3 = new Buyer("Бобриніченко Ярослав Миколайович");
//	ISubscriber* buyer4 = new Buyer("Враченко Вадим Максимович");
//	ISubscriber* buyer5 = new Buyer("Зубаль Тимур Віталійович");
//
//	car1->addSubscriber(buyer1);
//	car1->addSubscriber(buyer2);
//
//	car2->addSubscriber(buyer3);
//	car2->addSubscriber(buyer4);
//	car2->addSubscriber(buyer5);
//
//	car1->changePrice();
//	car2->changePrice();
//
//	car2->removeSubscriber(buyer5);
//
//	car2->changePrice();
//
//}