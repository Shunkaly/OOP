// ClassStek

#include <iostream>
#include "Stack.h"
#include<locale.h>
using namespace std;
0
 {
	setlocale(LC_ALL, "rus");
	Stack s1(1), s2(2);

	s1.push('a');
	s1.push('b');
	s1.push('c');
	s2.push('d');
	s2.push('e');
	s2.push('f');

	for (int i = 0; i < 3; i++) cout << s1.pop();
	cout << endl;
	for (int i = 0; i < 3; i++) cout << s2.pop();
	cout << endl;
}
