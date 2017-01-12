#include <iostream>
#include "Car.h"
#include "Parking.h"
#include "Order.h"
#include "Seller.h"
#include "Accounting.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
		Car car1("Audi", "green", "1232", 10, 20000);
		Car car2("BMW", "black", "2343", 20, 15000);
		Order order1;
		order1.cars.push(car1);
		Order order2;
		order2.cars.push(car1);
		order2.cars.push(car2);
		Order order3; 
		Order order4; 
		Order order5; 
		//cout << car1.color;
		Parking parking1;
		parking1.cars.push(car1);
		Accounting accounting1;
		accounting1.orders.push(order1);
		accounting1.orders.push(order2);
		accounting1.orders.push(order3); 
		Order order_price1;
		order_price1.cars.push(car1);
		order_price1.cars.push(car2); 
		//cout << parking1.cars.top().color;
	/*	cout << parking1.get_models().top();
		cout << parking1.cars.size(); */
	/*	cout << accounting1.get_revenue(); */
	/*	cout << order_price1.order_price(); */
		Accounting app1;
		app1.orders.push(order1);
		app1.orders.push(order2);
		app1.orders.push(order3);
		app1.orders.push(order4);
		app1.orders.push(order5);
		cout << app1.get_average_purchase_price();
	return 0;
}
//1.	Определить количество проданных автомобилей за месяц?
//2.	Какова выручка предприятия за месяц?
//3.	Какова наиболее популярная марка автомобиля по итогам опроса клиентов, по итогам продаж за месяц?
//4.	Определить какого цвета автомобили пользовались наибольшим спросом?
//5.	Определить среднее значение стоимости покупки за месяц.
//6.	Какие модели автомобиля полностью проданы? По желанию клиента сформировать заказ на приобретение. Выдать информацию о стоимости самого дорого заказа: марка автомобиля, его цвет, дата поставки.
//7.	Какой процент от продажи автомобилей добавлен к зарплате каждого из продавцов (размер процента определите самостоятельно). Определить продавца-лидера по итогам продаж за месяц.

