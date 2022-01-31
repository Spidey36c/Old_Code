#include <iostream>
using std::cout;
using std::endl;
#include "Engine.h"



Engine::Engine():m_cyl(0),m_manf("")
{
	cout << "Default Engine ctor called" << endl;
}

Engine::Engine(int cyl, string manf):m_cyl(cyl),m_manf(manf)
{
	cout << "Overloaded Engine ctor called" << endl;
}

Engine::Engine(const Engine & obj):m_cyl(obj.m_cyl),m_manf(obj.m_manf)
{
	cout << "Copy Engine ctor called" << endl;
}

Engine & Engine::operator=(const Engine & rhs)
{
	cout << "Engine Op = called" << endl;

	if (m_cyl != rhs.m_cyl)
	{
		m_cyl = rhs.m_cyl;
	}
	if (m_manf != rhs.m_manf)
	{
		m_manf = rhs.m_manf;
	}
	return *this;
}


Engine::~Engine()
{
	cout << "Engine Dtor called" << endl;
}
