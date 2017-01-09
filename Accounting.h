#ifndef ACCOUNTING_H
#define ACCOUNTING_H
#include <string>
#include "Seller.h"
#include "Order.h"

using namespace std;

class Accounting
{
	public:
		std::stack<string> shopping_list();
		Seller get_leader_seller();
		int get_number_sold_cars();
		int get_enterprise_revenue();
		string get_popular_brands();
		string get_most_popular_color();
		int get_average_purchase_price();
		Order orders(Car c);
		int get_sold_cars_count(); 
	protected:
};

#endif
