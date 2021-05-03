OBJS    = decrypt.o encrypt.o VigenereCipher.o
SOURCE  = decrypt.cpp encrypt.cpp VigenereCipher.cpp
HEADER  = decrypt.h encrypt.h
OUT     = vigenere.out
CC       = g++
FLAGS    = -g -c -Wall
LFLAGS   =

all: $(OBJS)
        $(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

decrypt.o: decrypt.cpp
        $(CC) $(FLAGS) decrypt.cpp

encrypt.o: encrypt.cpp
        $(CC) $(FLAGS) encrypt.cpp

VigenereCipher.o: VigenereCipher.cpp
        $(CC) $(FLAGS) VigenereCipher.cpp


clean:
        rm -f $(OBJS) $(OUT)
