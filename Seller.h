#ifndef SELLER_H
#define SELLER_H
#include <string>
#include "Client.h"

using namespace std;

class Seller
{
	public:
		void order_form(Client  from){ //+Сформировать_заказ(:от Клиент):Заказ
		}
		void most_expensive_order(Client from){	 //+Самый_дорогой_заказ(:от Клиент):Заказ	
		}
		int percentage_of_sales; //Атрибут(поле) Проценты_от_продаж:int 
		void sell(Order from); //+Проодть(:от Заказ):Покупка
	protected:
};

#endif
