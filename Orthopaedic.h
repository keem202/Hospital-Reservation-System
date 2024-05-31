#ifndef ORTHOPAEDIC_H
#define ORTHOPAEDIC_H

#include "Doctor.h"

class Orthopaedic : public Doctor {
public:
    Orthopaedic();
    Orthopaedic(string id, string name, string phoneNumber, int age, string specialization);
    Orthopaedic(const Orthopaedic& p);
    ~Orthopaedic();

};

Orthopaedic::Orthopaedic() : Doctor() {
}

Orthopaedic::Orthopaedic(string id, string name, string phoneNumber, int age, string specialization)
    : Doctor(id, name, phoneNumber, age) {
    setSpecialization(specialization);
}

Orthopaedic::Orthopaedic(const Orthopaedic& p) : Doctor(p) {
}

Orthopaedic::~Orthopaedic() {
}

#endif // ORTHOPAEDIC_H
