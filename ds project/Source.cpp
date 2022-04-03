#include <iostream>
#include<string>
#include<list>
#include<vector>
#include<map>
#include "Product.h"
#include "Customer.h"
#include "Seller.h"
#include "Customer.h"
#include<Windows.h>
#include"tabulate.hpp"

int answer, choice;

map <string, vector<Product> >OurProducts;
map <int, Product>products;

void numcheck(string choices)
{

	// to handle colors
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 5);
	std::cout << choices;
	SetConsoleTextAttribute(h, 7);


	std::cin >> answer;
	
	if (answer!=1 && answer != 2)
	{
		SetConsoleTextAttribute(h, 4);
		std::cout << "\nplease enter a valid number.\n";
		SetConsoleTextAttribute(h, 7);
		numcheck(choices);
	}

}

bool Quantitycheck(int id, int quan)
{
	for (auto product : OurProducts[products[id].category()])
	{
		if (product.ID() == id && product.quantity < quan)
		{
			return false;
			break;
		}
	}
}


using namespace std;
using namespace tabulate;


Product product(1, "laptop", 18000, "electronics", 5, 6);
Product product1(2, "iphone8", 8000, "electronics", 5, 20);
Product product2(3, "ipad", 10000, "electronics", 5, 15);
Product product3(4, "iphone11", 11000, "electronics", 5, 12);
Product product4(5, "headphones", 2000, "electronics", 5, 25);
Product product5(6, "airpods", 3000, "electronics", 5, 20);

Product product6(7, "skirt", 200, "clothes", 1, 10);
Product product7(8, "jeans", 150, "clothes", 1, 40);
Product product8(9, "jacket", 250, "clothes", 1, 30);
Product product9(10, "sweetpants", 200, "clothes", 1, 40);
Product product10(11, "hoodie", 300, "clothes", 1, 35);
Product product11(12, "sweatshirt", 100, "clothes", 1, 24);

Product product12(13, "hammer", 20, "houseware", 5, 10);
Product product13(14, "table", 200, "houseware", 5, 20);
Product product14(15, "char", 100, "houseware", 5, 30);
Product product15(16, "desk", 150, "houseware", 5, 40);
Product product16(17, "cupbord", 500, "houseware", 5, 7);



int main()
{
	// inserting products into main map
	OurProducts["electronics"].push_back(product);
	OurProducts["electronics"].push_back(product1);
	OurProducts["electronics"].push_back(product2);
	OurProducts["electronics"].push_back(product3);
	OurProducts["electronics"].push_back(product4);
	OurProducts["electronics"].push_back(product5);

	OurProducts["clothes"].push_back(product6);
	OurProducts["clothes"].push_back(product7);
	OurProducts["clothes"].push_back(product8);
	OurProducts["clothes"].push_back(product9);
	OurProducts["clothes"].push_back(product10);
	OurProducts["clothes"].push_back(product11);

	OurProducts["houseware"].push_back(product12);
	OurProducts["houseware"].push_back(product13);
	OurProducts["houseware"].push_back(product14);
	OurProducts["houseware"].push_back(product15);
	OurProducts["houseware"].push_back(product16);


	// for inserting products into products map
	for (auto it : OurProducts)
	{
		for (auto product : it.second)
		{
			products.insert({ product.ID(),product });
		}
	}

	while (true)
	{
		Table system;

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);
		cout << "\nEnter the system as: (choose a number) \n\n";

		SetConsoleTextAttribute(h, 7);

		system.add_row({ "no.","    " });
		system.add_row({ " 1 ","  Seller  " });
		system.add_row({ " 2 ","  Costumer  " });

		system.format()
			.font_style({ FontStyle::bold })
			.border_top(" ")
			.border_bottom(" ")
			.border_left(" ")
			.border_right(" ")
			.corner(" ");

		system[0][0].format()
			.font_background_color(Color::magenta)
			.font_style({ FontStyle::underline })
			.font_style({ FontStyle::bold });

		system[0][1].format()
			.font_background_color(Color::magenta)
			.font_style({ FontStyle::bold });

		system[1][0].format()
			.font_background_color(Color::magenta)
			.font_style({ FontStyle::bold });

		system[1][1].format()
			.font_background_color(Color::magenta)
			.font_style({ FontStyle::bold });

		system[2][0].format()
			.font_background_color(Color::magenta)
			.font_style({ FontStyle::bold });

		system[2][1].format()
			.font_background_color(Color::magenta)
			.font_style({ FontStyle::bold });

		cout << system << endl << endl;

		cin >> answer;

		if (answer == 1)
		{
			long long id; string name, mail;

			// for controlling colors
			SetConsoleTextAttribute(h, 5);
			cout << "\nEnter your information:\n";
			SetConsoleTextAttribute(h, 7);

			// entering seller info & creating seller object
			cout << "\nID: "; cin >> id;
			cout << "\nNAME: "; cin.ignore(); getline(cin, name);
			cout << "\nEMAIL: "; cin >> mail;
			cout << endl;
			Seller seller(id, name, mail);


			// for checking if the correct num was pressed
			numcheck("\n1.Add a new product.	2.Add an existing product.\n\n");

			// first option for adding a new product
			if (answer == 1) {

				Product prod = seller.add_product();

				// for checking if the product already exist
				if (products.find(prod.ID()) != products.end())
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\n		Product already exists.\n\n";
					SetConsoleTextAttribute(h, 7);
					continue;
				}

				OurProducts[prod.category()].push_back(prod);
				products.insert({ prod.ID(),prod });

				SetConsoleTextAttribute(h, 6);
				cout << "\n		Product added successfully!\n" << endl;
				SetConsoleTextAttribute(h, 7);
				continue;
			}

			// second option for adding an existing product
			else if (answer == 2)
			{
				int i, quan;
				string cat;
				cout << "\nEnter product category : ";	cin >> cat;

				cout << "\n\nEnter product id: "; cin >> i;

				cout << "\n\nEnter quantity: "; cin >> quan;

				// for checking if the id already exist
				if (products.find(i) == products.end())
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\n		ID does not exist.\n";
					SetConsoleTextAttribute(h, 7);
					continue;
				}

				vector<Product>v = OurProducts[cat];
				for (int x = 0; x < v.size(); x++) {
					if (v[x].ID() == i) {
						v[x].quantity += quan;
						break;
					}
				}
				OurProducts[cat] = v;

				SetConsoleTextAttribute(h, 6);
				cout << "\n		Product added successfully!\n" << endl;
				continue;
			}


		}


		else if (answer == 2)
		{
			int id, quan;
			string name, address, phone_number, email;

			// for controlling colors
			SetConsoleTextAttribute(h, 5);
			cout << "\nEnter your information:\n";
			SetConsoleTextAttribute(h, 7);

			// getting customer info and creating customer object to browse products
			cout << "\nID: "; cin >> id;
			cout << "\nNAME: ";  cin.ignore(); getline(cin, name);
			cout << "\nADDRESS: ";  cin.ignore(); getline(cin, address);
			cout << "\nPHONE NUMBER: "; cin >> phone_number;
			cout << "\nEMAIL: "; cin >> email; cout << endl;

			Customer customer(id, name, address, phone_number, email);
			customer.browse_products(OurProducts);


			numcheck("1.Add products to cart		2.Exit\n");
		

			if (answer == 2) continue;
			else if (answer == 1)
			{
				while (true)
				{
					SetConsoleTextAttribute(h, 5);
					cout << "To add products to cart please enter product id & quantity:\n";
					SetConsoleTextAttribute(h, 7);

					cout << "ID: "; cin >> id; cout << "QUANTITY : "; cin >> quan; cout << endl;
					if (products.find(id) == products.end())
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\n		This ID is not valid.\n";
						SetConsoleTextAttribute(h, 7);
						continue;
					}
					if (!Quantitycheck(id, quan))
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\n		The quantity you selected is more than the available quantity.\n";
						SetConsoleTextAttribute(h, 7);
						continue;
					}
					if (quan < 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\n		Number not valid.\n";
						SetConsoleTextAttribute(h, 7);
						continue;
					}

					customer.add_product(products, id, quan);

					numcheck("1.Add another product	2.Display total price\n");
					
					if (answer == 1)continue;
					else if (answer == 2)
					{
						cout << "Total Price: "; customer.display_total_prices(); cout << endl;

						
					 numcheck("1.Confirm buying	2.Undo\n");

						if (answer == 1) {
							SetConsoleTextAttribute(h, 6);
							cout << "		Successful purchase! \n\n";
							SetConsoleTextAttribute(h, 7);

							list< pair<Product, int > > cart= customer.return_cart();

							for (auto element : cart)
							{
								string cate = element.first.category();
								vector<Product>v = OurProducts[cate];
								for (int x = 0; x < v.size(); x++) {
									if (v[x].ID() == element.first.ID()) {
										v[x].quantity -= element.second;
										break;
									}
								}
								OurProducts[cate] = v;
							}
						
							
							break;
						}
						else break;
					}
				}
				continue;
			}
		}
		else
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			std::cout << "\nplease enter a valid number.\n";
			SetConsoleTextAttribute(h, 7);
		}
	}
	return 0;
}

