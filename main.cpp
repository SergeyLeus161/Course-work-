#include <iostream>
#include "Car.h"
#include "Parking.h"
#include "Order.h"
#include "Seller.h"
#include "Accounting.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
		Car car1("audi", "green", "1232", 10);
		Order order1;
		order1.cars.push(car1);
		order1.cars.push(car1);
		//cout << car1.color;
		Parking parking1;
		parking1.cars.push(car1);
		Accounting accounting1;
		accounting1.orders.push(order1);
		accounting1.orders.push(order1);
		//cout << parking1.cars.top().color;
	/*	cout << parking1.get_models().top();
		cout << parking1.cars.size(); */
		cout << accounting1.get_sold_cars_count();
	return 0;
}
//1.	Определить количество проданных автомобилей за месяц?
//2.	Какова выручка предприятия за месяц?
//3.	Какова наиболее популярная марка автомобиля по итогам опроса клиентов, по итогам продаж за месяц?
//4.	Определить какого цвета автомобили пользовались наибольшим спросом?
//5.	Определить среднее значение стоимости покупки за месяц.
//6.	Какие модели автомобиля полностью проданы? По желанию клиента сформировать заказ на приобретение. Выдать информацию о стоимости самого дорого заказа: марка автомобиля, его цвет, дата поставки.
//7.	Какой процент от продажи автомобилей добавлен к зарплате каждого из продавцов (размер процента определите самостоятельно). Определить продавца-лидера по итогам продаж за месяц.

