/* Read File.cpp : This program reads in the invetory file created in the Read Write application.  For each binary array that is stored in the file, gets put back into 
	a Invetory structure and then totals are then calculated and outputted to the screen.
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Declare global variables
int totalQuantity = 0;
double totalRetail = 0.00;
double totalWholesale = 0.00;
double grandTotalRetail = 0.00;
double grandTotalWholesale = 0.00;

//Declare an Inventory structure
struct Inventory {
	int quantity;
	char item[20];
	char date[20];
	double retail;
	double wholesale;
};
int main() {

	//Declare the read in file
	Inventory inventory;
	fstream inFile("C:\\Users\\adama\\OneDrive\\Documents\\School\\Spring2018\\Programming II\\Week8\\Assignments\\inventory.txt", ios::in | ios::binary);

	//Read the first array in the file
	inFile.read(reinterpret_cast<char *>(&inventory), sizeof(inventory));

	while (!inFile.eof()) {

		cout << "Item:  " << inventory.item << endl;
		cout << "Quantity:  " << inventory.quantity << endl;
		cout << "Date:  " << inventory.date << endl;
		cout << "Retail Price: " << inventory.retail << endl;
		cout << "Wholesale Price: " << inventory.wholesale << endl << endl;

		//Calcualate totals
		totalQuantity =  totalQuantity + inventory.quantity;
		totalRetail += totalRetail + inventory.retail;
		totalWholesale += totalWholesale + inventory.wholesale;

		//Read in next array
		inFile.read(reinterpret_cast<char *>(&inventory), sizeof(inventory));
	}

	//Close files
	inFile.close();

	grandTotalRetail = totalQuantity * totalRetail;
	grandTotalWholesale = totalQuantity * totalWholesale;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Total Quantity: ";
	cout << fixed << setprecision(2) << totalQuantity << endl;
	cout << "Total Amount of Retail:  $" << grandTotalRetail << endl;
	cout << "Total Amount of Wholesale:  $" << grandTotalWholesale << endl;

	system("pause");
}

