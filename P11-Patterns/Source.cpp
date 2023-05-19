#include <iostream>
#include <Windows.h>

#include "Singleton.h"
#include "Prototype.h"
#include "Builder.h"
#include "Abstract Factory.h"
#include "Factory Method.h"
#include "Adapter.h"
#include "Bridge.h"
#include "Decorator.h"
#include "Composite.h"
#include "Flyweight.h"
#include "Proxy.h"
#include "Chain of Responsibility.h"

using namespace std;




int main()
{
	SetConsoleOutputCP(1251);

	//HClient* client = new HClient(new EconomistHandler(new BuchgalterHandler(new DirectorHandler(nullptr))));
	HClient* client = new HClient(new EconomistHandler(new DirectorHandler(nullptr)));
	client->pay(1500);

}