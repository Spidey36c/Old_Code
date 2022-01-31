#pragma once

class person
{
public:
	person();
	person(const char  * name, int age);
	person(const person &obj);
	person & operator =(const person &rhs);
	bool operator ==(const person & obj) const;
	bool operator ==(const char * name) const;
	bool operator !=(const person & obj) const;
	bool operator <=(const person & obj) const;
	bool operator >=(const person & obj) const;
	bool operator >(const person & obj) const;
	bool operator <(const person & obj) const;
	const char * getName() const;
	void setName(const char * name);
	int getAge();
	void setAge(int age);
	void display();
	~person();
private:
	char * m_name;
	int m_age;
};

