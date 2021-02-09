#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// loading all each pizza lines into array
// format	(filename, arrayPointer, lines to go through the file)
void loadPizzasIntoArray(string, vector<string>&, vector<string>&, int);
// sorting string array descending order
void bubSortDescend(vector<string>&, int);
// create submission file
void createSubmissionFile(string, vector<string>&, int);
// compare pizzas with unique ingredients
// Put (line ingredients, unique word for word ingredients, team of 2, team of 3, team of 4
void comparePizza(vector<string>&, vector<string>&, int, int, int);

int main() {
	int numPizza = -1;
	ifstream read;
	// number of person in a team
	// t2 (2 person team)
	int t2, t3, t4;

	// Gets the number of pizza from the file
	read.open("a_example");
	read >> numPizza;
	read >> t2 >> t3 >> t4;
	read.close();
	
	vector<string> pizza(numPizza);
	vector<string> ingred;

	loadPizzasIntoArray("a_example", pizza, ingred, numPizza);
	// copy constructor copies everything from pizza vector
	// use this to comapre and remove pizzas in vector
	// keep the original to use for creating the submission file
	vector<string> pizzaCopy(pizza);
	comparePizza(pizzaCopy, ingred, t2, t3, t4);

	// create submission file
	createSubmissionFile("submission.txt", pizza, numPizza);
	// --DELETE AFTER-- check if loading array worked
	cout << endl;
	cout << "All the pizzas:" << endl;
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

void loadPizzasIntoArray(string fileName, vector<string>& pizzas, vector<string>& allIngreds, int size) {
	cout << "Loading array..." << endl;
	ifstream read;

	vector<string> lineIngreds;
	string currentLine;
	string tmp;
	int deleteNum;

	read.open(fileName);
	getline(read, pizzas[0]); // skips the 1st line in the file
	for (unsigned int currentpizza = 0; currentpizza < size; currentpizza++) {
		read >> deleteNum;
		getline(read, pizzas[currentpizza]);
		istringstream iss(pizzas[currentpizza]);
		iss >> ws;
		getline(iss, pizzas[currentpizza]);
		//TODO: SPLIT STRING INTO lineIngreds Vector/Array?
		string tmp;
		stringstream ss(pizzas[currentpizza]);

		while (getline(ss, tmp, ' ')) {
			lineIngreds.push_back(tmp);
		}

		//cout << lineIngreds.size() << endl;

		for (int j = 0; j < lineIngreds.size(); j++) {
			
			if (find(allIngreds.begin(), allIngreds.end(), lineIngreds[j]) != allIngreds.end()) {
				/* v contains x */
			}
			else {
				/* v does not contain x */
				allIngreds.push_back(lineIngreds[j]);
				//cout << lineIngreds[j] << endl;
			}
		}
		//SORTING SHIT IDK??
	}
	cout << "This is all the unique ingredients:" << endl;
	for (int i = 0; i < allIngreds.size(); i++) {
		cout << allIngreds[i] << endl;
	}
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

void comparePizza(vector<string>& pizzas, vector<string>& unique, int t2, int t3, int t4) {
	int pizza_size, unique_size;
	pizza_size = pizzas.size();
	unique_size = unique.size();

	int ingred_total = 0;

	vector<string> uniqueCopy(unique);
	// pizzas is still has all the ingredients with spaces.
	// unique has individual words.
	// comparing word for word
	vector<string> word;
	string temp;

	for (unsigned int currentIngred = 0; currentIngred < pizza_size; currentIngred++) {
		stringstream ss(pizzas[currentIngred]);
		while (ss >> temp) {
			word.push_back(temp);
		}
		int size_p = word.size();
		int size_i = uniqueCopy.size();
		// TODO: compare pizzas with unique ingreds.
		for (int i = 0; i < size_p; i++) {
			for (int j = 0; j < size_i; j++) {
				if (word[i] == uniqueCopy[j]) {
					uniqueCopy[j].erase();
					ingred_total++;
				}
			}
		}
		cout << ingred_total << endl;


		word.clear();
	}
}