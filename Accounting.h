#ifndef ACCOUNTING_H
#define ACCOUNTING_H
#include <string>
#include <stack>
#include "Seller.h"
#include "Order.h"

using namespace std;

class Accounting {
	public:
		std::stack<Order> orders;
		Seller get_leader_seller();
		int get_revenue();
		string get_popular_brands();
		string get_most_popular_color();
		int get_average_purchase_price();
		int get_sold_cars_count();
	protected:
};

#endif
