#ifndef PARKING_H
#define PARKING_H
#include <stack>
#include <string>
#include "Car.h"

using namespace std;

class Parking {
	public:
		Parking() {
			stack<Car> cs;
			cars = cs;
		}
		stack<string> get_models();
		stack<Car> cars;
		void add_car(const Car& c);
	protected:
};

#endif
