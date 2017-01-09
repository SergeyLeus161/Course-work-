#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "Car.h"
#include "Client.h"

using namespace std;

class Order {
	public:
		stack<Car> cars;
		Client client;
	protected:
};

#endif
