#include <iostream>
#include "Car.h"
using std::cout;
using std::endl;


Car::Car():m_make("")
{
	cout << "Default Car ctor called" << endl;
}

Car::Car(Engine engine, string make):m_engine(engine),m_make(make)
{
	cout << "Overloaded Car ctor called" << endl;
}

Car::Car(const Car & obj):m_engine(obj.m_engine),m_make(obj.m_make)
{
	cout << "Car Copy ctor called" << endl;
}

Car & Car::operator=(const Car & rhs)
{
	cout << "Car Op = called" << endl;
	m_engine = rhs.m_engine;
	if (m_make != rhs.m_make)
	{
		m_make = rhs.m_make;
	}
	return *this;
}


Car::~Car()
{
	cout << "Car Dtor called" << endl;
}
