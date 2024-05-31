#pragma once
#include "Person.h"

class Patient : public Person
{
public:
	Patient();
	Patient(string id, string name, string phoneNumber, int age, string patientType = "");
	Patient(const Patient& p);
	~Patient();

	void setPatientType(string patientType);
	string getPatientType() const;

private:
	string patientType;
};

Patient::Patient() : Person()
{
}

Patient::Patient(string id, string name, string phoneNumber, int age, string patientType) : Person(id, name, phoneNumber, age)
{
	setPatientType(patientType);
}

Patient::Patient(const Patient& p) : Person(p)
{
	setPatientType(p.patientType);
}

Patient::~Patient()
{
}

void Patient::setPatientType(string patientType)
{
	this->patientType = patientType;
}

string Patient::getPatientType() const
{
	return patientType;
}

