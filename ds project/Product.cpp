#include "Product.h"
#include <string>

Product::Product()
{
}

Product::Product(int id, std::string name, int price, std::string category, long long selleriD, int quant)
{
	Id = id;
	Name = name;
	Price = price;
	Category = category;
	SellerID = selleriD;
	quantity = quant;
}
std::string Product::name()
{
	return Name;
}
std::string Product::category()
{
	return Category;
}
int Product::ID()
{
	return Id;
}
int Product::price()
{
	return Price;
}
void  Product::SetQuantity(int quan)
{
	quantity = quan;
}

Product::~Product()
{
}
