#include <iostream>
#include "FileSystem.h"

int main() {
	Date date;

	File a("File", ".tg",date , 34);

	FileSystem test;

	test.AddFileToFolder(a, "C:/");
	test.CreateFolder("test", date, "C:/");
	test.AddFileToFolder(a, "C:/test/");

	std::cout << test.FindFileFromFolder("File", "C:/test/").GetName();
}