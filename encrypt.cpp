#include "encrypt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int encrypt::beginEncrypt(string& inputFile, string& outputFile, char& inputType) {
	  ofstream myfile;
	  myfile.open ("example.txt");
	  myfile << "Writing this to a file.\n";
	  myfile.close();
	// Overall if statement to decide whether we need to load a file or not
	if (inputType == 'f') {

	} else {

	}
	return 0;
}
