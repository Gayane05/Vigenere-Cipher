#include "Functions.h"


int GenerateKeyLength() {
	cout << "Generated length of the key \n";
	return rand() % 10 + 3;
}


void GenerateKeyWord(int length, char* key) {
	cout << "Generated key \n";
	for (int i = 0; i < length; i++) {
		key[i] = rand() % (90 - 65 + 1) + 65;
	}
}


void ToUpperSourceData(int length, char* source) {
	for (int i = 0; i < length; i++) {
		source[i] = toupper(source[i]);
	}
}

void CreateMatrix(char mat[27][27], int size) {
	int f = 0;
	char z;

	for (int i = 1; i <= size - 1; i++) {
		for (int j = 1; j < size - i + 1; j++) {
			mat[i][j] = 65 + j + i - 2;
		}
	}

	for (int i = 1; i < size; i++) {
		f = 0;
		for (int l = size - i + 1; l < size; l++) {
			z = 65 + f;
			mat[i][l] = z;
			f++;
		}
	}
}

void PrintMatrix(char mat[27][27], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void EncryptSourceData(char* key, int keyL, char* source, unsigned sourceL, char* encData) {
	int l = 0;
	char s[50] = "";
	strcpy(s, source);

	ToUpperSourceData(sourceL, s);

	if (sourceL > keyL) {
		while (strlen(key) < sourceL) {
			key[keyL] = key[l];
			keyL++;
			l++;
		}
	}
	else if (sourceL < keyL) {
		key[sourceL] = '\0';
	}

	for (unsigned int i = 0; i < sourceL; i++) {
		encData[i] = (((s[i] + key[i]) % 26) + 'A');
		if (source[i] >= 97 && source[i] <= 122) {
			encData[i] = tolower(encData[i]);
		}
	}
}


void DecryptEncData(char* key, char* source, int sourceL, char* encData, int encDataL, char* decData) {
	for (int i = 0; i < sourceL; i++) {
		if (encData[i] >= 96 && encData[i] <= 122) {
			decData[i] = ((((encData[i] - 32) - key[i] + 26) % 26) + 'A');
			decData[i] = tolower(decData[i]);
		}
		else{
			decData[i] = ((encData[i] - key[i] + 26) % 26) + 'A';
		}
	}
}
