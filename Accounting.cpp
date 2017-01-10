#include "Accounting.h"

int Accounting::get_sold_cars_count() {
	int cars;
	std::stack<Order> orders_tmp;
	while (!orders.empty()) {
		cars = orders.top().cars.size() + cars;
		orders_tmp.push(orders.top());
		orders.pop();
	}
	orders = orders_tmp;
	return cars;
}

int Accounting::get_revenue() {
	int revenue;
	std::stack<Order> orders_tmp;
	while (!orders.empty()) {
		Order o = orders.top();
		revenue = o.order_price() + revenue;
		orders_tmp.push(o);
		orders.pop();
	}
	orders = orders_tmp;
	return revenue;
}

