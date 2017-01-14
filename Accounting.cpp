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

int Accounting::get_average_purchase_price() {
	return get_revenue() / orders.size();
}

void Accounting::checkout(Order o) {
	stack<Order> os;
	os = orders;
	os.push(o);
	
	
	stack<Car> cs;
	cs = o.cars;
	
	int interest = 0;
	while(!cs.empty()) {
		Car c = cs.top();
		interest = interest + c.get_interest();
		cs.pop();
	}
	
	string s_name = o.seller.name;
	
	stack<Seller> ss;
	ss = sellers;
	stack<Seller> tmp;
	while(!ss.empty()) {
		Seller s = ss.top();
		if (s.name == s_name) {
			s.salary = s.salary + interest;
		}
		tmp.push(s);
		ss.pop();
	}
	sellers = tmp;
}

string Accounting::get_leader_seller() {
	string leader = "none";
	int max;
	stack<Seller> ss;
	ss = sellers;
	while(!ss.empty()) {
		Seller s = ss.top();
		if (s.salary > max) {
			max = s.salary;
			leader = s.name;
		}
		ss.pop();
	}
	return leader;
}
