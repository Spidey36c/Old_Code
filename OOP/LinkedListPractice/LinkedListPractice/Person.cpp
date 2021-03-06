#include <iostream>
#include <string.h>
#include "person.h"
using std::cout;
using std::endl;


person::person() : m_name(nullptr), m_age(0)
{
	cout << "person default ctor called" << endl;
	m_name = new char[sizeof("") + 1];
	strcpy(m_name, "");
}

person::~person()
{
	cout << "person dtor called" << endl;
	delete[] m_name;
}

person::person(const char * name, int age) :m_age(age)
{
	cout << "person 2 arg ctor called" << endl;

	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}

person::person(const person & obj) :m_age(obj.m_age), m_name(nullptr)
{
	cout << "person copy ctor called" << endl;

	m_name = new char[strlen(obj.m_name) + 1];
	strcpy(m_name, obj.m_name);

}

person & person::operator=(const person & rhs)
{
	cout << "person op = called" << endl;
	// 1. Check for self assignment
	if (this != &rhs)
	{
		// 2. Purge the left hand side
		delete[] m_name;

		// 3. Make the deep copy
		m_age = rhs.m_age;
		m_name = new char[strlen(rhs.m_name) + 1];
		strcpy(m_name, rhs.m_name);
	}
	// 4. Return reference to self
	return *this;
}

bool person::operator==(const person & obj) const
{
	return strcmp(m_name, obj.m_name) == 0 ? true : false;
}

bool person::operator==(const char * name) const
{
	return strcmp(m_name, name) == 0 ? true : false;
}

bool person::operator!=(const person & obj) const
{
	return strcmp(m_name, obj.m_name) == 0 ? true : false;
}

bool person::operator<=(const person & obj) const
{
	return strcmp(m_name, obj.m_name) <= 0 ? true : false;
}

bool person::operator>=(const person & obj) const
{
	return strcmp(m_name, obj.m_name) >= 0 ? true : false;
}

bool person::operator>(const person & obj) const
{
	return strcmp(m_name, obj.m_name) > 0 ? true : false;
}

bool person::operator<(const person & obj) const
{
	return strcmp(m_name, obj.m_name) < 0 ? true : false;
}

const char * person::getName() const
{
	return m_name;
}

void person::setName(const char * name)
{
	delete[] m_name;
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}

int person::getAge()
{
	return m_age;
}

void person::setAge(int age)
{
	m_age = age;
}

void person::display()
{
	cout << m_name << " is " << m_age << " years old" << endl;
}
