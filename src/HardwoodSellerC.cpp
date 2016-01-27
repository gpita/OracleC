//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout
			<< "This is an empty main method"
			<< endl;
	return 0;
}

WoodItem wood = new WoodItem();
string buyerName, address, date, amountStr;
int amount;

/*
 * Method to read the input file
 */
void readInputFile(string inputFilePath) 
{
	WoodItem wood = new WoodItem();
	string buyerName, address, date, amountStr;
	int amount;

	ifstream inputFile;
	inputFile.open(inputFilePath);

	while(!inputFile.eof())
	{
		getline(inputFile, buyerName, ';');
		getline(inputFile, address, ';');
		getline(inputFile, date, '\n');
		getline(inputFile, wood.type, ':');
		getline(inputFile, amountStr, ';');
	}

	amount = stoi(amountStr);
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime() {

	readInputFile(string);
	double deliveryETA = 0.0;

	switch wood.type
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
