#ifndef ACCOUNTING_H
#define ACCOUNTING_H
#include <string>

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
	protected:
};

#endif
