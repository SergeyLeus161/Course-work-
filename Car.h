#ifndef CAR_H
#define CAR_H
#include <string>

using namespace std;

class Car {
	private:
		string model;
		int percent;
		int price;
		string date_of_delivery;
		string color;
	public:
		Car(string m, string dod, string c, int p, int pr);
		string get_model();
		int get_price();
		int get_interest();
		string get_date_of_delivery();
		string get_color();
};

#endif
