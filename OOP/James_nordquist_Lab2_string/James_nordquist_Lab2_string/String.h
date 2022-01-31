#ifdef String_h
#define String_h
#endif
class String
{
public:
	String();
	String(char ch);
	String(char *str);
	~String();
	String(const String& copy);
	String & operator =(const String& rhs);
	void Display();
	void Upper();
	void Lower();
private:
	char * m_string;
};

