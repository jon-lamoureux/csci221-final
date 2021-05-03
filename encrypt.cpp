#include "encrypt.h"
#include <iostream>
#include <fstream>
#include <string>

int encrypt::beginEncrypt(string& inputFile, string& outputFile, char& inputType, string& keyword) {
	string genKeyword, encryptedText;
	// remove spaces from the string
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
	// Since the cipher requires the key to be the same length as the string to encrypt,
	// We need to increase the length of the key to be the same as the phrase to encrypt if it is smaller
	for (int i = 0; genKeyword.size() != content.size(); i++) {
		genKeyword.push_back(keyword[i]);
		if(i == (keyword.size() - 1)) {
			i = -1;
		}
	}
	// Encryption time! Finally
	for(int i = 0; i < content.size(); i++) { // Encrypt each individual character
		// according to https://www.dcode.fr/vigenere-cipher, the best way to use the cipher is to take the letter of the string's value and
		// take the letter of the key's value and add them together, and then modulo 26 in case they are both higher than 13
		char curr = (content[i] + genKeyword[i]) % 26 + 'A';

		// Add to encrypted string
		encryptedText.push_back(curr);
	}
	cout << "The encrypted text of \"" << content << "\" is: " << encryptedText << endl;
	ofstream outFile(outputFile, ios::out);
	outFile << encryptedText;
	outFile.close();
	cout << "The result of your encryption has been stored in " << outputFile << endl;
	ofstream keyFile("key_" + outputFile, ios::out);
	keyFile << keyword;
	keyFile.close();
	cout << "The key used for your encryption has been stored in key_" << outputFile << endl;
	if (inputType == 'f') {
		cout << "Your original input file can still be found at " << inputFile << endl;
	}
	return 0;
}
