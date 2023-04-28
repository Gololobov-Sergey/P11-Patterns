#pragma once

#include <fstream>


using namespace std;


class Logger
{
	static Logger* instance;

	Logger() {}

public:

	static Logger* getLogger();  // getInstance()

	void sendMessage(string message);
};


Logger* Logger::instance = nullptr;


Logger* Logger::getLogger()
{
	if (instance == nullptr)
		instance = new Logger();
	return instance;
}


void Logger::sendMessage(string message)
{
	ofstream out("log.txt", ios::app);
	out << __DATE__ << " " << __TIME__ << " " << message << endl;
	out.close();
}


//int main()
//{
//	Logger* log1 = Logger::getLogger();
//	log1->sendMessage("Error 1");
//	cout << log1 << endl;
//
//	Logger* log2 = Logger::getLogger();
//	log2->sendMessage("Fatal error 2");
//	cout << log2 << endl;
//
//	Logger::getLogger()->sendMessage("Error 3");
//}