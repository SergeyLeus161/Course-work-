#include "Seller.h"

Seller::Seller() : salary(0) {}

Seller::Seller(string n) : salary(0), name(n) {}

string Seller::get_name() {
	return name;
}

void Seller::add_salary(int sum) {
	salary += sum;
}

int Seller::get_salary() {
	return salary;
}
