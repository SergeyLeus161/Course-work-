#include "Order.h"


int Order::order_price() {
	int price;
	std::stack<Car> cars_tmp;
	while(!cars.empty()) {
		price = cars.top().get_price() + price;
		cars_tmp.push(cars.top());
		cars.pop();
		}
	cars = cars_tmp;
	return price;
}
