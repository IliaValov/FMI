#include <iostream> 
#include "List.h"
#include "String.h"
using namespace std;

int main() {
	String a;
	String b;

	char* c = new char[4]{ 'a','b','c','\0' };

	a = c;
	b = c;

	if (a == b) {
		cout << "Yes";
	}

	return 0;
}
