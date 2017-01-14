#include <iostream>
#include "Car.h"
#include "Parking.h"
#include "Order.h"
#include "Seller.h"
#include "Accounting.h"
#include "Company.h"
#include <string>

using namespace std;

int main(int argc, char** argv) {
	stack<Seller> ss;
	Seller s1("Vasya");
	cout << s1.name << " salary is correct = " << (0 == s1.salary) << "\n";
	ss.push(s1);
	Seller s2("Petya");
	cout << s2.name << " salary is correct = " << (0 == s2.salary) << "\n";
	ss.push(s2);
	
	Company company(ss);
	
	Car bmw51("BMW X5", "10/2016", "blue", 10, 40000);
	cout << bmw51.get_model() << " interest is correct = " << (4000 == bmw51.get_interest()) << "\n";
	company.add_car(bmw51);
	Car mb("MB SLK", "11/2016", "white", 15, 20000);
	company.add_car(mb);
	Car bmw52("BMW X5", "01/2016", "pink", 10, 50000);
	company.add_car(bmw52);
	Car bmw3("BMW X3", "01/2015", "pink", 20, 30000);
	cout << bmw3.get_model() << " interest is correct = " << (6000 == bmw3.get_interest()) << "\n";
	company.add_car(bmw3);
	
	Client cl;
	Order order1 = company.prepare_order(cl);
	order1.cars.push(bmw51);
	order1.cars.push(mb);	
	order1.cars.push(bmw52);
	cout << order1.seller.name << " order price is correct = " << (110000 == order1.order_price()) << "\n";
	
	company.checkout(order1);
	
	Client c2;
	Order order2 = company.prepare_order(c2);
	order2.cars.push(bmw3);
	cout << order2.seller.name << " order price is correct = " << (30000 == order2.order_price())<< "\n";
	
	company.checkout(order2);
	
//1.	Определить количество проданных автомобилей за месяц?
	cout << "company sold car count is correct = " << (4 == company.accounting.get_sold_cars_count()) << "\n";
	
//2.	Какова выручка предприятия за месяц?
	cout << "company revenue is correct = " << (140000 == company.accounting.get_revenue()) << "\n";
	
	Client c3;
	Order order3 = company.prepare_order(c3);
	order3.cars.push(mb);
	order3.cars.push(bmw3);
	
	company.save_draft(order3);
	
	Client c4;
	Order order4 = company.prepare_order(c4);
	order4.cars.push(mb);
	
	company.save_draft(order4);
	
	Client c5;
	Order order5 = company.prepare_order(c5);
	order5.cars.push(mb);
	
	company.save_draft(order5);
	
//3.	Какова наиболее популярная марка автомобиля по итогам опроса клиентов, по итогам продаж за месяц?	
	cout << "most popular model is correct = " << (mb.get_model() == company.most_popular_model()) << "\n";
	cout << "most selling model is correct = " << (bmw51.get_model() == company.most_selling_model()) << "\n";
	
//4.	Определить какого цвета автомобили пользовались наибольшим спросом?	
	cout << "most popular color is correct = " << ("pink" == company.most_selling_color()) << "\n";
	
//5.	Определить среднее значение стоимости покупки за месяц.
	cout << "average purchase price is correct = " << (70000 == company.accounting.get_average_purchase_price()) << "\n";
	
//6.	Какие модели автомобиля полностью проданы? По желанию клиента сформировать заказ на приобретение. Выдать информацию о стоимости самого дорого заказа: марка автомобиля, его цвет, дата поставки.
	cout << "sold models list is correct = " << ("BMW X3, MB SLK, BMW X5" == company.sold_models()) << "\n";
	cout << "most expensive car is correct = " << ("model=BMW X5, color=pink, date of delivery=01/2016" == order1.most_expensive()) << "\n";
	
//7.	Какой процент от продажи автомобилей добавлен к зарплате каждого из продавцов (размер процента определите самостоятельно). Определить продавца-лидера по итогам продаж за месяц.
	cout << "seller leader is correct = " << (order1.seller.name == company.get_leader_seller()) << "\n";
	return 0;
}
//1.	Определить количество проданных автомобилей за месяц?
//2.	Какова выручка предприятия за месяц?
//3.	Какова наиболее популярная марка автомобиля по итогам опроса клиентов, по итогам продаж за месяц?
//4.	Определить какого цвета автомобили пользовались наибольшим спросом?
//5.	Определить среднее значение стоимости покупки за месяц.
//6.	Какие модели автомобиля полностью проданы? По желанию клиента сформировать заказ на приобретение. Выдать информацию о стоимости самого дорого заказа: марка автомобиля, его цвет, дата поставки.
//7.	Какой процент от продажи автомобилей добавлен к зарплате каждого из продавцов (размер процента определите самостоятельно). Определить продавца-лидера по итогам продаж за месяц.

