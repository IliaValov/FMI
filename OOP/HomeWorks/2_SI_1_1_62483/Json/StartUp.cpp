#include "Json.h"


class ab {
	int y;
public:
	ab(int y = 5) {
		this->y = y;
	}

	int b() 
	{ return y; }
};


int main() {	

	ab test;

	std::cout << test.b();

	JsonObject<int> obj("Key", 2);

	Json<int> a;

	a.AddJsonObjectByKeyValue("key2", 3);

	a.AddJsonObject(obj);

	std::cout << a;

	a.PrintJsonToFile("D:/Projects/FMI/OOP/HomeWorks/2_SI_1_1_62483", "test.txt");

}