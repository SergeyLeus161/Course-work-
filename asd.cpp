#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <stack>
#include <iostream>
using namespace std;
//для стеков//////////////////////////////
template <class T> //очистка стека
void clear(T& cont) {
	while (!cont.empty()) {
		cont.pop();
	}
}
template <class T> //вывод содержимого стека
void outt(stack<T> ss) {
	while(ss.size()-1) {
		ss.pop();
		cout<< ss.top()<<endl;
	}
}
template <class T> //получение элемента по индексу
T getElem(stack<T> st, int ind) {
	for(int i=1; i<=ind; i++) {
		st.pop();
	}
	T temp = st.top();
	return temp;
}
template <class T> //получение адреса элемента по индексу
T *getElemPtr(stack<T> st, int ind) {
	for(int i=1; i<=ind; i++) {
		st.pop();
	}
	T *temp = &st.top();
	return temp;
}
//для стеков//////////////////////////////

/////////////////////////////////////////////////////////////////
class transp {
	protected:
		string mark;
		int year;
		string color;
		string numb;
		int ride;
		float price;
		int in_rent; //период аренды
		int ride_in_month; //месячный пробег
	public:
		transp():
			mark("NoMark"),
			year(0),
			color("NoColor"),
			numb("NoNumb"),
			ride(0),
			price(0.0),
			in_rent(0),
			ride_in_month(0) {}
		virtual int ride_per_rent(int r) = 0;
//getters
		string getMark() {
			return mark;
		}
		int getYear() {
			return year;
		}
		string getColor() {
			return color;
		}
		string getNumb() {
			return numb;
		}
		int getRide() {
			return ride;
		}
		float getPrice() {
			return price;
		}
		int getInRent() {
			return in_rent;
		}
		int getRideInMonth() {
			return ride_in_month;
		}
//setters
		void setMark(string x) {
			mark = x;
		}
		void setYear(int x) {
			year = x;
		}
		9
		void setColor(string x) {
			color = x;
		}
		void setNumb(string x) {
			numb = x;
		}
		void setRide(int x) {
			ride = x;
		}
		void setPrice(float x) {
			price = x;
		}
		void setInRent(int x) {
			in_rent = x;
		}
		void setRideInMonth(int x) {
			ride_in_month = x;
		}
};
/////////////////////////////////////////////////////////////////
class car: public transp {
	private:
		int places;
	public:
		car(): transp(), places(0) {}
		int getPlaces() {
			return places;
		}
		void setPlaces(int x) {
			places = x;
		}
		void readFromFile(stack<car> &ss);
		friend ostream& operator<<(ostream &stream, car &d);
		friend istream& operator>>(istream &stream, car &d);
		friend void del_car(string);
		int ride_per_rent(int r) {
			return r;
		}
};
void car::readFromFile(stack<car> &ss) {
	ifstream file("cars.txt");
	car p;
	char buffer[100];
	while(!file.eof()) {
		file.getline(buffer, 100);
		p.mark = buffer;
		file.getline(buffer, 50);
		p.color = buffer;
		file.getline(buffer, 50);
		10
		p.numb = buffer;
		file.getline(buffer, 50);
		p.year = atoi(buffer);
		file.getline(buffer, 50);
		p.ride = atoi(buffer);
		file.getline(buffer, 50);
		p.price = atof(buffer);
		file.getline(buffer, 50);
		p.places = atoi(buffer);
		ss.push(p);
	}
	file.close();
}
ostream& operator<<(ostream& stream, car &d) {
	stream <<setw(20)<<d.mark
	       <<setw(10)<<d.year
	       <<setw(15)<<d.color
	       <<setw(12)<<d.numb
	       <<setw(15)<<d.ride
	       <<setw(15)<<d.price
	       <<setw(15)<<d.places;
	return stream;
}
istream& operator>>(istream &stream, car &d) {
	cout<<setw(40)<<"Введите марку\t";
	getline(stream, d.mark);
	cout<<setw(40)<<"Введите цвет\t";
	getline(stream, d.color);
	cout<<setw(40)<<"Введите номер\t";
	getline(stream, d.numb);
	cout<<setw(40)<<"Введите год выпуска\t";
	stream>>d.year;
	cout<<setw(40)<<"Введите пробег\t";
	stream>>d.ride;
	cout<<setw(40)<<"Введите стоимость суточной аренды\t";
	stream>>d.price;
	cout<<setw(40)<<"Введите количество мест\t";
	stream>>d.places;
	ofstream file("cars.txt", ios_base::app);
	file<<d.mark<<"\n";
	file<<d.color<<"\n";
	file<<d.numb<<"\n";
	file<<d.year<<"\n";
	file<<d.ride<<"\n";
	file<<d.price<<"\n";
	11
	file<<d.places<<"\n";
	file.close();
	return stream;
}
void del_car(string number) {
	ifstream file("cars.txt");
	stack<car> ss;
	car *p[100];
	int i = 0;
	char buffer[100];
	while(!file.eof()) {
		p[i] = new car;
		file.getline(buffer, 100);
		p[i]->mark = buffer;
		file.getline(buffer, 50);
		p[i]->color = buffer;
		file.getline(buffer, 50);
		p[i]->numb = buffer;
		file.getline(buffer, 50);
		p[i]->year = atoi(buffer);
		file.getline(buffer, 50);
		p[i]->ride = atoi(buffer);
		file.getline(buffer, 50);
		p[i]->price = atof(buffer);
		file.getline(buffer, 50);
		p[i]->places = atoi(buffer);
		if(p[i]->numb != number) {
			ss.push(*p[i]);
			i++;
		}
	}
	file.close();
	ofstream fil("cars.txt");
	int j = 0;
	while(j < i-1) {
		fil<<p[j]->mark<<"\n";
		fil<<p[j]->color<<"\n";
		fil<<p[j]->numb<<"\n";
		fil<<p[j]->year<<"\n";
		fil<<p[j]->ride<<"\n";
		fil<<p[j]->price<<"\n";
		fil<<p[j]->places<<"\n";
		j++;
	}
	fil.close();
}
/////////////////////////////////////////////////////////////////

class bike: public transp {
	private:
		string type; //харлей - чоппер эндурро	спортбайк кроссовый
	public:
		bike(): transp(), type("NoType") {}
		string getType() {
			return type;
		}
		void setType(string x) {
			type = x;
		}
		void readFromFile(stack<bike> &ss);
		friend ostream& operator<<(ostream &stream, bike &d);
		friend istream& operator>>(istream &stream, bike &d);
		friend void del_bike(string number);
		int ride_per_rent(int r) {
			return r;
		}
};
void bike::readFromFile(stack<bike> &ss) {
	ifstream file("bikes.txt");
	bike p;
	char buffer[100];
	while(!file.eof()) {
		file.getline(buffer, 100);
		p.mark = buffer;
		file.getline(buffer, 50);
		p.color = buffer;
		file.getline(buffer, 50);
		p.numb = buffer;
		file.getline(buffer, 50);
		p.year = atoi(buffer);
		file.getline(buffer, 50);
		p.ride = atoi(buffer);
		file.getline(buffer, 50);
		p.price = atof(buffer);
		file.getline(buffer, 50);
		p.type = buffer;
		ss.push(p);
	}
	file.close();
}
ostream& operator<<(ostream& stream, bike &d) {
	stream <<setw(20)<<d.mark
	       <<setw(10)<<d.year
	       <<setw(15)<<d.color
	       <<setw(12)<<d.numb
	       <<setw(15)<<d.ride
	       <<setw(15)<<d.price
	       <<setw(15)<<d.type;
	return stream;
}
istream& operator>>(istream &stream, bike &d) {
	cout<<setw(40)<<"Введите марку\t";
	getline(stream, d.mark);
	cout<<setw(40)<<"Введите цвет\t";
	getline(stream, d.color);
	cout<<setw(40)<<"Введите номер\t";
	getline(stream, d.numb);
	cout<<setw(40)<<"Введите год выпуска\t";
	stream>>d.year;
	cout<<setw(40)<<"Введите пробег\t";
	stream>>d.ride;
	cout<<setw(40)<<"Введите стоимость часовой аренды\t";
	stream>>d.price;
	cout<<setw(40)<<"Введите тип мотоцикла\t";
	stream>>d.type;
	ofstream file("bikes.txt", ios_base::app);
	file<<d.mark<<"\n";
	file<<d.color<<"\n";
	file<<d.numb<<"\n";
	file<<d.year<<"\n";
	file<<d.ride<<"\n";
	file<<d.price<<"\n";
	file<<d.type<<"\n";
	file.close();
	return stream;
}
void del_bike(string number) {
	ifstream file("bikes.txt");
	bike *p[100];
	stack<bike> ss;
	int i = 0;
	char buffer[100];
	while(!file.eof()) {
		p[i] = new bike;
		file.getline(buffer, 100);
		p[i]->mark = buffer;
		file.getline(buffer, 50);
		p[i]->color = buffer;
		file.getline(buffer, 50);
		p[i]->numb = buffer;
		file.getline(buffer, 50);
		p[i]->year = atoi(buffer);
		file.getline(buffer, 50);
		p[i]->ride = atoi(buffer);
		file.getline(buffer, 50);
		p[i]->price = atof(buffer);
		file.getline(buffer, 50);
		p[i]->type = buffer;
		if(p[i]->numb != number) {
			ss.push(*p[i]);
			i++;
		}
	}
	file.close();
	ofstream fil("bikes.txt");
	int j = 0;
	while(j < i-1) {
		fil<<p[j]->mark<<"\n";
		fil<<p[j]->color<<"\n";
		fil<<p[j]->numb<<"\n";
		fil<<p[j]->year<<"\n";
		fil<<p[j]->ride<<"\n";
		fil<<p[j]->price<<"\n";
		fil<<p[j]->type<<"\n";
		j++;
	}
	fil.close();
}
/////////////////////////////////////////////////////////////////
class Date {
		int day;
		int month;
		int year;
		int days_in_month[13];
	public:
		Date();
		Date(int day, int month, int year);
		Date& operator--();
		friend ostream& operator<<(ostream&, Date&);
};
Date::Date() {
	15
	int d_in_m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for(int i=0; i<13; i++)
		days_in_month[i] = d_in_m[i];
	const char* now = __DATE__; //получаем текущую дату
	int month;
	char m[4];
	m[0] = now[0];
	m[1] = now[1];
	m[2] = now[2];
	m[3] = '\0';
	if(!strcmp(m, "Jan"))
		month = 1;
	if(!strcmp(m, "Feb"))
		month = 2;
	if(!strcmp(m, "Mar"))
		month = 3;
	if(!strcmp(m, "Apr"))
		month = 4;
	if(!strcmp(m, "May"))
		month = 5;
	if(!strcmp(m, "Jun"))
		month = 6;
	if(!strcmp(m, "Jul"))
		month = 7;
	if(!strcmp(m, "Aug"))
		month = 8;
	if(!strcmp(m, "Sep"))
		month = 9;
	if(!strcmp(m, "Oct"))
		month = 10;
	if(!strcmp(m, "Nov"))
		month = 11;
	if(!strcmp(m, "Dec"))
		month = 12;
	char d[3];
	d[0] = now[4];
	d[1] = now[5];
	d[2] = '\0';
	const char* s = d;
	int day = atoi(s);
	char y[5];
	y[0] = now[7];
	y[1] = now[8];
	y[2] = now[9];
	y[3] = now[10];
	y[4] = '\0';
	const char* sy = y;
	16
	int year = atoi(sy);
	this->day = day;
	this->month = month;
	this->year = year;
}
Date& Date::operator--() {
	if(day-1 > 1) {
		day--;
	} else {
		if(month-1 < 1) {
			month += 12;
			year--;
		}
		day = days_in_month[month-1];
		month--;
	}
	return *this;
}
ostream& operator<<(ostream& stream, Date &d) {
	stream<<d.day<<"."<<d.month<<"."<<d.year;
	return stream;
}
/////////////////////////////////////////////////////////////////
template<class T>
void searchString(stack<T> v, string str) {
	while(v.size()-1) {
		v.pop();
		if(v.top().getMark()==str || v.top().getColor()==str)
			cout<<v.top()<<endl;
	}
}
template<class T>
void searchRide(stack<T> v, int x) {
	while(v.size()-1) {
		v.pop();
		if(v.top().getRide()<=x)
			cout<<v.top()<<endl;
	}
}
template<class T>
void searchYear(stack<T> v, int x) {
	while(v.size()-1) {
		v.pop();
		if(v.top().getYear()==x)
			cout<<v.top()<<endl;
	}
}
17
int _tmain(int argc, _TCHAR* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	car x;
	stack<car> c;
	x.readFromFile(c);
	cout<<setw(65)<<"Автомобили"<<endl;
	cout<<setw(20)<<"Марка"
	    <<setw(10)<<"Выпуск"
	    <<setw(15)<<"Цвет"
	    <<setw(12)<<"Номер"
	    <<setw(15)<<"Пробег"
	    <<setw(15)<<"Цена аренды"
	    <<setw(20)<<"Пас. мест"
	    <<endl;
	outt(c);
	cout<<endl<<endl;
	bike b;
	stack<bike> bb;
	b.readFromFile(bb);
	cout<<setw(65)<<"Мотоциклы"<<endl;
	cout<<setw(20)<<"Марка"
	    <<setw(10)<<"Выпуск"
	    <<setw(15)<<"Цвет"
	    <<setw(12)<<"Номер"
	    <<setw(15)<<"Пробег"
	    <<setw(15)<<"Цена аренды"
	    <<setw(20)<<"Тип"
	    <<endl;
	outt(bb);
	cout<<endl<<endl;
	int rents_per_day = 0;
	int rents_per_hour = 0;
	int transport_index = 0;
	int trig = 0;
	int rent_period = 0;
	int is_trade = 0;
	int over = 0;
	int over_time = 0;
	float over_cost = 0;
	float total_cost = 0;
	int counter_cars = 0;
	int counter_bikes = 0;
	int km_in_day;
	Date d;
	int *ride_cars = new int[c.size()-1];
	int *ride_bikes = new int[bb.size()-1];
	18
	for(int i=1; i<c.size(); i++)
		ride_cars[i] = 0;
	for(int i=1; i<bb.size(); i++)
		ride_bikes[i] = 0;
	cout<<setw(20)<<"Марка"
	    <<setw(10)<<"Выпуск"
	    <<setw(15)<<"Цвет"
	    <<setw(12)<<"Номер"
	    <<setw(15)<<"Пробег"
	    <<setw(15)<<"Цена аренды"
	    <<setw(15)<<"Пас. мест/Тип"
	    <<setw(10)<<"Штраф"
	    <<endl;
	for(int i=0; i<=30; i++) {
		cout<<d<<endl;
		rents_per_day = rand()%5 + 1;
		for(int j=0; j<=rents_per_day; j++) {
			rents_per_hour = rand()%2 + 1;
			for(int j=0; j<=rents_per_hour; j++) {
				is_trade = rand()%10 + 1;
				if(is_trade > 7) {
					transport_index =
					    rand()%(bb.size() - 1) + 1;
					trig = 100;
					while(getElem(bb, transport_index).getInRent() != 0) {
						transport_index = rand()%bb.size(); //выбор свободного ТС
						if(trig == 0) {
							transport_index = -1;
							break;
						}
						trig--;
					}
					if(transport_index == -1)
						break;
					rent_period = rand()%6 + 1;
					over_time = 0;
					over = rand()%20 + 1;
					if(over > 15) {
						over_time = rand()%1 + 1;
					}
					getElem(bb, transport_index).setInRent(rent_period+over_time);
					for(int it=rent_period+over_time;
					        it>0; it--) {
						km_in_day = rand()%70 + 20;
						ride_bikes[transport_index]
						+= km_in_day;
					}
					19
					over_cost = over_time * getElem(bb, transport_index).getPrice() * 2;
					cout<<getElem(bb, transport_index);
					if(over_cost != 0)
						cout<<setw(10)<<over_cost<<endl;
					else
						cout<<endl;
					total_cost += (rent_period * getElem(bb, transport_index).getPrice() + over_cost);
					if(i == 0)
						counter_bikes++;
				}
			}
			for(int k=0; k<bb.size()-1; k++) {
				if(getElem(bb, k).getInRent() > 0)
					getElem(bb, k).setInRent(getElem(bb, k).getInRent()-1);
			}
			is_trade = rand()%10 + 1;
			if(is_trade > 7) {
				transport_index = rand()%(c.size() - 1) + 1;
				trig = 100;
				while(getElem(c, transport_index).getInRent() != 0) {
					transport_index = rand()%c.size();
					if(trig == 0) {
						transport_index = -1;
						break;
					}
					trig--;
				}
				if(transport_index == -1)
					break;
				rent_period = rand()%3 + 1;
				over_time = 0;
				over = rand()%20 + 1;
				if(over > 17) {
					over_time = rand()%1 + 1;
				}
				getElem(c, transport_index).setInRent(rent_period+over_time);
				for(int it=rent_period+over_time; it>0; it--) {
					km_in_day = rand()%400 + 100;
					ride_cars[transport_index] += km_in_day;
				}
				over_cost = over_time * getElem(c, transport_index).getPrice() * 2;
				cout<<getElem(c, transport_index);
				if(over_cost != 0)
					cout<<setw(10)<<over_cost<<endl;
				else
					cout<<endl;
				total_cost += (rent_period * getElem(c, transport_index).getPrice() + over_cost);
				if(i == 0)
					counter_cars++;
			}
		}
		for(int k=0; k<c.size()-1; k++) {
			if(getElem(c, k).getInRent() > 0)
				getElem(c, k).setInRent(getElem(c, k).getInRent()-1);
		}
		--d;
	}
	cout<<endl;
	cout<<setw(102)<<fixed<<setprecision(2)<<"Месячная прибыль: "<<total_cost<<" р."<<endl;
	cout<<endl;
	cout<<setw(110)<<"В данный момент в прокате "<<counter_cars<<" автомобилей и "<<counter_bikes<<" мотоциклов."<<endl;
	int max_c_ind = 0;
	int max_b_ind = 0;
	cout<<endl;
	cout<<setw(65)<<"Месячный пробег автомобилей"<<endl;
	cout<<setw(20)<<"Марка"
	    <<setw(10)<<"Выпуск"
	    <<setw(15)<<"Цвет"
	    <<setw(12)<<"Номер"
	    <<setw(15)<<"Пробег"
	    <<setw(15)<<"Цена аренды"
	    <<setw(15)<<"Пас. мест"
	    <<setw(20)<<"Месячный пробег"
	    <<endl;
	for(int i=1; i<c.size(); i++) {
		cout<<getElem(c, i)<<setw(15)<<ride_cars[i]<<endl;
		if(ride_cars[max_c_ind] < ride_cars[i])
			max_c_ind = i;
	}
	cout<<endl;
	cout<<setw(65)<<"Месячный пробег мотоциклов"<<endl;
	cout<<setw(20)<<"Марка"
	    <<setw(10)<<"Выпуск"
	    <<setw(15)<<"Цвет"
	    <<setw(12)<<"Номер"
	    <<setw(15)<<"Пробег"
	    21
	    <<setw(15)<<"Цена аренды"
	    <<setw(15)<<"Тип"
	    <<setw(20)<<"Месячный пробег"
	    <<endl;
	for(int i=1; i<bb.size(); i++) {
		cout<<getElem(bb, i)<<setw(15)<<ride_bikes[i]<<endl;
		if(ride_bikes[max_b_ind] < ride_bikes[i])
			max_b_ind = i;
	}
	cout<<endl;
	if(ride_cars[max_c_ind] > ride_bikes[max_b_ind])
		cout<<setw(90)<<"Максимальный месячный пробег: "<<ride_cars[max_c_ind] <<" имеет "<<getElem(c, max_c_ind).getMark()<<" с номером "<<getElem(c, max_c_ind).getNumb()<<endl;
	else
		cout<<setw(90)<<"Максимальный месячный пробег: "<<ride_bikes[max_b_ind] <<" имеет "<<getElem(bb, max_b_ind).getMark()<<" с номером "<<getElem(bb, max_b_ind).getNumb()<<endl;
	string num;
	int val;
	int choice;
	while(1) {
		cout<<setw(40)<<"Меню"<<endl;
		cout<<"1. Добавить автомобиль"<<endl
		    <<"2. Добавить мотоцикл"<<endl
		    <<"3. Удалить автомобиль"<<endl
		    <<"4. Удалить мотоцикл"<<endl
		    <<"5. Поиск по цвету"<<endl
		    <<"6. Поиск по году выпуска"<<endl
		    <<"7. Поиск по пробегу"<<endl;
		cout<<"Введите номер команды: ";
		cin>>choice;
		cin.ignore(1, '\n');
		switch(choice) {
			case 1:
				cin>>x;
				clear(c);
				x.readFromFile(c);
				break;
			case 2:
				cin>>b;
				clear(bb);
				b.readFromFile(bb);
				break;
			case 3:
				cout<<"Введите номер: ";
				cin>>num;
				del_car(num);
				22
				clear(c);
				x.readFromFile(c);
				break;
			case 4:
				cout<<"Введите номер: ";
				cin>>num;
				del_bike(num);
				clear(bb);
				b.readFromFile(bb);
				break;
			case 5:
				cout<<"Введите цвет для поиска: ";
				cin>>num;
				cout<<"\tАвтомобили\n";
				searchString(c, num);
				cout<<"\tМотоциклы\n";
				searchString(bb, num);
				break;
			case 6:
				cout<<"Введите год для поиска: ";
				cin>>val;
				cout<<"\tАвтомобили\n";
				searchYear(c, val);
				cout<<"\tМотоциклы\n";
				searchYear(bb, val);
				break;
			case 7:
				cout<<"Введите верхнюю границу пробега для поиска: ";
				cin>>val;
				cout<<"\tАвтомобили\n";
				searchRide(c, val);
				cout<<"\tМотоциклы\n";
				searchRide(bb, val);
		}
	}
	return 0;
}
