#include "Parking.h"

stack<string> Parking::get_models() {
	stack<string> models;
	stack<Car> cars_tmp;
	while(!cars.empty()) {
		models.push(cars.top().get_model());
		cars_tmp.push(cars.top());
		cars.pop();
	}
	cars = cars_tmp;
	return models;
}

void Parking::add_car(const Car& c) {
	cars.push(c);
}
