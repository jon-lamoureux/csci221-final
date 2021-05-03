#include "decrypt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int decrypt::beginDecrypt(string& inputFile, string& outputFile, char& inputType, string& keyword) {
	string genKeyword, decryptedText;
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
	// Make everything uppercase because of ASCII being weird
	transform(genKeyword.begin(), genKeyword.end(), genKeyword.begin(), ::toupper);
	transform(content.begin(), content.end(), content.begin(), ::toupper);
	// Decryption time
	for(int i = 0; i < content.size(); i++) { // Decrypt each individual character
		// according to https://www.dcode.fr/vigenere-cipher, the best way to use the cipher is to take the letter of the string's value and
		// take the letter of the key's value and subtract them, and then modulo 26
		char curr = (content[i] - genKeyword[i] + 26) % 26 + 'A';
		// Add to decrypted string
		decryptedText.push_back(curr);
	}
	cout << "The decrypted text of \"" << content << "\" is: " << decryptedText << endl;

	ofstream outFile(outputFile, ios::out);
	outFile << decryptedText;
	outFile.close();
	cout << "The result of your decryption has been stored in " << outputFile << endl;

	ofstream keyFile("key_" + outputFile, ios::out);
	keyFile << keyword;
	keyFile.close();

	cout << "The key used for your decryption has been stored in key_" << outputFile << endl;
	if (inputType == 'f' && inputFile != outputFile) {
		cout << "Your original input file can still be found at " << inputFile << endl;
	}
	return 0;
}
