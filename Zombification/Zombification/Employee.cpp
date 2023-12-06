#include "Employee.h"

Employee::Employee(int empId) : id(empId), infectionCounter(0), state(SANE) {
    if (empId == 0) {
        SetNewZombieficationState(INCUBATING);
        infectionCounter = 1;
    }
}

bool Employee::CheckIsZombified() {
    return getZombificationState() == ZOMBIFIED;
}

void Employee::HandleInfection() {
    if (getZombificationState() == INCUBATING) {
        infectionCounter++;
        if (infectionCounter >= incubationDelay) {
            SetNewZombieficationState(ZOMBIFIED);
        }
    }
}

void Employee::IncubationDelay(int incubationDelay) {
    this->incubationDelay = incubationDelay;
}

void Employee::SetNewZombieficationState(ZombificationState newState) {
    state = newState;
}

ZombificationState Employee::getZombificationState() const {
    return state;
}