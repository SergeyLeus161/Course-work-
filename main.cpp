#include <iostream>
#include "Car.h"
#include "Parking.h"
#include "Order.h"
#include "Seller.h"
#include "Accounting.h"
#include "Company.h"
#include <string>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	stack<Seller> ss;
	Seller s1("n1");
	ss.push(s1);
	Seller s2("n2");
	ss.push(s2);
	Company company(ss);
	Car car("b", "b", "c", 1, 2);
	company.add_car(car);
	
	Client cl;
	Order o1 = company.prepare_order(cl);
	
	Car car2("b", "b", "c", 1, 2);
	Car car3("a", "b", "c", 1, 2);
	o1.cars.push(car);
	o1.cars.push(car2);	
	o1.cars.push(car3);
	company.save_draft(o1);
	cout << "most popular is "
		<< company.most_popular();
//	cout << company.parking.get_models().size();
//	company.checkout(o1);
//	cout << company.parking.get_models().size();
	return 0;
}
//1.	Определить количество проданных автомобилей за месяц?
//2.	Какова выручка предприятия за месяц?
//3.	Какова наиболее популярная марка автомобиля по итогам опроса клиентов, по итогам продаж за месяц?
//4.	Определить какого цвета автомобили пользовались наибольшим спросом?
//5.	Определить среднее значение стоимости покупки за месяц.
//6.	Какие модели автомобиля полностью проданы? По желанию клиента сформировать заказ на приобретение. Выдать информацию о стоимости самого дорого заказа: марка автомобиля, его цвет, дата поставки.
//7.	Какой процент от продажи автомобилей добавлен к зарплате каждого из продавцов (размер процента определите самостоятельно). Определить продавца-лидера по итогам продаж за месяц.

