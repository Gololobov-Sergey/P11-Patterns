#pragma once
#include <iostream>
#include <vector>

using namespace std;



class MCComponent
{
public:
	virtual~MCComponent() {}
	virtual string toString() = 0;
};


class Radio : public MCComponent
{
public:
	//virtual string toString() override
	//{
	//	return "Radio";
	//}
};


class RadioFM : public Radio
{
public:
	virtual string toString() override
	{
		return "RadioFM";
	}
};

class RadioAM : public Radio
{
public:
	virtual string toString() override
	{
		return "RadioAM";
	}
};

class CD : public MCComponent
{
public:
	virtual string toString() override
	{
		return "CD";
	}
};


class Karaoke : public MCComponent
{
public:
	virtual string toString() override
	{
		return "Karaoke";
	}
};


class Subwoofer : public MCComponent
{
public:
	virtual string toString() override
	{
		return "Subwoofer";
	}
};


class VinilDisk : public MCComponent
{
public:
	virtual string toString() override
	{
		return "VinilDisk";
	}
};



class MusicCentr
{
	vector<MCComponent*> parts;
	Radio* radio;

public:
	void addPart(MCComponent* part)
	{
		parts.push_back(part);
	}

	void info()
	{
		cout << "Music Centr" << endl;
		cout << "-----------" << endl;
		for (size_t i = 0; i < parts.size(); i++)
		{
			cout << i + 1 << ". " << parts[i]->toString() << endl;
		}
	}
};


class Builder
{
public:
	virtual ~Builder() {}
	virtual void reset()          = 0;
	virtual void buildRadio()     = 0;
	virtual void buildCD()        = 0;
	virtual void buildKaraoke()   = 0;
	virtual void buildSubwoofer() = 0;
	virtual void buildVinilDisk() = 0;
};



class MCBuilder : public Builder
{
	MusicCentr* result;

public:
	MCBuilder() { this->reset(); }

	virtual void reset()
	{
		result = new MusicCentr();
	}

	virtual void buildRadio()     override 
	{ 
		result->addPart(new RadioFM()); 
	}

	virtual void buildCD()        override { result->addPart(new CD()); }

	virtual void buildKaraoke()   override { result->addPart(new Karaoke()); }

	virtual void buildSubwoofer() override { result->addPart(new Subwoofer()); }

	virtual void buildVinilDisk() override { result->addPart(new VinilDisk()); }

	MusicCentr* getResult()
	{
		MusicCentr* product = result;
		this->reset();
		return product;
	}
};


class Director
{
	Builder* builder;

public:
	Director(Builder* builder = nullptr) : builder(builder) {}

	void changeBuilder(Builder* builder)
	{
		/*if (this->builder)
			delete this->builder;*/
		this->builder = builder;
	}

	void make(string type)
	{
		if (type == "miniMC")
		{
			this->builder->buildRadio();
			this->builder->buildCD();
		}

		if (type == "maxiMC")
		{
			this->builder->buildRadio();
			this->builder->buildCD();
			this->builder->buildKaraoke();
			this->builder->buildSubwoofer();
			this->builder->buildVinilDisk();
		}
	}
};



class MCManual
{
	string manual = "Manual Music Centr\n----------------\n";

public:
	void addSection(string section)
	{
		manual += section;
	}

	string info()
	{
		return manual;
	}
};


class ManualMCBuilder : public Builder
{
	MCManual* result;

public:
	ManualMCBuilder() { this->reset(); }

	virtual void reset()
	{
		result = new MCManual();
	}

	virtual void buildRadio()     override { result->addSection("For Radio press 1\n"); }

	virtual void buildCD()        override { result->addSection("For CD press 3\n"); }

	virtual void buildKaraoke()   override { result->addSection("For Karaoke press 1 and 4\n"); }

	virtual void buildSubwoofer() override { result->addSection("For Subwoofer press 5\n"); }

	virtual void buildVinilDisk() override { result->addSection("For Vinil set disk and press 55\n"); }

	MCManual* getResult()
	{
		MCManual* product = result;
		this->reset();
		return product;
	}
};