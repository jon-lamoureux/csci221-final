#ifndef DECRYPT_H_
#define DECRYPT_H_
#include <string>

class decrypt {
public:
	decrypt(){};
	int beginDecrypt(std::string& inputFile, std::string& outputFile, char& inputType);
};

#endif /* DECRYPT_H_ */

