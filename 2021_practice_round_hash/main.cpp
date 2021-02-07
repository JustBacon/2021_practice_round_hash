#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

	read.open(fileName);
	getline(read, pizzas[0]);
	for (unsigned int currentpizza = 0; currentpizza < size; currentpizza++) {
		getline(read, pizzas[currentpizza]);
	}
	//Sort vector list in descending order.
	// Might not need to sort because the submission file
	// need the specific pizza
	// example. (A 2-person team will receive pizza 1 and pizza 4)
	// need to track the pizza so do not sort
	//bubSortDescend(pizzas, size);
	read.close();
}

void bubSortDescend(vector<string>& arr, int size) {
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