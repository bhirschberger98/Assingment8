/******************************
Assignment 8
Written by: Brett Hirschberger
******************************/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	ifstream dataFile("dataFile.txt");
	string tempStr;
	int arrSize = 0;

	double *arrayptr, sum = 0, avg;
	double tempDouble = 0;

	//counts the lines in the file
	if (dataFile) {
		while (getline(dataFile, tempStr)) {
			arrSize++;
		}
	}
	else {
		cout << "File not found";
	}
	//moves cursor to the beginning of the file in order to read the file again
	dataFile.close();
	dataFile.open("dataFile.txt");
	//dynamically allocates memory
	arrayptr = new double[arrSize];
	if (arrayptr != nullptr) {
		//stores elements from the file in the array
		for (int c = 0; dataFile >> tempDouble; c++) {
			*(arrayptr + c) = tempDouble;
		}
	}
	else {
		cout << "Error: memory could not be allocated" << endl;
	}
	//finds sum
	for (int c = 0; c < arrSize; c++) {
		sum += *(arrayptr + c);
	}
	//finds average
	avg = sum / arrSize;
	//prints results
	cout << "Sum: " << sum << endl;
	cout << "Average: " << avg << endl;
	//deletes array pointer
	delete[] arrayptr;
	system("PAUSE");
	return 0;
}