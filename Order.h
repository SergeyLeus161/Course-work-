#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "Car.h"
#include "Client.h"
#include "Seller.h"
#include <stack>

using namespace std;

class Order {
	private:
		Seller seller;
		Client client;
		stack<Car> cars;
	public:
		Order(Seller& s, Client& c);
		
		int car_count();
		int order_price();
		string most_expensive();
		Seller& get_seller();
		stack<Car> get_cars();
		void add_car(const Car& c);
};

#endif
