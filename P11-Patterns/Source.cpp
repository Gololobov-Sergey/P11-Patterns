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
#include "Command.h"
#include "Observer.h"
#include "Memento.h"
#include "Strategy.h"

using namespace std;




int main()
{
	SetConsoleOutputCP(1251);

	Navigator* navi = new Navigator;
	navi->setStrategy(new OnAutoStrategy());
	navi->getRoute(10);


	//Strategy* strategy
}