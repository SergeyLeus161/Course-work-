#include <iostream>
#include "Car.h"
#include "Parking.h"
#include "Order.h"
#include "Seller.h"
#include "Accounting.h"
#include "Company.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
//сохранение продавцов
	stack<Seller> seller_saving;
	Seller s1("Vasya");
	seller_saving.push(s1);
	Seller s2("Petya");
	seller_saving.push(s2);
	
	const string sellers_file_name = "sellers.csv";

	ofstream seller_ofile(sellers_file_name.c_str());
	if (seller_ofile.is_open()) {
		seller_ofile << "Name,Salary\n";
		while(!seller_saving.empty()) {
			Seller s = seller_saving.top();
			seller_ofile << s.get_name() << ",";
			seller_ofile << s.get_salary() << "\n";
			seller_saving.pop();
		}

		seller_ofile.close();
	} else cout << "Unable to write file " + sellers_file_name;

//чтение продавцов
	stack<Seller> seller_reading;
	ifstream seller_ifile (sellers_file_name.c_str());
	if (seller_ifile.is_open()) {
		string line;
		getline(seller_ifile,line);//skip header
		while (getline(seller_ifile,line)) {
			stringstream str(line);
			string name;
			getline(str, name, ',');
			Seller slr(name);
			int salary;
			str >> salary;
			slr.add_salary(salary);
			seller_reading.push(slr);
		}
		seller_ifile.close();
	} else cout << "Unable to read file " + sellers_file_name;

	Company company(seller_reading);

//сохранение автомобилей
	stack<Car> car_saving;
	
	Car car1("BMW X5", "10/2016", "blue", 10, 40000);
	car_saving.push(car1);
	Car car2("MB SLK", "11/2016", "white", 15, 20000);
	car_saving.push(car2);
	Car car3("BMW X5", "01/2016", "pink", 10, 50000);
	car_saving.push(car3);
	Car car4("BMW X3", "01/2015", "pink", 20, 30000);
	car_saving.push(car4);
	
	string cars_file_name = "cars.csv";
	
	ofstream car_ofile (cars_file_name.c_str());
	if (car_ofile.is_open()) {
		car_ofile << "Model,Date of delivery,Color,Precent,Price\n";
		while(!car_saving.empty()) {
			Car c = car_saving.top();
			car_ofile << c.get_model() << ",";
			car_ofile << c.get_date_of_delivery()  << ",";
			car_ofile << c.get_color()  << ",";
			car_ofile << c.get_percent()  << ",";
			car_ofile << c.get_price()  << "\n";
			car_saving.pop();
		}
		car_ofile.close();
	} else cout << "Unable to write file " + cars_file_name;
	
//чтение автомобилей	
	stack<Car> car_reading;
	ifstream car_ifile(cars_file_name.c_str());
	if (car_ifile.is_open()) {
		string line;
		getline(car_ifile,line);//skip header
		
		while (getline(car_ifile,line)) {
			stringstream str(line);
			string model;
			getline(str, model, ',');
			string dod;
			getline(str, dod, ',');
			string color;
			getline(str, color, ',');
			
			string pc;
			getline(str, pc, ',');
			int percent = atoi( pc.c_str() );
			int price;
			str >> price;
			Car car(model, dod, color, percent, price);
			car_reading.push(car);
			company.add_car(car);
		}
		car_ifile.close();
	} else cout << "Unable to read file " + cars_file_name;
	
	cout << car_reading.size();
	
	Car bmw51 = car_reading.top();
	car_reading.pop();
	cout << bmw51.get_model() << " interest is correct = " << (4000 == bmw51.get_interest()) << "\n";
	Car mb = car_reading.top();
	car_reading.pop();
	Car bmw52 = car_reading.top();
	car_reading.pop();
	Car bmw3 = car_reading.top();
	car_reading.pop();
	cout << bmw3.get_model() << " interest is correct = " << (6000 == bmw3.get_interest()) << "\n";

	Client cl;
	Order order1 = company.prepare_order(cl);
	order1.add_car(bmw51);
	order1.add_car(mb);
	order1.add_car(bmw52);
	cout << order1.get_seller().get_name() << " order price is correct = " << (110000 == order1.order_price()) << "\n";

	company.checkout(order1);
	cout << order1.get_seller().get_name() << " salary is correct = " << (12000 == order1.get_seller().get_salary()) << "\n";

	Client c2;
	Order order2 = company.prepare_order(c2);
	order2.add_car(bmw3);
	cout << order2.get_seller().get_name() << " order price is correct = " << (30000 == order2.order_price())<< "\n";

	company.checkout(order2);
	cout << order2.get_seller().get_name() << " salary is correct = " << (6000 == order2.get_seller().get_salary())<< "\n";

//1.	Определить количество проданных автомобилей за месяц?
	cout << "company sold car count is correct = " << (4 == company.get_accounting().get_sold_cars_count()) << "\n";

//2.	Какова выручка предприятия за месяц?
	cout << "company revenue is correct = " << (140000 == company.get_accounting().get_revenue()) << "\n";

	Client c3;
	Order order3 = company.prepare_order(c3);
	order3.add_car(mb);
	order3.add_car(bmw3);

	company.save_draft(order3);

	Client c4;
	Order order4 = company.prepare_order(c4);
	order4.add_car(mb);

	company.save_draft(order4);

	Client c5;
	Order order5 = company.prepare_order(c5);
	order5.add_car(mb);

	company.save_draft(order5);

//3.	Какова наиболее популярная марка автомобиля по итогам опроса клиентов, по итогам продаж за месяц?
	cout << "most popular model is correct = " << (mb.get_model() == company.most_popular_model()) << "\n";
	cout << "most selling model is correct = " << (bmw51.get_model() == company.most_selling_model()) << "\n";

//4.	Определить какого цвета автомобили пользовались наибольшим спросом?
	cout << "most popular color is correct = " << ("pink" == company.most_selling_color()) << "\n";

//5.	Определить среднее значение стоимости покупки за месяц.
	cout << "average purchase price is correct = " << (70000 == company.get_accounting().get_average_purchase_price()) << "\n";

//6.	Какие модели автомобиля полностью проданы? По желанию клиента сформировать заказ на приобретение. Выдать информацию о стоимости самого дорого заказа: марка автомобиля, его цвет, дата поставки.
	cout << "sold models list is correct = " << ("MB SLK, BMW X5, BMW X3" == company.sold_models()) << "\n";
	cout << "most expensive car is correct = " << ("model=BMW X5, color=pink, date of delivery=01/2016" == order1.most_expensive()) << "\n";

//7.	Какой процент от продажи автомобилей добавлен к зарплате каждого из продавцов (размер процента определите самостоятельно). Определить продавца-лидера по итогам продаж за месяц.
	cout << "seller leader is correct = " << (order1.get_seller().get_name() == company.get_leader_seller()) << "\n";
	return 0;
}
//1.	Определить количество проданных автомобилей за месяц?
//2.	Какова выручка предприятия за месяц?
//3.	Какова наиболее популярная марка автомобиля по итогам опроса клиентов, по итогам продаж за месяц?
//4.	Определить какого цвета автомобили пользовались наибольшим спросом?
//5.	Определить среднее значение стоимости покупки за месяц.
//6.	Какие модели автомобиля полностью проданы? По желанию клиента сформировать заказ на приобретение. Выдать информацию о стоимости самого дорого заказа: марка автомобиля, его цвет, дата поставки.
//7.	Какой процент от продажи автомобилей добавлен к зарплате каждого из продавцов (размер процента определите самостоятельно). Определить продавца-лидера по итогам продаж за месяц.

