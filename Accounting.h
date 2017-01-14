#ifndef ACCOUNTING_H
#define ACCOUNTING_H
#include <string>
#include <stack>
#include "Seller.h"
#include "Order.h"

using namespace std;

class Accounting {
	public:
		stack<Seller> sellers;
		stack<Order> orders;
		string get_leader_seller();
		int get_revenue();
		string get_popular_brands();
		int get_average_purchase_price();
		int get_sold_cars_count();
		void checkout(Order o);
	protected:
};

#endif
