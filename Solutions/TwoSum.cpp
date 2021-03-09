#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

void printArray(const vector<int> array);
void validateIntInput(int& valueToInput, const string prompt = "Enter value: ");
void generateNumbers(vector<int>& array);

int main() {

	// =================================== //
	//			Task preparation		   //
	// =================================== //

	srand(time(NULL));

	vector<int> array(10);
	int requestedSum;
	
	generateNumbers(array);
	sort(array.begin(), array.end());
	printArray(array);
	validateIntInput(requestedSum, "Enter the sum to be found: ");

	// =================================== //
	//			     Solution  		       //
	// =================================== //

	auto rightIterator = array.end() - 1; // Iterator pointing to the very last element
	auto leftIterator = array.begin();    // Iterator pointing to the beggining

	// Loop is executed as long as the iterators do not cross
	while (rightIterator > leftIterator)
	{
		int sum = *rightIterator + *leftIterator;

		if (sum == requestedSum) {
			cout << "[" << *rightIterator << " " << *leftIterator << "]" << endl;
			break;
		}

		else if (sum > requestedSum) --rightIterator;
		else ++leftIterator;
	}

	if (rightIterator <= leftIterator) cout << "-1" << endl; // No pair found

	return 0;
}

void printArray(const vector<int> array) {
	for (auto element : array) {
		cout << element << " ";
	}
	cout << endl;
}

void generateNumbers(vector<int>& array) 
{
	generate(array.begin(), array.end(), []() {
		return rand() % 100;
	});
}

void validateIntInput(int& valueToInput, const string prompt)
{
	cout << prompt;
	while (!(cin >> valueToInput)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << prompt;
	}
}