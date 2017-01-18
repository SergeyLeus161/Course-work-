#ifndef SELLER_H
#define SELLER_H
#include <string>
#include "Client.h"

using namespace std;

class Seller {
	private:
		int salary;
		string name;
	public:
		Seller();
		
		Seller(string n);
		void add_salary(int sum);
		int get_salary();
		string get_name();
};

#endif
