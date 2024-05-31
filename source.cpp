#include <iostream>
#include "HospitalSystem.h"
#include "Patient.h"
#include "SortedQueue.h"
#include "DateTime.h"
#include "AppointmentsSchedule.h"
using namespace std;

/*
	In this hospital reservation system. We will define mainly two objects:
	1- Hospital system
	2- Patient

	Hospital system includes multiple objects:
	1- doctors: different specializations
	2- (if needed) nurses
	3- schedule of appointments

	the schedule of appointments is a sorted queue having all appointments made in the system
	sorted by their start time

	an appointment includes:
	1- start datetime
	2- end datetime
	3- patient
	4- doctor

	doctors and patients (and poteintially nurses) all inhiert from a person class
	
	
	*/

void testQueue() {
	SortedQueue<int> myQueue('\n');
	myQueue.Add(5);
	myQueue.Add(3);
	myQueue.Add(7);
	myQueue.Add(1);
	myQueue.Add(9);
	myQueue.Add(2);
	myQueue.Add(4);
	cout << myQueue << endl;
	myQueue.Remove(5);
	cout << myQueue << endl;
	myQueue.Remove(1);
	cout << myQueue << endl;
	myQueue.Remove(9);
	cout << myQueue << endl;
	myQueue.Remove(8);
	cout << myQueue << endl;
}

void testDateTime() {
	DateTime d1(2020, 5, 1, 10, 30, 0);
	DateTime d2(2020, 5, 1, 11, 20, 0);
	DateTime d3 = d2;
	d3.setHour(10);
	
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	cout << (d1 < d2) << ", should be true" << endl;
	cout << (d1 == d2) << ", should be false"  << endl;
	cout << (d1 > d2)  << ", should be false" << endl;
	cout << (d1 == d3) << ", should be false"  << endl;
	cout << (d1 < d3)  << ", should be false" << endl;
	cout << (d1 > d3)  << ", should be true" << endl;
	cout << (d1 <= d3) << ", should be false"  << endl;
	cout << (d1 >= d3) << ", should be true"  << endl;
	cout << (d1 != d3) << ", should be true"  << endl;
	cout << (d1 == d3) << ", should be false"  << endl;
	cout << (d1 != d2) << ", should be true"  << endl;
	cout << (d1 == d2) << ", should be false" << endl;

}
Appointment createAppointment(int hour, int min, int minDuration, Doctor* d, Patient* p) {
	DateTime start(2024, 5, 5, hour, min);
	DateTime end = start + DateTime(0, 0, 0, 0, minDuration);
	return Appointment(start, end, d, p);
}

void testAppointmentSchedule() {
	AppointmentsSchedule mySchedule;
	Doctor drAhmed("900", "Dr. Ahmed", "123450", 40);
	Doctor drAli("901", "Dr. Ali", "123451", 30);
	Patient p1("100", "Mohamed", "100200", 30);
	Patient p2("101", "Hassan", "100201", 40);
	Patient p3("102", "Khaled", "100202", 50);
	Patient p4("103", "Omar", "100203", 60);

	mySchedule.addAppointment(createAppointment(10, 0, 30, &drAhmed, &p1));
	mySchedule.addAppointment(createAppointment(10, 0, 30, &drAhmed, &p2));
	mySchedule.addAppointment(createAppointment(10, 10, 10, &drAhmed, &p3));
	mySchedule.addAppointment(createAppointment(10, 30, 30, &drAli, &p4));
	mySchedule.addAppointment(createAppointment(9, 0, 30, &drAli, &p4));
	cout << mySchedule << endl;


}

int main() {

	//Patient myPatient;
	//Person p;
	//testQueue();
	//testDateTime();
	//testAppointmentSchedule();

	HospitalSystem myHospital;
	myHospital.runHospitalPortal();

	return 0;
}