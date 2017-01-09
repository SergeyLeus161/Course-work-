#include "Accounting.h"

int Accounting::get_sold_cars_count() {
	int cars;
	std::stack<Order> orders_tmp;
	while (!orders.empty()){
		cars = orders.top().cars.size() + cars;
		orders_tmp.push(orders.top());
		orders.pop();
	}
	orders = orders_tmp;
	return cars;
}

