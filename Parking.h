#ifndef PARKING_H
#define PARKING_H
#include <stack>
#include <string>
#include "Car.h"

using namespace std;

class Parking {
	private:
		stack<Car> cars;
	public:
		Parking(): cars() {}
		stack<string> get_models();
		void add_car(const Car& c);
		void exclude(const Car& c);
};

#endif
