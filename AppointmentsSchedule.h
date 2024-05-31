#pragma once
#include "SortedQueue.h"
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"

class AppointmentsSchedule
{
public:
	AppointmentsSchedule();
	AppointmentsSchedule(const AppointmentsSchedule& appointmentsSchedule);
	~AppointmentsSchedule();
	void addAppointment(Appointment appointment);
	void removeAppointment(Appointment appointment);
	void removeAppointment(int appointmentID);
	void removeAppointment(DateTime start, DateTime end, string patientName, string doctorName);
	bool isAppointmentAvailable(Appointment appointment);
	vector<Appointment> getAllAppointments();

	friend ostream& operator<<(ostream& os, const AppointmentsSchedule& appointmentsSchedule)
	{
		os << appointmentsSchedule.allAppointments;
		return os;
	}

private:
	SortedQueue<Appointment> allAppointments;
};

AppointmentsSchedule::AppointmentsSchedule()
{
	
}

AppointmentsSchedule::AppointmentsSchedule(const AppointmentsSchedule& appointmentsSchedule)
{
	allAppointments = appointmentsSchedule.allAppointments;
}

AppointmentsSchedule::~AppointmentsSchedule()
{
}

void AppointmentsSchedule::addAppointment(Appointment appointment)
{
	if(!isAppointmentAvailable(appointment))
	{
		cout << "Doctor is not available at this time!" << endl;
		return;
	}

	allAppointments.Add(appointment);
	Doctor* doctor = (Doctor*)appointment.getAssignedDoctor();
	doctor->addAppointment(appointment);
}

void AppointmentsSchedule::removeAppointment(Appointment appointment)
{
	appointment = allAppointments.Remove(appointment);
	Doctor* doctor = (Doctor*)appointment.getAssignedDoctor();
	doctor->removeAppointment(appointment);
}

void AppointmentsSchedule::removeAppointment(int appointmentID)
{
	Appointment appointment;
	appointment.setAppointmentID(appointmentID);
	removeAppointment(appointment);
}

void AppointmentsSchedule::removeAppointment(DateTime start, DateTime end, string patientName, string doctorName)
{
	Appointment appointment;
	appointment.setStart(start);
	appointment.setEnd(end);
	Patient patient("", patientName, "", 0);
	Doctor doctor("", doctorName, "", 0);
	appointment.setAssignedPatient(&patient);
	appointment.setAssignedDoctor(&doctor);
	removeAppointment(appointment);
}

bool AppointmentsSchedule::isAppointmentAvailable(Appointment appointment)
{
	Doctor* doctor = (Doctor*) appointment.getAssignedDoctor();
	return doctor->isAvailableAt(appointment);
}

vector<Appointment> AppointmentsSchedule::getAllAppointments()
{
	return allAppointments.ToVector();
}
