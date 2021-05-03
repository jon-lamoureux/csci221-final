//============================================================================
// Name        : HillCipher.cpp
// Author      : Jonathan Lamoureux
// Version     :
// Description : A Hill cipher that uses a square matrix to encrypt and decrypt text
//============================================================================

#include "encrypt.h"
#include "decrypt.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	// Variable creation
	char methodType, fileType;
	string fileName, outputName, inputText;
    encrypt encryption;
    decrypt decryption;

	// Opening statement
	cout << "Welcome to the Vigenere Cipher Encryption and Decryption Program" << endl << endl;

	// Ask the user if they want to use raw text or load a file
	cout << "Would you like to load a file or input raw text?" << endl << "Input \"f\" to load a file or \"t\" to input text: ";
	cin >> fileType;

	// Validate user input
	while (fileType != 'f' && fileType != 't') {
		cout << "Error: input either \"f\" to load a file or \"t\" to input text: ";
		cin >> fileType;
	}

	// Ask the user if they would like to encrypt or decrypt
	cout << endl << "Would you like to encrypt or decrypt?" << endl << "Input \"e\" for encryption or \"d\" for decryption: ";
	cin >> methodType;

	// Validate user input
	while (methodType != 'e' && methodType!= 'd') {
		cout << "Error: input either \"e\" to encrypt or \"d\" to decrypt: ";
		cin >> methodType;
	}

	cout << endl << "Enter name of output file (example: output.txt): ";
	cin >> outputName;


	if (methodType == 'e' && fileType == 'f') {
		cout << "Enter name of file to encrypt: ";
		cin >> fileName;
	} else if (methodType == 'd' && fileType == 'f') {
		cout << "Enter name of file to decrypt: ";
		cin >> fileName;
	} else if (methodType == 'd' && fileType == 't') {
		cout << "Enter text to decrypt: ";
		cin >> inputText;
	} else if (methodType == 'e' && fileType == 't') {
		cout << "Enter text to encrypt: ";
		cin >> inputText;
	}


}
