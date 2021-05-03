#include "decrypt.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int decrypt::beginDecrypt(string& inputFile, string& outputFile, char& inputType) {
	// If we need to open a file, turn it into a string
	string content = inputFile;
	if (inputType == 'f') {
		// Create variables
		ifstream inFile(inputFile, ios::in);
		if (inFile) {
			// Optimal way to allocate size for string from https://insanecoding.blogspot.com/2011/11/how-to-read-in-file-in-c.html
			inFile.seekg(0, ios::end);
			content.reserve(inFile.tellg());
			// Return to beginning of file for later
			inFile.seekg(0, ios::beg);
			// Assign contents of file to string
			content.assign((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
			inFile.close();
		}
	}
	cout << content;
	ofstream outFile(outputFile, ios::out);
	outFile << content;
	outFile.close();
	return 0;
}
