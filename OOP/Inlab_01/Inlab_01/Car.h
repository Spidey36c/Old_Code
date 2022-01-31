#pragma once
#include <iostream>
#include <string.h>
#include "Engine.h"
using std::string;
class Car
{
public:
	Car();
	Car(Engine cyl, string make);
	Car(const Car & obj);
	Car & operator =(const Car & rhs);
	~Car();
private:
	Engine m_engine;
	string m_make;
};

