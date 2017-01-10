#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "Car.h"
#include "Client.h"
#include <stack>

using namespace std;

class Order {
	public:
		std::stack<Car> cars;
		Client client;
	protected:
};

#endif
