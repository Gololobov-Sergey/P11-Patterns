#pragma once
#include <iostream>
#include <map>

using namespace std;


class IPage
{
public:
	virtual string getPage(string key) = 0;
};



class DataBase: public IPage
{
	map<string, string> base;

public:
	DataBase()
	{
		base["1"] = "Page 1";
		base["2"] = "Page 2";
		base["3"] = "Page 3";
		base["4"] = "Page 4";
		base["5"] = "Page 5";
	}

	virtual string getPage(string key) override
	{
		if (base.contains(key))
			return base[key];
		return "No page 404";
	}
};



class DataBaseProxy : public IPage
{
	map<string, string> cash;

public:
	virtual string getPage(string key) override
	{
		if (cash.contains(key))
			return cash[key] + " from cash";
		else
		{
			DataBase* db = new DataBase();
			string result = db->getPage(key);
			cash[key] = result;
			delete db;
			return result;
		}
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//
//	DataBaseProxy* proxy = new DataBaseProxy();
//
//	while (true)
//	{
//		string key;
//		cin >> key;
//		cout << proxy->getPage(key) << endl;
//	}
//
//}