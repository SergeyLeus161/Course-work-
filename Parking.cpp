#include "Parking.h"

std::stack<string> Parking::get_models() {
	std::stack<string> models;
	std::stack<Car> cars_tmp;
	while(!cars.empty()) {
		models.push(cars.top().get_model());
		cars_tmp.push(cars.top());
		cars.pop();
	}
	cars = cars_tmp;
	return models;
}

void Parking::add_car(const Car& c) {
	std::stack<Car> cars_tmp = cars;
	cars_tmp.push(c);
	cars = cars_tmp;
}
