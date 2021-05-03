#ifndef DECRYPT_H_
#define DECRYPT_H_
#include <string>
using namespace std;

class decrypt {
public:
	decrypt(){};
	int beginDecrypt(string& inputFile, string& outputFile, char& inputType);
};

#endif /* DECRYPT_H_ */

