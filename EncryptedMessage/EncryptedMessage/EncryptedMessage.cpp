#include <iostream>
#include <string>

using namespace std;

string fullMessage;

void swapBackString(string &string)
{
	int length=string.length();
	string = string.substr(length/2,length) + string.substr(0,length/2);
}

void encrypt()
{
	int lengthOfAlphabet, lengthOfKey, lengthOfEncryptedMessage;
	string alphabetOfMessage, key, encryptedMessage;

	lengthOfAlphabet = atoi( fullMessage.substr( 0, fullMessage.find('~') ).c_str() );
	fullMessage.erase(0, fullMessage.find('~')+1);

	alphabetOfMessage = fullMessage.substr(0, lengthOfAlphabet);
	fullMessage.erase(0, lengthOfAlphabet);

	lengthOfKey = atoi( fullMessage.substr( fullMessage.find('~')+1, fullMessage.length() ).c_str() );
	fullMessage.erase( fullMessage.find('~'), fullMessage.length() );

	key = fullMessage.substr(fullMessage.length()-lengthOfKey, lengthOfKey);
	fullMessage.erase(fullMessage.length()-lengthOfKey, lengthOfKey);

	encryptedMessage = fullMessage;
	lengthOfEncryptedMessage = encryptedMessage.length();
	
	for(int tempKeyLenght=lengthOfKey; tempKeyLenght<lengthOfEncryptedMessage; tempKeyLenght++)
		key += key[tempKeyLenght-lengthOfKey];

	int* massageIndexes = new int[lengthOfEncryptedMessage];
	int *keyIndexes = new int[lengthOfEncryptedMessage];
	int* encryptIndexes = new int[lengthOfEncryptedMessage];

	for(int i=0;i<lengthOfEncryptedMessage;i++)
	{
		keyIndexes[i] = alphabetOfMessage.find(key[i]);
		encryptIndexes[i] = alphabetOfMessage.find(encryptedMessage[i]);

		massageIndexes[i] = encryptIndexes[i] - keyIndexes[i];
		if(massageIndexes[i] < 0)
			massageIndexes[i] += lengthOfAlphabet;
	}
	for(int i=0;i<lengthOfEncryptedMessage;i++)
		cout << alphabetOfMessage[ massageIndexes[i] ];
	cout << endl;
}

int main()
{
	getline(cin,fullMessage);
	swapBackString(fullMessage);
	encrypt();

	system("pause");
	return 0;
}