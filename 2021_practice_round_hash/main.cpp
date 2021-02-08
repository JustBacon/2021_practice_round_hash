#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// loading all each pizza lines into array
// format	(filename, arrayPointer, lines to go through the file)
void loadPizzasIntoArray(string, string[], int);
// organize the array from biggest to smallest
void bub_sort(string[], int);


int main() {
	int numPizza = -1;
	string string1;
	bool is_eof = true;
	ifstream read;

	// Gets the number of pizza from the file
	read.open("c_many_ingredients.in");
	read >> string1;
	numPizza = stoi(string1);
	read.close();
	
	string *pizza = new string[numPizza];

	loadPizzasIntoArray("b_little_bit_of_everything.in", pizza, numPizza);

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
}

void bub_sort(string arr[], int size) {
	int* ingredientNum = new int[size];
	for (int i = 0; i < size; i++) {
		ingredientNum[i] = stoi(arr[i]);
	}
	bool swap;
	string temp;
	int numTemp;

	// run at least once to check if array is already sorted
	do {
		// make swap = false
		swap = false;

		// for loop with (i < size - 1) because when comparing
		// we compare arr[i] with arr[i + 1]
		for (int i = 0; i < (size - 1); i++) {
			// if there was a swap. make swap true to continue loop
			if (ingredientNum[i] < ingredientNum[i + 1]) {
				// swap function with temp
				numTemp = ingredientNum[i];
				ingredientNum[i] = ingredientNum[i + 1];
				ingredientNum[i + 1] = numTemp;
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

}