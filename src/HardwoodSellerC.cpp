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
	int amount;

	WoodItem Cherry = new WoodItem("Cherry", 2.5, 5.95);
	WoodItem CurlyMaple = new WoodItem("Curly Maple", 1.5, 6.00);
	WoodItem GenuineMahogany = new WoodItem("Genuine Mahogany", 3, 9.60);
	WoodItem Wenge = new WoodItem("Wenge", 5, 22.35);
	WoodItem WhiteOak = new WoodItem("White Oak", 2.3, 6.70);
	WoodItem Sawdust = new WoodItem("Sawdust", 1, 1.5);
	
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

			while (ch != ';') 
			{
				amountStr += c;
				c = inputFile.get();
			}

			amount = stoi(amountStr);
		} 

	inputFile.close();

	return 0;
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime(string woodType) {

	double deliveryETA = 0.0;

	switch woodType
	{
		case "Cherry": 
			wood.price = 5.95; wood.baseDeliveryTime = 2.5;
			break;
		case "Curly Maple": wood.price = 6.00; wood.baseDeliveryTime = 1.5;
			break;
		case "Genuine Mahogany": wood.price = 9.60; wood.baseDeliveryTime = 3;
			break;
		case "Wenge": wood.price = 22.35; wood.baseDeliveryTime = 5;
			break;
		case "White Oak": wood.price = 6.70; wood.baseDeliveryTime = 2.3;
			break;
		case "Sawdust": wood.price = 1.5; wood.baseDeliveryTime = 1;
	}

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












