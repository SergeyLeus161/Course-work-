#ifndef PARKING_H
#define PARKING_H
#include <stack>
#include <string>
#include "Car.h"

using namespace std;

class Parking {
	public:
		std::stack<string> get_models();
		std::stack<Car> cars;
	protected:
};

#endif
