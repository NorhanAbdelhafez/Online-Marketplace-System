#pragma once
#include<string>
#include<iostream>
#include"Product.h"
#include<map>
#include<vector>
using namespace std;
class Seller
{
private:
	long long sell_id;
	string sell_name, sell_email;
public:

	Product add_product();
	Seller(long long id, string name, string mail);
	~Seller();
};