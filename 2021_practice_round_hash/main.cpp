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
string comparePizza(vector<string>&, vector<string>&, unsigned int, string);
int getLowestIngredPizza(vector<string>&, string);


int main() {
	int numPizza = -1;
	ifstream read;
	// number of person in a team
	// t2 (2 person team)
	int t2, t3, t4;
	string fileName = "a_example";

	// Gets the number of pizza from the file
	read.open(fileName);
	read >> numPizza;
	read >> t2 >> t3 >> t4;
	read.close();
	
	vector<string> pizza(numPizza);
	vector<string> ingred;

	cout << "LOAD:\n";
	loadPizzasIntoArray(fileName, pizza, ingred, numPizza);
	cout << "DONE LOADING:\n";
	// copy constructor copies everything from pizza vector
	// use this to comapre and remove pizzas in vector
	// keep the original to use for creating the submission file
	
	vector<string> stringSubmission;
	//cout << "teams of 4\n";
	for (int i = 0; i < t4; i++) {
		stringSubmission.push_back(comparePizza(pizza, ingred, 4, fileName));
	}

	//cout << "teams of 3\n";
	for (int i = 0; i < t3; i++) {
		stringSubmission.push_back(comparePizza(pizza, ingred, 3, fileName));
	}

	//cout << "teams of 2\n";
	for (int i = 0; i < t3; i++) {
		stringSubmission.push_back(comparePizza(pizza, ingred, 2, fileName));
	}
	for (unsigned int i = 0; i < stringSubmission.size(); i++) {
		if (stringSubmission[i] == "") {
			stringSubmission.erase(stringSubmission.begin() + i, stringSubmission.end());
		}
	}
	stringSubmission.insert(stringSubmission.begin(), to_string(stringSubmission.size()));
	// create submission file
	createSubmissionFile("submissionA.txt", stringSubmission, numPizza);
	
	return 0;
}

void createSubmissionFile(string fileName, vector<string>& stringSubmission, int size) {
	ofstream write;

	write.open(fileName);
	for (unsigned int i = 0; i < stringSubmission.size(); i++) {
		// check if vector index is empty
		if(stringSubmission[i] != "")
		write << stringSubmission[i] << endl;
	}
	write.close();

}

void loadPizzasIntoArray(string fileName, vector<string>& pizzas, vector<string>& allIngreds, int size) {
	ifstream read;

	vector<string> lineIngreds;
	string currentLine;
	string tmp;
	int deleteNum;

	read.open(fileName);
	if (!read) {
		cout << "ERROR. CANT OPEN.\n\n\n";
	}
	getline(read, pizzas[0]); // skips the 1st line in the file
	for (int currentpizza = 0; currentpizza < size; currentpizza++) {
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
		cout << currentpizza << endl;
		//cout << lineIngreds.size() << endl;

		for (unsigned int j = 0; j < lineIngreds.size(); j++) {
			
			if (find(allIngreds.begin(), allIngreds.end(), lineIngreds[j]) != allIngreds.end()) {
				/* v contains x */
			}
			else {
				/* v does not contain x */
				allIngreds.push_back(lineIngreds[j]);
				//cout << lineIngreds[j] << endl;
			}
		}

		pizzas[currentpizza].insert(0, to_string(currentpizza) + " ");
		//SORTING SHIT IDK??
	}
	cout << "This is all the unique ingredients:" << endl;
	for (unsigned int i = 0; i < allIngreds.size(); i++) {
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

string comparePizza(vector<string>& pizzas, vector<string>& unique, unsigned int team_size, string fileName) {
	string line;
	// check if we have enough pizzas
	if (!pizzas.empty() && (pizzas.size() >= team_size) && pizzas.size() > 0) {
		int unique_size;
		unique_size = unique.size();

		int ingred_total = 0;

		vector<string> pizzasCopy(pizzas);
		vector<string> uniqueCopy(unique);

		line = to_string(team_size);
		// pizzas is still has all the ingredients with spaces.
		// unique has individual words.
		// comparing word for word
		vector<string> word;
		string temp;
		bool isIngredFind = false;

		unsigned int currentIngred = 0;
		unsigned int j = 0;
		while (currentIngred < pizzas.size()) {
			stringstream ss(pizzasCopy[currentIngred]);
			while (ss >> temp) {
				word.push_back(temp);
			}

			isIngredFind = false;
			// TODO: compare pizzas with unique ingreds.
			for (unsigned int i = 0; i < word.size(); i++) {
				for (j = 0; j < uniqueCopy.size(); j++) {
					if (word[i] != uniqueCopy[j] || uniqueCopy.empty()) {

					}
					else {
						isIngredFind = true;
						uniqueCopy.erase(uniqueCopy.begin() + j);
						//uniqueCopy[j].erase();

					}
				}
			}
			if (isIngredFind) {
				team_size--;
				isIngredFind = false;
				word.clear();
				line += " " + pizzasCopy[currentIngred].substr(0, pizzasCopy[currentIngred].find(" "));
				//pizzas[currentIngred].erase();
				pizzasCopy.erase(pizzasCopy.begin() + currentIngred);
				pizzas.erase(pizzas.begin() + currentIngred);
				//cout << line << endl;
			}
			else {
				currentIngred++;
			}
			if (team_size > 0 && uniqueCopy.empty()) {
				team_size--;
				//cout << "broken: ";
				int lowIngredIndex = getLowestIngredPizza(pizzasCopy, fileName);
				line += " " + pizzasCopy[lowIngredIndex].substr(0, pizzasCopy[lowIngredIndex].find(" "));
				pizzasCopy.erase(pizzasCopy.begin() + lowIngredIndex);
				pizzas.erase(pizzas.begin() + lowIngredIndex);

			}
			if (team_size == 0)
				break;

			word.clear();
		}
	}
	else {
		//line = "hmm: \n";
		//cout << "No pizza left!\n";
		line = "";
	}
	//cout << line << endl;
	return line;
}



int getLowestIngredPizza(vector<string>& pizzas, string fileName) {
	int pizzaIndex = 0;
	int size = pizzas.size();
	int fileSize;
	int temp = -1;

	vector<int> pizzaNum; // index of original pizzas
	pizzaNum.resize(size);
	//cout << endl;
	//cout << pizzaNum.size() << endl;
	for (int i = 0; i < size; i++) {
		pizzaNum[i] = stoi(pizzas[i].substr(0, pizzas[i].find(" ")));
	}

	string deleteString;

	ifstream read;
	read.open(fileName);
	read >> fileSize;
	vector<int> numArray;
	numArray.resize(fileSize);
	//int *numArray = new int[fileSize]; // index of all the pizzas in a file
	getline(read, deleteString);

	// numArray is the number of ingredients
	for (int i = 0; i < fileSize; i++) {
		read >> numArray[i];
		if (temp == -1)
			temp = numArray[i]; // inital temp to minimum
		getline(read, deleteString);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < fileSize; j++) {
			if (pizzaNum[i] == j) {

				if (numArray[j] < temp) {
					temp = numArray[j];
					pizzaIndex = i;
					break;
				}
			}

		}
	}

	read.close();
	return pizzaIndex;
}