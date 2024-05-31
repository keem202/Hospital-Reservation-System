#ifndef DERMATOLOGIST_H
#define DERMATOLOGIST_H

#include "Doctor.h"

class Dermatologist : public Doctor {
public:
    Dermatologist();
    Dermatologist(string id, string name, string phoneNumber, int age, string specialization);
    Dermatologist(const Dermatologist& p);
    ~Dermatologist();

};

Dermatologist::Dermatologist() : Doctor() {
}

Dermatologist::Dermatologist(string id, string name, string phoneNumber, int age, string specialization)
    : Doctor(id, name, phoneNumber, age) {
    setSpecialization(specialization);
}

Dermatologist::Dermatologist(const Dermatologist& p) : Doctor(p) {
}

Dermatologist::~Dermatologist() {
}

#endif // DERMATOLOGIST_H
