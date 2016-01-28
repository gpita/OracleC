//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
// Editor	   : Gabriela Pita
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "WoodItem.cpp"
using namespace std;

int main() {
	
	string buyerName, address, date, woodType = "", amountStr = "";
	int amount 
	double price, total = 0.0, deliveryTime = 0.0;
	vector<WoodItem> wood;
	ostringstrem os;

	wood.insert(new WoodItem("Cherry", 2.5, 5.95));
	wood.insert(new WoodItem("Curly Maple", 1.5, 6.00));
	wood.insert(new WoodItem("Genuine Mahogany", 3, 9.60));
	wood.insert(new WoodItem("Wenge", 5, 22.35));
	wood.insert(new WoodItem("White Oak", 2.3, 6.70));
	wood.insert(new WoodItem("Sawdust", 1, 1.50));
	
	ifstream inputFile;
	inputFile.open("order.txt");
	
	if(inputFile.is_open())
	{
		getline(inputFile, buyerName, ';');
		getline(inputFile, address, ';');
		getline(inputFile, date, '\n');

		cout << "Buyer's Name: " << buyerName << endl;
		cout << "Address: " << address << endl;
		char c;
		while (!inputFile.eof()) 
		{
			c = inputFile.get();

			while (c != ':') 
			{
				os << c;
				woodType += os.str();
				c = inputFile.get();
			}

			c = inputFile.get();

			while (c != ';') 
			{
				os << c;
				amountStr += os.str();
				c = inputFile.get();
			}

			amount = stoi(amountStr);

			cout << "Ordered " << amount << " BF of " << woodType << " at price ";
			for (int i = 0; i < wood.size(); ++i)
			{
				if(wood[i].type == woodType)
				{
					price = amount * wood[i].price;
					total = total + price;
					if(deliveryTime(amount) * wood[i].baseDeliveryTime > deliveryTime)
						deliveryTime = deliveryTime(amount) * wood[i].baseDeliveryTime;
				}
			}

			cout << '$' << setprecision(2) << fixed << price << endl;
		} 

	inputFile.close();

	cout << "Order total: $" << total << endl;
	cout << "Deliver Time: " << deliveryTime;

	return 0;
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime(int amount) {

	double deliveryETA = 0.0;


	if(amount > 0 && amount < 101)
		deliveryETA = 1.0;
	else if(amount > 100 && amount < 201)
		deliveryETA = 2.0;
	else if(amount > 200 && amount < 301)
		deliveryETA = 3.0;
	else if(amount > 300 && amount < 401)
		deliveryETA = 4.0;
	else if(amount > 400 && amount < 501)
		deliveryETA = 5.0;
	else if(amount > 500 && amount < 1001)
		deliveryETA = 5.5;

	return deliveryETA;
}
