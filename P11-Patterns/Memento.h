#pragma once
#include <iostream>
#include <stack>


using namespace std;


class Hero_Memento;


class Hero_Originator
{
	int bullets = 100;
	int hp = 100;
	//.....

public:

	void shoot()
	{
		if (bullets)
		{
			cout << "--->  " << --bullets << endl;
		}
	}

	Hero_Memento* save();

	void restore(Hero_Memento* hm);
};


class Hero_Memento
{
	int bullets;
	int hp;

public:

	Hero_Memento(int bullets, int hp) : bullets(bullets), hp(hp) {}

	int getBullets() { return bullets; }

	int getHP() { return hp; }
};


Hero_Memento* Hero_Originator::save()
{
	cout << "Save: " << bullets << " bullets" << endl;
	return new Hero_Memento(bullets, hp);
}


void Hero_Originator::restore(Hero_Memento* hm)
{
	bullets = hm->getBullets();
	hp = hm->getHP();
	cout << "Load: " << bullets << " bullets" << endl;
}


class GameHistory
{
	Hero_Originator* hero;
	stack<Hero_Memento*> history;

public:
	GameHistory(Hero_Originator* hero) : hero(hero) {}

	void save()
	{
		history.push(hero->save());
	}

	void undo()
	{
		Hero_Memento* hm = history.top();
		hero->restore(hm);
		history.pop();
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Hero_Originator* hero = new Hero_Originator();
//	GameHistory* history = new GameHistory(hero);
//
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//
//	history->save();
//
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot(); // boom
//
//	history->undo();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//
//}