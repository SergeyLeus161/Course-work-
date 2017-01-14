#ifndef CAR_H
#define CAR_H
#include <string>

using namespace std;

class Car {
	private:
		string model;
		int percent;
		int price;
	public:
		Car(string m, string dod, string c, int p, int pr);
		string get_model() {
			return model;
		}
		int get_price() {
			return price;
		}
		int get_interest() {
			int interest;
			interest = ((price / 100) * percent);
			return interest;
		}
		
		string date_of_delivery;
		string color;
};

#endif
