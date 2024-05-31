#pragma once
#include "DateTime.h"

class Appointment
{
public:
	Appointment();
	Appointment(DateTime start, DateTime end, Person* assignedDoctor, Person* assignedPatient);
	Appointment(DateTime start, DateTime end);
	Appointment(const Appointment& other);
	Appointment& operator=(const Appointment& other);
	~Appointment();

	DateTime getStart() const;
	DateTime getEnd() const;
	Person* getAssignedDoctor() const;
	Person* getAssignedPatient() const;
	void setAppointmentID(int id);
	int getAppointmentID();
	void setStart(DateTime start);
	void setEnd(DateTime end);
	void setAssignedDoctor(Person* assignedDoctor);
	void setAssignedPatient(Person* assignedPatient);

	bool operator==(const Appointment& other) const;
	bool operator!=(const Appointment& other) const;
	bool operator<(const Appointment& other) const;
	bool operator>(const Appointment& other) const;
	bool operator<=(const Appointment& other) const;
	bool operator>=(const Appointment& other) const;
	bool intersects(const Appointment& other) const;
	bool isBefore(const Appointment& other) const;
	bool isAfter(const Appointment& other) const;

	DateTime getDuration() const;

	friend ostream& operator<<(ostream& os, const Appointment& appointment) {
		os << "Appointment ID: " << appointment.id << endl;
		os << "Start: " << appointment.start << endl;
		os << "End: " << appointment.end << endl;
		os << "Assigned Doctor: " << appointment.assignedDoctor->getName() << endl;
		os << "Assigned Patient: " << appointment.assignedPatient->getName() << endl;
		return os;
	}

private:
	static int idCounter;
	int id;
	void setID();
	DateTime start;
	DateTime end;
	Person* assignedDoctor;
	Person* assignedPatient;

};
int Appointment::idCounter = 0;

Appointment::Appointment()
{
	setID();
	start = DateTime();
	end = DateTime();
	assignedDoctor = nullptr;
	assignedPatient = nullptr;
}

Appointment::Appointment(DateTime start, DateTime end, Person* assignedDoctor, Person* assignedPatient)
{
	setID();
	setStart(start);
	setEnd(end);
	setAssignedDoctor(assignedDoctor);
	setAssignedPatient(assignedPatient);
}

Appointment::Appointment(DateTime start, DateTime end)
{
	setID();
	setStart(start);
	setEnd(end);
	setAssignedDoctor(nullptr);
	setAssignedPatient(nullptr);
}

Appointment::Appointment(const Appointment& other)
{
	setAppointmentID(other.id);
	setStart(other.start);
	setEnd(other.end);
	setAssignedDoctor(other.assignedDoctor);
	setAssignedPatient(other.assignedPatient);
}

Appointment& Appointment::operator=(const Appointment& other)
{
	setID();
	setStart(other.start);
	setEnd(other.end);
	setAssignedDoctor(other.assignedDoctor);
	setAssignedPatient(other.assignedPatient);
	return *this;
}

Appointment::~Appointment()
{
	// the appointment does not own the doctor or the patient pointers, so it does not delete them
	// it never uses new to create them hence it does not need to delete them
}

DateTime Appointment::getStart() const
{
	return start;
}

DateTime Appointment::getEnd() const
{
	return end;
}

Person* Appointment::getAssignedDoctor() const
{
	return assignedDoctor;
}

Person* Appointment::getAssignedPatient() const
{
	return assignedPatient;
}

void Appointment::setAppointmentID(int id)
{
	this->id = id;
}
void Appointment::setID()
{
	id = idCounter++;
}

void Appointment::setStart(DateTime start)
{
	this->start = start;
}

void Appointment::setEnd(DateTime end)
{
	// end must be greater than start
	if (end < start)
	{
		throw invalid_argument("End must be greater than start");
	}
	this->end = end;
}

void Appointment::setAssignedDoctor(Person* assignedDoctor)
{
	this->assignedDoctor = assignedDoctor;
}

void Appointment::setAssignedPatient(Person* assignedPatient)
{
	this->assignedPatient = assignedPatient;
}

bool Appointment::operator==(const Appointment& other) const
{
	return id == other.id
		|| (start == other.start 
			&& end == other.end 
			&& assignedPatient->getName() == other.assignedPatient->getName()
			&& assignedDoctor->getName() == other.assignedDoctor->getName());
}

bool Appointment::operator!=(const Appointment& other) const
{
	return !(*this == other);
}

bool Appointment::operator<(const Appointment& other) const
{
	return start < other.start;
}

bool Appointment::operator>(const Appointment& other) const
{
	return start > other.start;
}

bool Appointment::operator<=(const Appointment& other) const
{
	return !(*this > other);
}

bool Appointment::operator>=(const Appointment& other) const
{
	return !(*this < other);
}

bool Appointment::intersects(const Appointment& other) const
{
	return start < other.end && end > other.start;
}

bool Appointment::isBefore(const Appointment& other) const
{
	return end < other.start;
}

bool Appointment::isAfter(const Appointment& other) const
{
	return start > other.end;
}

DateTime Appointment::getDuration() const
{
	return end - start;
}

int Appointment::getAppointmentID()
{
	return this->id;
}