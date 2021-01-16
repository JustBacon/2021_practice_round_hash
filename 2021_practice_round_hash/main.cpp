#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// loading all each pizza lines into array
// format	(filename, arrayPointer, lines to go through the file)
void loadPizzasIntoArray(string, string[], int);

int main() {
	int tempNumPizza = -1;
	string string1;
	bool is_eof = true;
	ifstream read;

	// Gets the number of pizza from the file
	read.open("b_little_bit_of_everything.in");
	read >> string1;
	tempNumPizza = stoi(string1);
	read.close();

	const int NUM_OF_PIZZA = tempNumPizza;
	
	string *pizza = new string[NUM_OF_PIZZA];

	loadPizzasIntoArray("b_little_bit_of_everything.in", pizza, NUM_OF_PIZZA);
	// --DELETE AFTER-- check if loading array worked
	for (int i = 0; i < NUM_OF_PIZZA; i++) {
		cout << pizza[i] << endl;
	}
	return 0;
}

void loadPizzasIntoArray(string fileName, string pizzas[], int size) {
	cout << "Loading array..." << endl;
	ifstream read;

	read.open(fileName);
	getline(read, pizzas[0]);
	for (int currentpizza = 0; currentpizza < size; currentpizza++) {
		getline(read, pizzas[currentpizza]);
	}
	read.close();
}