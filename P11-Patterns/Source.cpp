#include <iostream>

#include "Singleton.h"
#include "Prototype.h"
#include "Builder.h"

using namespace std;




int main()
{
	Director* director = new Director();

	MCBuilder* builder = new MCBuilder();
	//=====================================
	//director->changeBuilder(builder);
	//director->make("maxiMC");

	builder->buildRadio();
	builder->buildVinilDisk();
	//=====================================
	MusicCentr* mc = builder->getResult();
	mc->info();
	cout << endl;



	ManualMCBuilder* manualBuilder = new ManualMCBuilder();
	//======================================
	/*director->changeBuilder(manualBuilder);
	director->make("maxiMC");*/

	manualBuilder->buildRadio();
	manualBuilder->buildVinilDisk();
	//======================================
	MCManual* mcmanual = manualBuilder->getResult();
	cout << mcmanual->info() << endl;

	/*director->make("maxiMC");
	MusicCentr* bigMC = builder->getResult();
	bigMC->info();*/
}