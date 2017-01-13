#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "Car.h"
#include "Client.h"
#include "Seller.h"
#include <stack>

using namespace std;

class Order {
	public:
		Seller seller;
		stack<Car> cars;
		Client client;
		int order_price();
		bool sold;
	protected:
};

#endif
