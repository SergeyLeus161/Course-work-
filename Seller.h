#ifndef SELLER_H
#define SELLER_H
#include <string>
#include "Client.h"

using namespace std;

class Seller {
	public:
		int salary;
		string name;
		Seller() {
		}
		Seller(string n) {
			name = n;
		}
	protected:
};

#endif
