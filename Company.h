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
	public:
		Company(stack<Seller> ss) {
			sellers = ss;
			stack<Seller> nss;
			next_sellers = nss;
			stack<string> cms;
			cars_models = cms;
		}
		
		Accounting accounting;
		Parking parking;
		stack<string> sold_models();
		void add_car(Car c);
		Order prepareOrder(Client cl);
	protected:
};

#endif
