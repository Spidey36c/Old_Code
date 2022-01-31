#pragma once
#include <iostream>
#include <string.h>
using std::string;

class Engine
{
public:
	Engine();
	Engine(int cyl, string manf);
	Engine(const Engine & obj);
	Engine & operator =(const Engine & rhs);
	~Engine();
private:
	int m_cyl;
	string m_manf;
};

