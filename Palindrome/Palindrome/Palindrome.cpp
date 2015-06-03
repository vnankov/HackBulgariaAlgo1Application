#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isPalindrome(string checkThisString)
{
    string reversedString = "";
	for(int i = checkThisString.length() - 1; i >= 0; i--)
	{
		reversedString = reversedString + checkThisString[i];
    }
        
	if(checkThisString.compare(reversedString) == 0) 
		return true;

       return false;
}
	
vector<string> rotateWords(string myString)
{
	int temp = 1;
	string finalString="";
	vector<string> rotatedWords;
	string* arrayList= new string[myString.length()];
		
	string firstWordPart="";
	string secondWordPart="";
		
	for(int i = 0; i < myString.length(); i++)
	{
		firstWordPart.append(myString,0,temp);
		secondWordPart.append(myString,temp,myString.length());
		finalString = secondWordPart + firstWordPart;
			
		rotatedWords.push_back(finalString);
			
		finalString="";
		firstWordPart="";
		secondWordPart="";
		
		temp++;
	}
	return rotatedWords;
}

int main()
{
	string word;
	cout << "Please enter string:";
	cin >> word;
	vector<string> myVector;
	myVector = rotateWords(word);
	bool palindrome = false;
	for (unsigned int i = 0; i < myVector.size(); i++)
	{
		if(isPalindrome(myVector[i]))
		{
			cout << "THIS IS PALINDROME: " << myVector[i] << endl;
			palindrome = true;
		}	
	}

	if(palindrome==false)
	{
		cout << "NONE" << endl;
	}
	system("pause");
	return 0;
}