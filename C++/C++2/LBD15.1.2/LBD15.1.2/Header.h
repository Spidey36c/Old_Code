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
