#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;


class Person
{
public:
	Person();
	Person(string id, string name, string phoneNumber, int age);
	Person(const Person& p);
	~Person();

	string getId() const;
	string getName() const;
	string getPhoneNumber() const;
	int getAge() const;

	void setId(string id);
	void setName(string name);
	void setPhoneNumber(string phoneNumber);
	void setAge(int age);
	
	bool operator==(const Person& p) const;
	bool operator!=(const Person& p) const;

	friend ostream& operator<<(ostream& os, const Person& p) {
		os << "ID: " << p.id << ", Name: " << p.name << ", Phone Number: " << p.phoneNumber << ", Age: " << p.age;
		return os;
	}


private:
	string id;
	string name;
	string phoneNumber;
	int age;
};

Person::Person() {
	id = "";
	name = "";
	phoneNumber = "";
	age = 0;
}

Person::Person(string id, string name, string phoneNumber, int age)
{
	this->id = id;
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->age = age;
}

Person::Person(const Person& p)
{
	this->id = p.id;
	this->name = p.name;
	this->phoneNumber = p.phoneNumber;
	this->age = p.age;
}

Person::~Person() 
{
}

string Person::getId() const
{
	return id;
}

string Person::getName() const
{
	return name;
}

string Person::getPhoneNumber() const
{
	return phoneNumber;
}

int Person::getAge() const
{
	return age;
}

void Person::setId(string id)
{
	this->id = id;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Person::setAge(int age)
{
	this->age = age;
}

bool Person::operator==(const Person& p) const
{
	return this->id == p.id;
}

bool Person::operator!=(const Person& p) const
{
	return this->id != p.id;
}

#endif // !PERSON_H