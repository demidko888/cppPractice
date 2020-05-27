#include <string>
#include <iostream>

using namespace std;

struct Person {
	int age;
	string name;
	char grade;
};
Person addPerson(int age, string name, char grade);
void printPerson(Person student);


int main()
{
	Person student = addPerson(20, "Vasya", 'A');
	printPerson(student);
	return 0;
}

void printPerson(Person student) {
	cout << "Peroson's age = " << student.age << endl;
	cout << "Peroson's name = " << student.name << endl;
	cout << "Peroson's grade = " << student.grade << endl;
}

Person addPerson(int age, string name, char grade) {
	Person tmp;
	tmp.age = age;
	tmp.name = name;
	tmp.grade = grade;
	return tmp;
}