#include "Company.h"

std::stack<string> Company::sold_models() {
	std::stack<string> p_models = parking.get_models();
	std::stack<string> all;
	all = cars_models;
	while (!p_models.empty()) {
		std::stack<string> tmp;
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
	return all;
}

