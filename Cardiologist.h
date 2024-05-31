#ifndef CARDIOLOGIST_H
#define CARDIOLOGIST_H

#include "Doctor.h"

class Cardiologist : public Doctor {
public:
    Cardiologist();
    Cardiologist(string id, string name, string phoneNumber, int age, string specialization);
    Cardiologist(const Cardiologist& p);
    ~Cardiologist();

};

Cardiologist::Cardiologist() : Doctor() {
}

Cardiologist::Cardiologist(string id, string name, string phoneNumber, int age, string specialization)
    : Doctor(id, name, phoneNumber, age) {
    setSpecialization(specialization);
}

Cardiologist::Cardiologist(const Cardiologist& p) : Doctor(p) {

}

Cardiologist::~Cardiologist() {
}

#endif // CARDIOLOGIST_H
