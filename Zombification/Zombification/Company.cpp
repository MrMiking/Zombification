#include "Company.h"

Company::Company() {
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < 100; i++) {
		int delay = rand() % 4 + 2;
		employees.emplace_back(i);
		employees[i].IncubationDelay(delay);
	}
}