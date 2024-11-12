#include "Stack.h"
#include <iostream>
using namespace std;

void Stack::push(char ch)
{
	if (tos == SIZE) {
		cout << "���� �����!" << endl;
		return;
	} 
	stck[tos] = ch;
	tos++;
}

void Stack::init()
{
	tos = 0;
}

Stack::Stack(int id)
{
	this->StackID = id;
	cout << "������������� ����� " << StackID<<endl;
	tos = 0;
}

Stack::~Stack()
{
	cout << "���������� ����� " << StackID << " �����������..."<<endl;
}

char Stack::pop()
{
	if (tos == 0) {
		cout << "���� ����!" << endl;
		return 0;
	}
	tos--;
	return stck[tos];
}

