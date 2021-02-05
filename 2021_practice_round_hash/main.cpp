#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
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
	read.open("c_many_ingredients.in");
	read >> string1;
	tempNumPizza = stoi(string1);
	read.close();

	const int NUM_OF_PIZZA = tempNumPizza;
	
	string *pizza = new string[NUM_OF_PIZZA];

	loadPizzasIntoArray("c_many_ingredients.in", pizza, NUM_OF_PIZZA);
	/*/ --DELETE AFTER-- check if loading array worked
	for (int i = 0; i < NUM_OF_PIZZA; i++) {
		cout << pizza[i] << endl;
	}
	return 0;/*/
}

void loadPizzasIntoArray(string fileName, string pizzas[], int size) {
	cout << "Loading array..." << endl;
	ifstream read;

	vector<string> allIngreds, lineIngreds;
	string currentLine;
	string tmp;

	read.open(fileName);
	getline(read, pizzas[0]);
	for (int currentpizza = 0; currentpizza < size; currentpizza++) {
		getline(read, pizzas[currentpizza]);
		//TODO: SPLIT STRING INTO lineIngreds Vector/Array?
		string tmp;
		stringstream ss(pizzas[currentpizza]);

		while (getline(ss, tmp, ' ')) {
			lineIngreds.push_back(tmp);
		}

		//cout << lineIngreds.size() << endl;

		for (int j = 0; j < lineIngreds.size(); j++) {
			lineIngreds[j];
			if (std::find(allIngreds.begin(), allIngreds.end(), lineIngreds[j]) != allIngreds.end()) {
				/* v contains x */
			}
			else {
				/* v does not contain x */
				allIngreds.push_back(lineIngreds[j]);
				cout << lineIngreds[j] << endl;
			}
		}
		//SORTING SHIT IDK??
	}
	for (int i = 0; i < allIngreds.size(); i++) {
		cout << allIngreds[i] << endl;
	}
	read.close();
	// ...
}
