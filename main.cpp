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
	Seller s1("Vasya");
	ss.push(s1);
	Seller s2("Petya");
	ss.push(s2);
	
	Company company(ss);
	
	Car bmw("BMW X5", "10/2016", "blue", 10, 40000);
	company.add_car(bmw);
	Car mb("MB SLK", "11/2016", "white", 15, 40000);
	company.add_car(mb);
	Car volvo("VOLVO", "01/2016", "gray", 10, 40000);
	company.add_car(volvo);
	
	Client cl;
	Order order1 = company.prepare_order(cl);
	order1.cars.push(bmw);
	order1.cars.push(mb);	
	order1.cars.push(volvo);
	
	company.checkout(order1);
	
	Client c2;
	Order order2 = company.prepare_order(c2);
	
	company.checkout(order2);
	
	cout << "leader "
		<< company.get_leader_seller()
		<< " "
		<< order2.seller.name;
	return 0;
}
//1.	���������� ���������� ��������� ����������� �� �����?
//2.	������ ������� ����������� �� �����?
//3.	������ �������� ���������� ����� ���������� �� ������ ������ ��������, �� ������ ������ �� �����?
//4.	���������� ������ ����� ���������� ������������ ���������� �������?
//5.	���������� ������� �������� ��������� ������� �� �����.
//6.	����� ������ ���������� ��������� �������? �� ������� ������� ������������ ����� �� ������������. ������ ���������� � ��������� ������ ������ ������: ����� ����������, ��� ����, ���� ��������.
//7.	����� ������� �� ������� ����������� �������� � �������� ������� �� ��������� (������ �������� ���������� ��������������). ���������� ��������-������ �� ������ ������ �� �����.

