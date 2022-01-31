#pragma once
#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

class String
{
public:
	String();
	String(const char * string);
	String(const String & copy);
	String & operator = (const String & rhs);
	~String();
	void SetString(const char * string);
	char * GetString() const;
private:
	char * m_string;
};

class Person
{
public:
	Person();
	Person(String name, int age);
	Person(const Person & copy);
	Person & operator = (const Person & rhs);
	~Person();
	void SetName(String name);
	String GetName() const;
	void SetAge(int age);
	int GetAge() const;
private:
	String m_name;
	int m_age;
};