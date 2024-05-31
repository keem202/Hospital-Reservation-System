#ifndef UROLOGIST_H
#define UROLOGIST_H

#include "Doctor.h"

class Urologist : public Doctor {
public:
    Urologist();
    Urologist(string id, string name, string phoneNumber, int age, string specialization);
    Urologist(const Urologist& p);
    ~Urologist();

};

Urologist::Urologist() : Doctor() {
}

Urologist::Urologist(string id, string name, string phoneNumber, int age, string specialization)
    : Doctor(id, name, phoneNumber, age) {
        setSpecialization(specialization);

}

Urologist::Urologist(const Urologist& p) : Doctor(p) {
}

Urologist::~Urologist() {

}

#endif // UROLOGIST_H
