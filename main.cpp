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
		order1.cars.push(car1);
		//cout << car1.color;
		Parking parking1;
		parking1.cars.push(car1);
		Accounting accounting1;
		accounting1.orders.push(order1);
		accounting1.orders.push(order1); 
		Order order_price1;
		order_price1.cars.push(car1);
		order_price1.cars.push(car2);
		//cout << parking1.cars.top().color;
	/*	cout << parking1.get_models().top();
		cout << parking1.cars.size(); */
	/*	cout << accounting1.get_revenue(); */
		cout << order_price1.order_price();
	return 0;
}
//1.	���������� ���������� ��������� ����������� �� �����?
//2.	������ ������� ����������� �� �����?
//3.	������ �������� ���������� ����� ���������� �� ������ ������ ��������, �� ������ ������ �� �����?
//4.	���������� ������ ����� ���������� ������������ ���������� �������?
//5.	���������� ������� �������� ��������� ������� �� �����.
//6.	����� ������ ���������� ��������� �������? �� ������� ������� ������������ ����� �� ������������. ������ ���������� � ��������� ������ ������ ������: ����� ����������, ��� ����, ���� ��������.
//7.	����� ������� �� ������� ����������� �������� � �������� ������� �� ��������� (������ �������� ���������� ��������������). ���������� ��������-������ �� ������ ������ �� �����.

