#pragma once
class string
{
public:
	string();
	string(const char  * string);
	string(const string &obj);
	string & operator =(const string &rhs);
	~string();
	void display();
private:
	char * m_string;
};

