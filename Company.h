#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <stack>
#include "Accounting.h"
#include "Parking.h"

using namespace std;

class Company
{
	public:
		Accounting accounting;
		Parking parking;
		std::stack<string> cars_models;
		std::stack<string> sold_models();
	protected:
};

#endif
