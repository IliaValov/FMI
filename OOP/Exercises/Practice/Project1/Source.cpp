#include <iostream>
using namespace std;

struct Subject
{
	char name[100];
	int grade;
};
struct Student
{
	int FN;
	Subject subject[10];
};

int findAverage(Student);
int main()
{
	Student persons[10];

	for (int i = 0; i < 2; i++)
	{
		cout << "Student: " << i << "\r\n";
		cout << "fn"; cin >> persons[i].FN;
		for (int j = 0; j < 2; j++)
		{
			cin.ignore();
			cin.getline(persons[i].subject[j].name, 100);
		
			cin >> persons[i].subject[j].grade;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << persons[i].subject[j].name;
		}
		cout << "the average from the grades: " << findAverage(persons[i]);
	}

	return 0;
}
int findAverage(Student person)
{
	int sum = 0;
	int counter = 1;
	for (int i = 0; i <2; i++)
	{
		sum = (sum + person.subject[i].grade)/counter;
		counter++;
	}
	return sum;
}