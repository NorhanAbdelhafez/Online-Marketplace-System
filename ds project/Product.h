#include <string>

#pragma once

class Product
{
private:
	int Id;
	std::string Name;
	int Price;
	std::string Category;
	int SellerID;

public:
	Product();
	Product(int id, std::string name, int price, std::string category, long long selleriD, int quant);
	std::string name();
	std::string category();
	int ID();
	int price();
	void SetQuantity(int quan);
	int quantity = 0;
	~Product();
};

