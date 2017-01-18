#include "Order.h"

Order::Order(Seller& s, Client& c) : seller(s), client(c), cars() {}

int Order::car_count() {
	return cars.size();
}

int Order::order_price() {
	int price;
	stack<Car> cs;
	cs = cars;
	while(!cs.empty()) {
		price = cs.top().get_price() + price;
		cs.pop();
	}
	return price;
}

string Order::most_expensive() {
	string res = "none";
	int max = 0;
	stack<Car> cs;
	cs = cars;
	while(!cs.empty()) {
		Car c = cs.top();
		if (max < c.get_price()) {
			max = c.get_price();
			res = "model=" + c.get_model() + ", color=" + c.get_color() + ", date of delivery=" + c.get_date_of_delivery();
		}
		cs.pop();
	}
	return res;
}

Seller& Order::get_seller() {
	return seller;
}

stack<Car> Order::get_cars() {
	return cars;
}

void Order::add_car(const Car& c) {
	cars.push(c);
}

