#include "Parking.h"

stack<string> Parking::get_models() {
	stack<string> models;
	stack<Car> cs;
	cs = cars;
	while(!cs.empty()) {
		models.push(cs.top().get_model());
		cs.pop();
	}
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
