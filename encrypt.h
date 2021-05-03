#ifndef ENCRYPT_H_
#define ENCRYPT_H_
#include <string>

class encrypt {
public:
	encrypt(){};
	int beginEncrypt(std::string& inputFile, std::string& outputFile, char& inputType);
};

#endif /* ENCRYPT_H_ */
