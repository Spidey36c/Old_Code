#pragma once

class person
{
public:
	person();
	person(const char  * name, int age);
	person(const person &obj);
	person & operator =(const person &rhs);
	const char * getName();
	void setName(const char * name);
	int getAge();
	void setAge(int age);
	void display();
	~person();
private:
	char * m_name;
	int m_age;
};

