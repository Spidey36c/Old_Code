#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Sample
{
public:
	Sample();
	Sample(const Sample & copy);
	Sample &operator = (const Sample & copy);
	Sample(short int age, float shoe_size=8);
	short int getAge();
	~Sample();

private:
	short int m_age;
	float m_shoe_size;
};

Sample::Sample()
{
	m_age = 0;
	m_shoe_size = 0;
	cout << "Ctor that sets age and shoe size to zero has been called" << endl;
}
Sample::Sample(const Sample & copy) :m_age(copy.m_age), m_shoe_size(copy.m_shoe_size)
{
	cout << "copy Ctor was called" << endl;
}
Sample &Sample::operator=(const Sample & copy)
{
	cout << "Copy Assignment Operator was called" << endl;
	m_age = copy.m_age;
	m_shoe_size = copy.m_shoe_size;
	return *this;
}
Sample::Sample(short int age, float shoe_size)
{
	m_age = age;
	m_shoe_size = shoe_size;
	cout << "Ctor that calls a short int and float for age and shoe size respectivly has been called" << endl;
}
Sample::~Sample()
{
	cout << "Dtor has been called" << endl;
}
short int Sample::getAge()
{
	return m_age;
}