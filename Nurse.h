#pragma once
#include "Person.h"
class Nurse : public Person
{
public:
	Nurse();
	Nurse(string id, string name, string phoneNumber, int age);
	~Nurse();

private:

};

Nurse::Nurse(): Person()
{
}

Nurse::Nurse(string id, string name, string phoneNumber, int age) : Person(id, name, phoneNumber, age)
{
}

Nurse::~Nurse()
{
}
