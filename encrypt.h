#ifndef ENCRYPT_H_
#define ENCRYPT_H_
#include <string>
using namespace std;

class encrypt {
public:
	encrypt(){};
	int beginEncrypt(string& inputFile, string& outputFile, char& inputType);
};

#endif /* ENCRYPT_H_ */
