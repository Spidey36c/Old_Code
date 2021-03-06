#include <iostream>
#include <string.h>
#include "Engine.h"
#include "Car.h"

void EVtest(Engine FE);
void ERtest(Engine &FE);
void EPtest(Engine *FE);
void EAtest(Engine FE[]);
void CERtest(const Engine &FE);
Engine IRTest();
Car CVtest(Car FC);

int main()
{
	Engine E1;
	Engine E2(4, "Isuzu Motors");
	Engine *Eptr;
	Engine E3[3];
	Engine E4 = E2;
	Car C1;
	Car C2(E2, "Ford");

	Eptr = new Engine;
	EVtest(E2);
	ERtest(E4);
	EPtest(&E2);
	EAtest(E3);
	for (int i = 0; i < 3; i++)
	{
		EVtest(E3[i]);
	}
	CERtest(E4);
	E1 = IRTest();
	C1 = CVtest(C2);
	delete Eptr;

	return 0;
}

void EVtest(Engine FE)
{

}

void ERtest(Engine &FE)
{

}

void EPtest(Engine *FE)
{

}

void EAtest(Engine FE[])
{

}

void CERtest(const Engine &FE)
{

}

Engine IRTest()
{
	Engine FE(2, "D. Napier & Son");

	return FE;
}

Car CVtest(Car FC)
{
	return FC;
}