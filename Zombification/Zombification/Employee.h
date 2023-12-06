#include "GlobalHeader.h"

enum ZombificationState {
    SANE,
    INCUBATING,
    ZOMBIFIED
};

class Employee {
public:
    int id;
    int infectionCounter;
    int incubationDelay;
    ZombificationState state;

    Employee(int emId);

    bool CheckIsZombified();

    void HandleInfection();

    void IncubationDelay(int incubationDelay);

    void SetNewZombieficationState(ZombificationState newState);

    ZombificationState getZombificationState() const;
};

