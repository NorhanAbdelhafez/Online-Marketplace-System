#include "Customer.h"
#include"Product.h"
#include <map>
#include <iostream>
#include<Windows.h>

using namespace std;
Customer::Customer(int ID, string name, string address, string phone_number, string email)
{
	this->ID = ID;
	this->name = name;
	this->address = address;
	this->phone_number = phone_number;
	this->email = email;

}


void Customer::browse_products(map<string, vector<Product>> m)
{
	for (auto it : m)
	{
		//to handle colors
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 3);
		cout << it.first << '\n';
		for (auto product : it.second)
			

		SetConsoleTextAttribute(h, 11);
		cout << "ID:" << "	" << "NAME:" << "		" << "PRICE:" << "	" << "QUANTITY:" << endl;

		SetConsoleTextAttribute(h, 7);
		for (auto product : it.second)
		{
			cout << product.ID() << "	" << product.name();
			// checks for length of string to format it the right way
			if (product.name().length() >= 8) cout << "	";
			else cout << "		";
			cout << product.price() << "	" << product.quantity << endl;
		}
	}
}

void Customer::add_product(map <int, Product >products, int id, int quantity)
{

	cart.push_back({ products[id], quantity });

}



void Customer::display_total_prices()
{
	long long total_price = 0;
	for (auto it : cart) {
		total_price += it.first.price() * it.second;
	}
	cout << total_price << endl;
}

list<pair<Product, int>> Customer::return_cart()
{
	return cart;
}
