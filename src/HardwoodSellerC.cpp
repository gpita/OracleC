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
	double deliveryETA = 0.0;
	return deliveryETA;
}
