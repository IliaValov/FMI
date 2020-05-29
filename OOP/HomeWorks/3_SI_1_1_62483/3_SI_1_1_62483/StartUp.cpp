#include <iostream>
#include "JSONArray.h"

int main() {

	JSONArray<int> jsonArray;
	JSONArray<int> jsonArrayTest;

	jsonArrayTest.insert("keyTest", 5);


	jsonArray.insert("key", 3);
	jsonArray.insert(jsonArrayTest);

	jsonArray.Print();

	return 0;
}