#include "Stack.h"
#include <iostream>
using namespace std;

void Stack::push(char ch)
{
	if (tos == SIZE) {
		cout << "Стек полон!" << endl;
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
	cout << "Инициализация стека " << StackID<<endl;
	tos = 0;
}

Stack::~Stack()
{
	cout << "Деструктор стека " << StackID << " выполняется..."<<endl;
}

char Stack::pop()
{
	if (tos == 0) {
		cout << "Стек пуст!" << endl;
		return 0;
	}
	tos--;
	return stck[tos];
}

