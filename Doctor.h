#pragma once
#include "Person.h"
#include "Appointment.h"
#include <vector>

class Doctor: public Person
{
public:
	Doctor();	
	Doctor(string id, string name, string phoneNumber, int age, string specialization = "");
	Doctor(const Doctor& p);
	~Doctor();

	void setSpecialization(string specialization);
	string getSpecialization() const;

	void addAppointment(Appointment appointment);
	void removeAppointment(Appointment appointment);
	bool isAvailableAt(Appointment appointment) const;

	friend ostream& operator<<(ostream& os, const Doctor& d) {
		os << "Dr. " << d.getName() << ", ID: " << d.getId() <<": specializing in: " << d.getSpecialization();
		return os;
	}

private:
	string specialization;
	vector<Appointment> appointments;
};


Doctor::Doctor(): Person()
{
}

Doctor::Doctor(string id, string name, string phoneNumber, int age, string specialization): Person(id, name, phoneNumber, age)
{
	setSpecialization(specialization);
}

Doctor::Doctor(const Doctor& p): Person(p)
{
	setSpecialization(p.specialization);
}

Doctor::~Doctor()
{
}

void Doctor::setSpecialization(string specialization)
{
	this->specialization = specialization;
}

string Doctor::getSpecialization() const
{
	return specialization;
}

void Doctor::addAppointment(Appointment appointment)
{
	appointments.push_back(appointment);
}

void Doctor::removeAppointment(Appointment appointment)
{
	for (int i = 0; i < appointments.size(); i++)
	{
		if (appointments[i] == appointment)
		{
			appointments.erase(appointments.begin() + i);
			break;
		}
	}
}

bool Doctor::isAvailableAt(Appointment appointment) const
{
	for (int i = 0; i < appointments.size(); i++)
	{
		if (appointments[i].intersects(appointment))
		{
			return false;
		}
	}
	return true;
}

