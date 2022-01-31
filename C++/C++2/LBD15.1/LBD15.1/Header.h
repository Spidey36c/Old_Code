#pragma once

class Person
{
public:
	void SetId(int id);
	int GetId();
	void SetGender(char gender);
	char GetGender();
private:
	int c_id;
	char c_gender;
};

void Person::SetId(int id)
{
	c_id = id;
}
int Person::GetId()
{
	return c_id;
}
void Person::SetGender(char gender)
{
	c_gender = gender;
}
char Person::GetGender()
{
	return c_gender;
}