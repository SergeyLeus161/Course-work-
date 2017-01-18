#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <stack>
#include "Accounting.h"
#include "Parking.h"
#include "Order.h"
#include "Seller.h"

using namespace std;

class Company
{
	private:
		stack<Seller> sellers;
		stack<Seller> next_sellers;
		stack<string> cars_models;
		stack<string> get_colors(stack<Order> os);
		stack<string> get_models(stack<Order> os);
		stack<string> group(stack<string> ss);
		string most_appeared(stack<string> grouped);
		stack<Order> draft_orders;
		Accounting accounting;
		Parking parking;
	public:
		Company(stack<Seller> ss);
		
		string sold_models();
		void add_car(Car c);
		Order prepare_order(Client cl);
		void save_draft(Order o);
		void checkout(Order& o);
		string most_popular_model();
		string most_selling_model();
		string get_leader_seller();
		string most_selling_color();
		Accounting get_accounting();
};

#endif
