#ifndef SURGEON_H
#define SURGEON_H

#include "Doctor.h"

class Surgeon : public Doctor {
public:
    Surgeon();
    Surgeon(string id, string name, string phoneNumber, int age, string specialization);
    Surgeon(const Surgeon& p);
    ~Surgeon();
};

Surgeon::Surgeon() : Doctor() {
}

Surgeon::Surgeon(string id, string name, string phoneNumber, int age, string specialization)
    : Doctor(id, name, phoneNumber, age) {
    setSpecialization(specialization);
}

Surgeon::Surgeon(const Surgeon& p) : Doctor(p) {
}

Surgeon::~Surgeon() {
}

#endif // SURGEON_H
