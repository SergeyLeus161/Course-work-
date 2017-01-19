#include "Accounting.h"
#include <iostream>

Accounting::Accounting(stack<Seller> &ss) : sellers(), orders() {
	sellers = ss;
}

int Accounting::get_sold_cars_count() {
	int sold = 0;
	stack<Order> os;
	os = orders;
	while (!os.empty()) {
		sold += os.top().car_count();
		os.pop();
	}
	return sold;
}

int Accounting::get_revenue() {
	int revenue = 0;
	stack<Order> os;
	os = orders;
	while (!os.empty()) {
		Order o = os.top();
		revenue = revenue + o.order_price();
		os.pop();
	}
	return revenue;
}

int Accounting::get_average_purchase_price() {
	return get_revenue() / orders.size();
}

void Accounting::checkout(Order& o) {
	orders.push(o);

	stack<Car> cs;
	cs = o.get_cars();

	int interest = 0;
	while(!cs.empty()) {
		Car c = cs.top();
		interest += c.get_interest();
		cs.pop();
	}
	
	o.get_seller().add_salary(interest);

	stack<Seller> ss;
	while(!sellers.empty()) {
		Seller& s = sellers.top();
		if (s.get_name() == o.get_seller().get_name()) {
			s.add_salary(interest);
		}
		ss.push(s);
		sellers.pop();
	}

	while(!ss.empty()) {
		sellers.push(ss.top());
		ss.pop();
	}
}

string Accounting::get_leader_seller() {
	string leader = "none";
	int max = 0;
	stack<Seller> ss;
	ss = sellers;
	while(!sellers.empty()) {
		Seller s = sellers.top();
		if (s.get_salary() > max) {
			max = s.get_salary();
			leader = s.get_name();
		}
		sellers.pop();
	}
	return leader;
}

stack<Order> Accounting::get_orders() {
	return orders;
}
