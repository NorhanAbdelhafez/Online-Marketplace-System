#pragma once
#include <string>
#include "Product.h"
#include <vector>
#include<map>
#include <utility>
#include<list>


using namespace std;
class Customer
{
protected:
	long long ID;
	string name, address, phone_number, email;
	list< pair<Product, int > > cart;
public:
	Customer(int ID, string name, string address, string phone_number, string email);
	void browse_products(map<string, vector<Product> >m);
	void add_product(map <int, Product >products, int id, int quantity);
	void display_total_prices();
	list< pair<Product, int > >return_cart();
};
