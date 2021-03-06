// Read Write Files.cpp : This program writes the data from structures to a file.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

//Declare global variable
const int ITEM_NUMBER = 20;
const int DATE_NUMBER = 20;

//Declare structure
struct Inventory {
	int quantity;
	char item[ITEM_NUMBER];
	char date[DATE_NUMBER];
	double retail;
	double wholesale;
};

//Declare constructor
void display(Inventory);

int main() {

	//Make references of the structure
	Inventory inventory = {100, "basketballs", "03/21/18", 20.05, 15.85};
	Inventory inventory2 = {35, "hoops", "03/20/18", 208.69, 180.66};
	Inventory inventory3 = {20, "shoes", "03/14/18", 20.60, 16.05};
	Inventory inventory4 = {18, "shorts", "03/13/18", 16.55, 14.00};
	Inventory inventory5 = {16, "shirts", "03/12/18", 10.00, 9.95};

	//Declare the file that you are writing to
	ofstream fout("C:\\Users\\adama\\OneDrive\\Documents\\School\\Spring2018\\Programming II\\Week8\\Assignments\\inventory.txt", ios::out  | ios::binary);
	
	//Call the display function to output the data to the screen
	display(inventory);
	display(inventory2);
	display(inventory3);
	display(inventory4);
	display(inventory5);

	//Write to the file and put the data into a binary array
	fout.write(reinterpret_cast<char *>(&inventory), sizeof(inventory));
	fout.write(reinterpret_cast<char *>(&inventory2), sizeof(inventory2));
	fout.write(reinterpret_cast<char *>(&inventory3), sizeof(inventory3));
	fout.write(reinterpret_cast<char *>(&inventory4), sizeof(inventory4));
	fout.write(reinterpret_cast<char *>(&inventory5), sizeof(inventory5));

	//Close file
	fout.close();

	system("pause");
	return 0;
}

/* This function displays the data for each record to the screen
*/
void display(Inventory inventory) {
	cout << "Item:  " << inventory.item << endl;
	cout << "Quantity:  " << inventory.quantity << endl;
	cout << "Date:  " << inventory.date << endl;
	cout << "Retail Price: " << inventory.retail << endl;
	cout << "Wholesale Price: " << inventory.wholesale << endl << endl;
}


