#pragma once
#include <cstdlib>
#include <time.h>  
#include <cstring>
#include <iostream>
using namespace std;

int GenerateKeyLength();
void GenerateKeyWord(int length, char* key);
void PrintMatrix(char mat[27][27], int size);
void CreateMatrix(char mat[27][27], int size);
void ToUpperSourceData(int length, char* source);
void EncryptSourceData(char* key, int keyL, char* source, unsigned sourceL, char* encData);
void DecryptEncData(char* key, char* source, int sourceL, char* encData, int encDataL, char* decData);
