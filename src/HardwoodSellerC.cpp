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
#include <iomanip>
#include "WoodItem.cpp"
using namespace std;

int main() {
	
	string buyerName, address, date, woodType, amountStr;
	int amount, price;
	char c;
	vector<WoodItem> wood;

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

		while (!inputFile.eof()) 
		{
			c = inputFile.get();

			while (c != ':') 
			{
				woodType += c;
				c = inputFile.get();
			}

			c = inputFile.get();

			while (c != ';') 
			{
				amountStr += c;
				c = inputFile.get();
			}

			amount = stoi(amountStr);

			cout << "Ordered " << amount << " BF of " << woodType << " at price ";
			switch woodType
			{
				case "Cherry": 
					price = 5.95; baseDeliveryTime = 2.5;
					break;
				case "Curly Maple": price = 6.00; baseDeliveryTime = 1.5;
					break;
				case "Genuine Mahogany": price = 9.60; baseDeliveryTime = 3;
					break;
				case "Wenge": price = 22.35; baseDeliveryTime = 5;
					break;
				case "White Oak": price = 6.70; baseDeliveryTime = 2.3;
					break;
				case "Sawdust": price = 1.5; baseDeliveryTime = 1;
					break;
			}

			cout << price << endl;
		} 

	inputFile.close();



	return 0;
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime(string woodType) {

	double deliveryETA = 0.0;


	if(amount > 0 && amount < 101)
		deliveryETA = wood.baseDeliveryTime;
	else if(amount > 100 && amount < 201)
		deliveryETA = 2.0*wood.baseDeliveryTime;
	else if(amount > 200 && amount < 301)
		deliveryETA = 3.0*wood.baseDeliveryTime;
	else if(amount > 300 && amount < 401)
		deliveryETA = 4.0*wood.baseDeliveryTime;
	else if(amount > 400 && amount < 501)
		deliveryETA = 5.0*wood.baseDeliveryTime;
	else if(amount > 500 && amount < 1001)
		deliveryETA = 5.5*wood.baseDeliveryTime;
	


	return deliveryETA;
}












