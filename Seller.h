#ifndef SELLER_H
#define SELLER_H
#include <string>
#include "Client.h"

using namespace std;

class Seller {
	public:
		int salary = 0;
		string name;
		Seller() {
		}
		Seller(string n) {
			name = n;
		}
		void add_salary(int sum);
	protected:
};

#endif
