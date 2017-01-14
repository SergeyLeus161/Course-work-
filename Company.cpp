#include "Company.h"

string Company::sold_models() {
	stack<string> p_models = parking.get_models();
	stack<string> all;
	all = cars_models;
	while (!p_models.empty()) {
		stack<string> tmp;
		string p_model = p_models.top();
		while (!all.empty()) {
			string m = all.top();
			if (p_model != m) {
				tmp.push(m);
			}
			all.pop();
		}
		all = tmp;
		p_models.pop();
	}
	
	string res = "";
	while(!all.empty()) {
		res = res + all.top();
		all.pop();
		if (!all.empty()) {
			res = res + ", ";
		}
	}
	return res;
}

void Company::add_car(Car c) {
	parking.add_car(c);
	stack<string> ms;
	ms = cars_models;
	while (!ms.empty()) {
		string m = ms.top();
		if (m == c.get_model()) {
			return;
		}
		ms.pop();
	}
	cars_models.push(c.get_model());
}

Order Company::prepare_order(Client cl) {
	if (sellers.empty()) {
		sellers = next_sellers;
		stack<Seller> s;
		next_sellers = s;
	}
	Seller s = sellers.top();
	next_sellers.push(s);
	sellers.pop();
	Order o;
	o.seller = s;
	o.client = cl;
	return o;
}

void Company::save_draft(Order o) {
	draft_orders.push(o);
}

void Company::checkout(Order o) {
	accounting.checkout(o);
	stack<Car> cs;
	cs = o.cars;
	
	stack<Car> tmp;
	while (!cs.empty()) {
		parking.exclude(cs.top());
		cs.pop();
	}
	
	o.sold = true;
}

string Company::most_popular_model() {
	stack<Order> os;
	os = draft_orders;
	stack<Order> cos;
	cos = accounting.orders;
	while (!cos.empty()) {
		os.push(cos.top());
		cos.pop();
	}
	
	return most_appeared(group(get_models(os)));
}

string Company::most_selling_model(){
	return most_appeared(group(get_models(accounting.orders)));
}

string Company::most_selling_color() {
	return most_appeared(group(get_colors(accounting.orders)));
}

stack<string> Company::get_colors(stack<Order> os) {
	stack<Order> os_tmp;
	os_tmp = os;
	stack<string> models;
	while(!os_tmp.empty()) {
		stack<Car> cs_tmp;
		cs_tmp = os_tmp.top().cars;
		while(!cs_tmp.empty()) {
			models.push(cs_tmp.top().color);
			cs_tmp.pop();
		}
		os_tmp.pop();
	}
	return models;
}

stack<string> Company::get_models(stack<Order> os) {
	stack<Order> os_tmp;
	os_tmp = os;
	stack<string> models;
	while(!os_tmp.empty()) {
		stack<Car> cs_tmp;
		cs_tmp = os_tmp.top().cars;
		while(!cs_tmp.empty()) {
			models.push(cs_tmp.top().get_model());
			cs_tmp.pop();
		}
		os_tmp.pop();
	}
	return models;
}

stack<string> Company::group(stack<string> ss) {
	stack<string> source;
	source = ss;
	stack<string> grouped;
	stack<string> tmp;
	while (!source.empty()) {
		string t = source.top();
		while(!grouped.empty() and (t != grouped.top())) {
			tmp.push(grouped.top());
			grouped.pop();
		}
		grouped.push(t);
		while(!tmp.empty()) {
			grouped.push(tmp.top());
			tmp.pop();
		}
		source.pop();
	}
	
	return grouped;
}

string Company::most_appeared(stack<string> grouped) {
	string most = "none";
	string last = "none";
	int max = 0;
	int current = 0;
	while(!grouped.empty()) {
		string s = grouped.top();
		if (s == last) {
			current = current + 1;
		} else {
			last = s;
			current = 1;
		}
		
		if (current > max) {
			most = last;
			max = current;
		}
		grouped.pop();
	}
	return most;
}

string Company::get_leader_seller() {
	return accounting.get_leader_seller();
}
