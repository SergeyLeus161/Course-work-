#include "Car.h"
#include <string>

Car::Car(string m, string dod, string c, int p, int pr) :
	model(m),
	date_of_delivery(dod),
	color(c),
	percent(p),
	price(pr) {}
	
string Car::get_model()	{
	return model;
}

int Car::get_price() {
	return price;
}

int Car::get_interest() {
	int interest((price / 100) * percent);
	return interest;
}

string Car::get_date_of_delivery() {
	return date_of_delivery;
}

string Car::get_color() {
	return color;
}
