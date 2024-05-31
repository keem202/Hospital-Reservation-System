#pragma once
#include "Doctor.h"
#include "Nurse.h"
#include "AppointmentsSchedule.h"
#include "Patient.h"
#include "LinkedList.h"
#include <fstream>
using namespace std;

class HospitalSystem
{
public:
	HospitalSystem();
	~HospitalSystem();
	void AddDoctor(string id, string name, string phoneNumber, int age, string specialization);
	void AddNurse(string id, string name, string phoneNumber, int age);
	void AddPatient(string id, string name, string phoneNumber, int age, string patientType);
	void BookAnAppointment(string doctorId, string patientId, DateTime start, DateTime duration, int appointmentId = -1);
	void CancelAnAppointment(string doctorId, string patientId, DateTime start, DateTime duration);
	void CancelAnAppointment(int appointmentId);
	void ShowDoctorAppointments(string doctorId);
	void ShowPatientAppointments(string patientId);
	void ShowAllDoctors();
	void ShowAllNurses();
	void ShowAllPatients();
	void ShowAllAppointments();
	void ShowAllAppointmentsByDate(DateTime date);
	void runHospitalPortal();

	void loadDatabase();
	void loadDoctorsFromFile();
	void loadNursesFromFile();
	void loadPatientsFromFile();
	void loadAppointmentsFromFile();

	void saveDatabase();
	void saveDoctorsToFile();
	void saveNursesToFile();
	void savePatientsToFile();
	void saveAppointmentsToFile();


private:
	// future work to make different types of doctors
	//static Doctor* createDoctor(string specialization);
	Doctor* findDoctor(string doctorId) const;
	Patient* findPatient(string patientId) const;
	LinkedList<Doctor> doctors;
	LinkedList<Nurse> nurses;
	LinkedList<Patient> patients;
	AppointmentsSchedule fullSchedule;
};

HospitalSystem::HospitalSystem()
{
}

HospitalSystem::~HospitalSystem()
{
}

void HospitalSystem::AddDoctor(string id, string name, string phoneNumber, int age, string specialization)
{
	Doctor doctor(id, name, phoneNumber, age, specialization);
	doctors.insertEnd(doctor);
}

void HospitalSystem::AddNurse(string id, string name, string phoneNumber, int age)
{
	Nurse nurse(id, name, phoneNumber, age);
	nurses.insertEnd(nurse);
}

void HospitalSystem::AddPatient(string id, string name, string phoneNumber, int age, string patientType)
{
	Patient patient(id, name, phoneNumber, age, patientType);
	patients.insertEnd(patient);
}

void HospitalSystem::BookAnAppointment(string doctorId, string patientId, DateTime start, DateTime duration, int appointmentId)
{
	Doctor* doctor = findDoctor(doctorId);
	Patient* patient = findPatient(patientId);
	if(doctor == nullptr || patient == nullptr)
	{
		cout << "Doctor or patient not found" << endl;
		return;
	}

	DateTime end = start + duration;
	Appointment appointment(start, end, doctor, patient);
	if (appointmentId != -1)
	{
		appointment.setAppointmentID(appointmentId);
	}
	
	fullSchedule.addAppointment(appointment);
}

void HospitalSystem::CancelAnAppointment(string doctorId, string patientId, DateTime start, DateTime duration)
{
	Doctor* doctor = findDoctor(doctorId);
	Patient* patient = findPatient(patientId);
	if (doctor == nullptr || patient == nullptr)
	{
		cout << "Doctor or patient not found" << endl;
		return;
	}
	DateTime end = start + duration;
	Appointment appointment(start, end, doctor, patient);
	fullSchedule.removeAppointment(appointment);
}

void HospitalSystem::CancelAnAppointment(int appointmentId)
{
	Appointment dummy;
	dummy.setAppointmentID(appointmentId);
	fullSchedule.removeAppointment(dummy);

}
void HospitalSystem::ShowDoctorAppointments(string doctorId)
{
	Doctor* doctor = findDoctor(doctorId);
	if (doctor == nullptr)
	{
		cout << "Doctor not found" << endl;
		return;
	}

	cout << "for doctor " << doctor->getName() << " the appointments are: " << endl;
	vector<Appointment> allApps = fullSchedule.getAllAppointments();
	for (int i = 0; i < allApps.size(); i++)
	{
		if (allApps.at(i).getAssignedDoctor()->getId() == doctorId)
		{
			cout << allApps.at(i) << endl;
		}
	}
}

void HospitalSystem::ShowPatientAppointments(string patientId)
{
	Patient* patient = findPatient(patientId);
	if (patient == nullptr)
	{
		cout << "Patient not found" << endl;
		return;
	}

	cout << "for patient " << patient->getName() << " the appointments are: " << endl;
	vector<Appointment> allApps = fullSchedule.getAllAppointments();
	for (int i = 0; i < allApps.size(); i++)
	{
		if (allApps.at(i).getAssignedPatient()->getId() == patientId)
		{
			cout << allApps.at(i) << endl;
		}
	}
}

void HospitalSystem::ShowAllDoctors()
{
	cout << doctors << endl;
}

void HospitalSystem::ShowAllNurses()
{
	cout << nurses << endl;
}

void HospitalSystem::ShowAllPatients()
{
	cout << patients << endl;
}

void HospitalSystem::ShowAllAppointments()
{
	cout << fullSchedule;
}

void HospitalSystem::ShowAllAppointmentsByDate(DateTime date)
{
	vector<Appointment> allApps = fullSchedule.getAllAppointments();
	for (int i = 0; i < allApps.size(); i++)
	{
		DateTime d = allApps.at(i).getStart();
		if (d.getYear() == date.getYear() && d.getMonth() == date.getMonth() && d.getDay() == date.getDay())
		{
			cout << allApps.at(i) << endl;
		}
	}
}

void HospitalSystem::runHospitalPortal()
{
	loadDatabase();
	int choice, age, minDuration, appointmentId;
	string id, name, phoneNumber, specialization, type, doctorId, patientId;
	DateTime start, duration, date;
	char c;
	do
	{
		cout << "----------------------------------------------" << endl;
		cout << "1. Add Doctor" << endl;
		cout << "2. Add Nurse" << endl;
		cout << "3. Add Patient" << endl;
		cout << "4. Book an appointment" << endl;
		cout << "5. Cancel an appointment" << endl;
		cout << "6. Show doctor appointments" << endl;
		cout << "7. Show patient appointments" << endl;
		cout << "8. Show all doctors" << endl;
		cout << "9. Show all nurses" << endl;
		cout << "10. Show all patients" << endl;
		cout << "11. Show all appointments" << endl;
		cout << "12. Show all appointments by date" << endl;
		cout << "13. Exit" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:					//1. Add Doctor
			cout << "Enter doctor id: ";
			cin >> id;
			cout << "Enter doctor name: ";
			cin >> name;
			cout << "Enter doctor phone number: ";
			cin >> phoneNumber;
			cout << "Enter doctor age: ";
			cin >> age;
			cout << "Enter doctor specialization: ";
			cin >> specialization;
			AddDoctor(id, name, phoneNumber, age, specialization);
			break;
		case 2:					//2. Add Nurse
			cout << "Enter nurse id: ";
			cin >> id;
			cout << "Enter nurse name: ";
			cin >> name;
			cout << "Enter nurse phone number: ";
			cin >> phoneNumber;
			cout << "Enter nurse age: ";
			cin >> age;
			AddNurse(id, name, phoneNumber, age);
			break;
		case 3:					//3. Add Patient
			cout << "Enter patient id: ";
			cin >> id;
			cout << "Enter patient name: ";
			cin >> name;
			cout << "Enter patient phone number: ";
			cin >> phoneNumber;
			cout << "Enter patient age: ";
			cin >> age;
			cout << "Enter patient type: ";
			cin >> type;
			AddPatient(id, name, phoneNumber, age, type);
			break;
		case 4:					//4. Book an appointment
			cout << "Enter doctor id: ";
			cin >> doctorId;
			cout << "Enter patient id: ";
			cin >> patientId;
			cout << "Enter appointment start date: ";
			DateTime::EnterDateTime(start);
			cout << "Enter appointment duration in minutes: ";
			cin >> minDuration;
			duration = DateTime(0, 0, 0, 0, minDuration);
			BookAnAppointment(doctorId, patientId, start, duration);
			break;
		case 5:					//5. Cancel an appointment
			cout << "do you know the appointment id? enter Y if yes" << endl;
			cin >> c;
			if (c == 'Y')
			{
				cout << "Enter appointment id: ";
				cin >> appointmentId;
				CancelAnAppointment(appointmentId);
				break;
			}
			cout << "Enter doctor id: ";
			cin >> doctorId;
			cout << "Enter patient id: ";
			cin >> patientId;
			cout << "Enter appointment start date: ";
			DateTime::EnterDateTime(start);
			cout << "Enter appointment duration in minutes: ";
			cin >> minDuration;
			duration = DateTime(0, 0, 0, 0, minDuration);
			CancelAnAppointment(doctorId, patientId, start, duration);
			break;
		case 6:					//6. Show doctor appointments
			cout << "Enter doctor id: ";
			cin >> doctorId;
			ShowDoctorAppointments(doctorId);
			break;
		case 7:					//7. Show patient appointments
			cout << "Enter patient id: ";
			cin >> patientId;
			ShowPatientAppointments(patientId);
			break;
		case 8:					//8. Show all doctors
			ShowAllDoctors();
			break;
		case 9:					//9. Show all nurses
			ShowAllNurses();
			break;
		case 10:				//10. Show all patients
			ShowAllPatients();
			break;
		case 11:				//11. Show all appointments
			ShowAllAppointments();
			break;
		case 12:				//12. Show all appointments by date
			cout << "Enter date: ";
			DateTime::EnterDateTime(date);
			ShowAllAppointmentsByDate(date);
			break;
		case 13:				//13. Exit
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 13);
	
	saveDatabase();
}

void HospitalSystem::loadDatabase()
{
	loadDoctorsFromFile();
	loadNursesFromFile();
	loadPatientsFromFile();
	loadAppointmentsFromFile();
}

void HospitalSystem::loadDoctorsFromFile()
{
	ifstream input;
	string fname = "doctors.txt";
	input.open(fname);
	string id, name, phoneNumber, specialization;
	int age;
	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> id >> name >> phoneNumber >> age >> specialization;
			if (name != "")
			{
				AddDoctor(id, name, phoneNumber, age, specialization);
			}
			name = "";
		}
	}
	else
	{
		cout << fname << ": file not found" << endl;
	}
	input.close();

}

void HospitalSystem::loadNursesFromFile()
{
	ifstream input;
	string fname = "nurses.txt";
	input.open(fname);
	string id, name, phoneNumber;
	int age;
	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> id >> name >> phoneNumber >> age;
			if (name != "")
			{
				AddNurse(id, name, phoneNumber, age);
			}
			name = "";
		}
	}
	else
	{
		cout << fname << ": file not found" << endl;
	}
	input.close();
}

void HospitalSystem::loadPatientsFromFile()
{
	ifstream input;
	string fname = "patients.txt";
	input.open(fname);
	string id, name, phoneNumber, type;
	int age;
	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> id >> name >> phoneNumber >> age >> type;
			if (name != "")
			{
				AddPatient(id, name, phoneNumber, age, type);
			}
			name = "";
		}
	}
	else
	{
		cout << fname << ": file not found" << endl;
	}
	input.close();
}

void HospitalSystem::loadAppointmentsFromFile()
{
	ifstream input;
	string fname = "appointments.txt";
	input.open(fname);
	string doctorId, patientId;
	int appointmentId, year, month, day, hour, minute, duration;
	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> appointmentId >> doctorId >> patientId >> year >> month >> day >> hour >> minute >> duration;
			DateTime start(year, month, day, hour, minute);
			DateTime dur(0, 0, 0, 0, duration);
			if (doctorId != "")
			{
				BookAnAppointment(doctorId, patientId, start, dur, appointmentId);
			}
			doctorId = "";
		}
	}
	else
	{
		cout << fname << ": file not found" << endl;
	}
	input.close();
}

void HospitalSystem::saveDatabase()
{
	saveDoctorsToFile();
	saveNursesToFile();
	savePatientsToFile();
	saveAppointmentsToFile();
}

void HospitalSystem::saveDoctorsToFile()
{
	ofstream output;
	string fname = "doctors.txt";
	output.open(fname);
	if (output.is_open())
	{
		vector<Doctor> allDoctors = doctors.toVector();
		for (int i = 0; i < allDoctors.size(); i++)
		{
			output << allDoctors.at(i).getId() << " " 
				<< allDoctors.at(i).getName() << " " 
				<< allDoctors.at(i).getPhoneNumber() << " " 
				<< allDoctors.at(i).getAge() << " " 
				<< allDoctors.at(i).getSpecialization() << endl;
		}
	}
	output.close();
}

void HospitalSystem::saveNursesToFile()
{
	ofstream output;
	string fname = "nurses.txt";
	output.open(fname);
	if (output.is_open())
	{
		vector<Nurse> allNurses = nurses.toVector();
		for (int i = 0; i < allNurses.size(); i++)
		{
			output << allNurses.at(i).getId() << " "
				<< allNurses.at(i).getName() << " "
				<< allNurses.at(i).getPhoneNumber() << " "
				<< allNurses.at(i).getAge() << endl;
		}
	}
	output.close();
}

void HospitalSystem::savePatientsToFile()
{
	ofstream output;
	string fname = "patients.txt";
	output.open(fname);
	if (output.is_open())
	{
		vector<Patient> allPatients = patients.toVector();
		for (int i = 0; i < allPatients.size(); i++)
		{
			output << allPatients.at(i).getId() << " "
				<< allPatients.at(i).getName() << " "
				<< allPatients.at(i).getPhoneNumber() << " "
				<< allPatients.at(i).getAge() << " "
				<< allPatients.at(i).getPatientType() << endl;
		}
	}
	output.close();
}

void HospitalSystem::saveAppointmentsToFile()
{
	ofstream output;
	string fname = "appointments.txt";
	output.open(fname);
	if (output.is_open())
	{
		vector<Appointment> allApps = fullSchedule.getAllAppointments();
		for (int i = 0; i < allApps.size(); i++)
		{
			output << allApps.at(i).getAppointmentID() << " "
				<< allApps.at(i).getAssignedDoctor()->getId() << " "
				<< allApps.at(i).getAssignedPatient()->getId() << " "
				<< allApps.at(i).getStart().getYear() << " "
				<< allApps.at(i).getStart().getMonth() << " "
				<< allApps.at(i).getStart().getDay() << " "
				<< allApps.at(i).getStart().getHour() << " "
				<< allApps.at(i).getStart().getMinute() << " "
				<< allApps.at(i).getDuration().ToMinutes() << endl;
		}
	}
	output.close();
}

Doctor* HospitalSystem::findDoctor(string doctorId) const
{
	Doctor dummy(doctorId, "", "", 0, "");
	return doctors.LocateElement(dummy);
}

Patient* HospitalSystem::findPatient(string patientId) const
{
	Patient dummy(patientId, "", "", 0, "");
	return patients.LocateElement(dummy);
}

