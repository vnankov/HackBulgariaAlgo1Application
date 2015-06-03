#include <iostream>
#include <string>

using namespace std;

string findBrackets(string& completeStrig)
{	
	size_t length = completeStrig.size();
	string convertedToBracketsString = "";
	for (int i = 0; i < length; i++)
	{
		 if (completeStrig[i] == '(')
			convertedToBracketsString += '(';
		 if (completeStrig[i] == ')')
			convertedToBracketsString += ')';
		 if (completeStrig[i] == '[')
			convertedToBracketsString += '[';
		 if (completeStrig[i] == ']')
			convertedToBracketsString += ']';
		 if (completeStrig[i] == '{')
			convertedToBracketsString += '{';
		 if (completeStrig[i] == '}')
			convertedToBracketsString += '}';
	}
	
	return convertedToBracketsString;
}

bool isValidBrackets(string& brackets)
{
	int rectangularBracket = 0, curlyBracket = 0, quadratedBracket = 0;
	size_t length = brackets.size();
	for (int i = 0; i < length; i++)
	{
		
		if (brackets[i] == '(')	rectangularBracket++;
		if (brackets[i] == ')')	rectangularBracket--;
		if (brackets[i] == '[')quadratedBracket++;
		if (brackets[i] == ']')	quadratedBracket--;
		if (brackets[i] == '{')curlyBracket++;
		if (brackets[i] == '}')	curlyBracket--;

		
		if (rectangularBracket <=0 && quadratedBracket<=0 && curlyBracket <=0 && i < length-1) {
			return false;
	
		}
	}
	if (rectangularBracket != 0 || quadratedBracket != 0 || curlyBracket != 0)
		return false;

	if	(  brackets[0] == '(' && brackets[length-1] != ')'
		|| brackets[0] == '[' && brackets[length - 1] != ']'
		|| brackets[0] == '{' && brackets[length - 1] != '}')
		return false;

	if ((brackets[0] != '(' && brackets[0] != '[' && brackets[0] != '{') ||
		brackets[length - 1] != ')' && brackets[length - 1] != ']' && brackets[length - 1] != '}')
		return false;

	return true;
}

void calculate(string& str)
{
	size_t length = str.size();
	int multiplayer = 1,sum = 0;
	string number = "";

	for (int i = 1; i < length-1; i++)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			sum += atoi(number.c_str()) * multiplayer;
			multiplayer *= 2;
			number = "";
		}
		else if (str[i] == ')' || str[i] == ']')
		{
			sum += atoi(number.c_str()) * multiplayer;
			multiplayer /= 2;
			number = "";
		}
		else 
			number += str[i];
	}
	sum += atoi(number.c_str())*multiplayer;
	
	cout << sum << "\n";
}
int main ()
{

	string str;
	cin >> str;

	if( isValidBrackets(str))
	{
		calculate(str);
		cout<<endl;
	}
	else
	{
		cout << "Not valid brackets mixtures" << endl;
	}


	system("pause");
	return 0;
}