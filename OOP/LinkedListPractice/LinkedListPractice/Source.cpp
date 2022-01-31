#include <iostream>
#include "list.h"
#include "person.h"
#include "Node.h"
using std::cout;
using std::cin;
using std::endl;
#include <crtdbg.h>

void getData(person & data);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	list * myList = new list;
	person data;

	getData(data);
	myList->insertOrdered(data);
	getData(data);
	myList->insertOrdered(data);
	getData(data);
	myList->insertOrdered(data);

	list new_list(*myList);
	list myList3;

	myList3 = new_list;

	delete myList;

	return 0;
}


void getData(person & data)
{
	char buffer[256];
	int intb;
	cout << "Please enter the persons first name: ";
	cin >> buffer;
	data.setName(buffer);
	cout << "Please enter the persons age: ";
	cin >> intb;
	data.setAge(intb);
}