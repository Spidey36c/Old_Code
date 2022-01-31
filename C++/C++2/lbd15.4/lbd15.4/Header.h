class Sample
{
public:
	Sample();
	Sample(const Sample & copy);
	Sample &operator = (const Sample & copy);
	Sample(short int age, float shoe_size = 8);
	short int getAge();
	~Sample();

private:
	short int m_age;
	float m_shoe_size;
};
