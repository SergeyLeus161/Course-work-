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

string Order::most_expensive() {
	string res = "none";
	int max = 0;
	std::stack<Car> cars_tmp;
	while(!cars.empty()) {
		Car c = cars.top();
		if (max < c.get_price()) {
			max = c.get_price();
			res = "model=" + c.get_model() + " color=" + c.color + " date=" + c.date_of_delivery;
		}
		cars_tmp.push(cars.top());
		cars.pop();
		}
	cars = cars_tmp;
	return res;
}
