#include "Seller.h"
#include"Product.h"
#include<map>
#include<vector>

using namespace std;


Product Seller::add_product()
{
	int prod_id, price, quantity;
	string prod_name, category;
	cout << "Enter product name : ";
	cin >> prod_name;
	cout << "\nEnter product id :";
	cin >> prod_id;
	cout << "\nEnter price : ";
	cin >> price;
	cout << "\nEnter quantity : ";
	cin >> quantity;
	cout << "\nEnter category : ";
	cin >> category;


	Product p(prod_id, prod_name, price, category, sell_id, quantity);
	return p;

}

Seller::Seller(long long id, string name, string mail)
{
	sell_name = name;
	sell_email = mail;
	sell_id = id;
}

Seller::~Seller()
{
}