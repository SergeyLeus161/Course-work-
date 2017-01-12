#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <stack>

using namespace std;

class Company
{
	public:
		string accounting;
		string parking;
		std::stack<string> cars_models;
		string sold_models();
	protected:
};

#endif
