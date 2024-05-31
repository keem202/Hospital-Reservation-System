#ifndef ENT_H
#define ENT_H

#include "Doctor.h"

class ENT : public Doctor {
public:
    ENT();
    ENT(string id, string name, string phoneNumber, int age, string specialization);
    ENT(const ENT& p);
    ~ENT();

};

ENT::ENT() : Doctor() {

}

ENT::ENT(string id, string name, string phoneNumber, int age, string specialization)
    : Doctor(id, name, phoneNumber, age) {
    setSpecialization(specialization);
}

ENT::ENT(const ENT& p) : Doctor(p) {
}

ENT::~ENT() {
}

#endif // ENT_H
