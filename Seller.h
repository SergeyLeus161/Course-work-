#ifndef SELLER_H
#define SELLER_H
#include <string>

using namespace std;

class Seller
{
	public:
		void order_form(Client  from){ //+������������_�����(:�� ������):�����
		}
		void most_expensive_order(Client from){	 //+�����_�������_�����(:�� ������):�����	
		}
		int percentage_of_sales; // �������(����)  ��������_��_������:int
		void sell(Order from); //+�������(:�� �����):�������
	protected:
};

#endif
