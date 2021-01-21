#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// loading all each pizza lines into array
// format	(filename, arrayPointer, lines to go through the file)
void loadPizzasIntoArray(string, string[], int);
// organize the array from biggest to smallest
// sortArrayDescend goes with merge function
void sortArrayDescend(string[], int, int);
void merge(string[], int, int, int);
void bub_sort(string[], int);


int main() {
	int numPizza = -1;
	string string1;
	bool is_eof = true;
	ifstream read;

	// Gets the number of pizza from the file
	read.open("b_little_bit_of_everything.in");
	read >> string1;
	numPizza = stoi(string1);
	read.close();
	
	string *pizza = new string[numPizza];

	loadPizzasIntoArray("b_little_bit_of_everything.in", pizza, numPizza);

	// --DELETE AFTER-- check if loading array worked
	for (int i = 0; i < numPizza; i++) {
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
	//sortArrayDescend(pizzas, 0, size);
	bub_sort(pizzas, size);
	read.close();
}

// MERGE SORT NOT WORKING. F THIS
void merge(string arr[], int l, int m, int r) {
	int i = l;
	int j = m + l;
	int k = l;

	int size = (r - 1) + 1;
	string *temp = new string[size];

	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		}
		else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while (i <= m) {
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= r) {
		temp[k] = arr[j];
		j++;
		k++;
	}
	for (int t = l; t <= r + 1; t++) {
		arr[t] = temp[t];
	}
}
// MERGE SORT NOT WORKING
void sortArrayDescend(string pizzas[], int l, int r) {
	if (l < r) {
		int m = (1 + r) / 2;
		sortArrayDescend(pizzas, l, m);
		sortArrayDescend(pizzas, m+1, r);
		merge(pizzas, l, m, r);

	}
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