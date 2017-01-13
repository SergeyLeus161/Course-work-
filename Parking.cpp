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

void Parking::exclude(const Car& c) {
	stack<Car> cars_tmp;
	stack<Car> cs = cars;
	while(!cs.empty()) {
		if (&c == &cs.top()) {
			cars_tmp.push(cs.top());
		}
		cs.pop();
	}
	cars = cars_tmp;
}
