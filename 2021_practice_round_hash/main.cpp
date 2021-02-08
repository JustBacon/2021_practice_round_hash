#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// loading all each pizza lines into array
// format	(filename, arrayPointer, lines to go through the file)
void loadPizzasIntoArray(string, vector<string>&, int);
// sorting string array descending order
void bubSortDescend(vector<string>&, int);
// create submission file
void createSubmissionFile(string, vector<string>&, int);

int main() {
	int numPizza = -1;
	ifstream read;
	// number of person in a team
	// t2 (2 person team)
	int t2, t3, t4;

	// Gets the number of pizza from the file
	read.open("b_little_bit_of_everything.in");
	read >> numPizza;
	read >> t2 >> t3 >> t4;
	read.close();
	
	vector<string> pizza(numPizza);

	loadPizzasIntoArray("b_little_bit_of_everything.in", pizza, numPizza);
	// copy constructor copies everything from pizza vector
	// use this to comapre and remove pizzas in vector
	// keep the original to use for creating the submission file
	vector<string> pizzaCopy(pizza);

	// create submission file
	createSubmissionFile("submission.txt", pizza, numPizza);
	// --DELETE AFTER-- check if loading array worked
	for (int i = 0; i < numPizza; i++) {
		cout << pizza[i] << endl;
	}
	return 0;
}

void createSubmissionFile(string fileName, vector<string>& pizzas, int sizeDeliver) {
	ofstream write;

	write.open(fileName);
	write << sizeDeliver << endl;
	write.close();

}

void loadPizzasIntoArray(string fileName, vector<string>& pizzas, int size) {
	cout << "Loading array..." << endl;
	ifstream read;

	vector<string> allIngreds, lineIngreds;
	string currentLine;
	string tmp;

	read.open(fileName);
	getline(read, pizzas[0]);
	for (unsigned int currentpizza = 0; currentpizza < size; currentpizza++) {
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

void bubSortDescend(vector<string>& arr, int size) {
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