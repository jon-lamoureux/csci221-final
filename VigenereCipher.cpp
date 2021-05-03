//============================================================================
// Name        : VigenereCipher.cpp
// Author      : Jonathan Lamoureux
// Version     :
// Description : A Vigenere cipher that decrypts and encrypts text from command lines or files.
//============================================================================

#include "encrypt.h"
#include "decrypt.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	// Variable creation
	char methodType, fileType;
	string fileName, outputName, inputText, keyword;
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

	// Get output file name
	cout << endl << "Enter name of output file (example: output.txt): ";
	cin >> outputName;

	// Get user keyword
	cout << "Enter your keyword: It can be anything, as long as it only contains letters (example: CHRISTMAS): ";
	cin >> keyword;

	// If else statements to check what the user chose
	if (methodType == 'e' && fileType == 'f') {
		cout << "Enter name of file to encrypt: ";
		cin >> fileName;
        encryption.beginEncrypt(fileName, outputName, fileType, keyword);
	} else if (methodType == 'd' && fileType == 'f') {
		cout << "Enter name of file to decrypt: ";
		cin >> fileName;
        decryption.beginDecrypt(fileName, outputName, fileType, keyword);
	} else if (methodType == 'd' && fileType == 't') {
		cout << "Enter text to decrypt: ";
		cin.ignore();
		getline(cin, inputText);
        decryption.beginDecrypt(inputText, outputName, fileType, keyword);
	} else if (methodType == 'e' && fileType == 't') {
		cout << "Enter text to encrypt: ";
		cin.ignore();
		getline(cin, inputText);
        encryption.beginEncrypt(inputText, outputName, fileType, keyword);
	}


}
