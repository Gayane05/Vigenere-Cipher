#include "Functions.h"
const int SIZE = 27;

int main() {

	char mat[SIZE][SIZE] = { 0 };
	int keyLength = 0;
	char keyWord[50] = "";
	char sourceData[50] = "";
	char encryptedData[50] = "";
	char decryptedData[50] = "";
	srand(time(NULL));

	CreateMatrix(mat, SIZE);

	PrintMatrix(mat, SIZE);

	keyLength = GenerateKeyLength();
	cout << keyLength << endl;
	
	GenerateKeyWord(keyLength,keyWord);
	cout << keyWord << endl;

	cout << "\nInsert source data(A-Z,a-z)\n";
	cin >> sourceData;


	cout << "\nEncrypted data\n";
	EncryptSourceData(keyWord,keyLength,sourceData,strlen(sourceData), encryptedData);
	cout << encryptedData << endl;

	cout << "\nDecrypted data\n";
	DecryptEncData(keyWord, sourceData, strlen(sourceData), encryptedData, strlen(encryptedData), decryptedData);
	cout << decryptedData << endl;
	
	system("pause");
}
