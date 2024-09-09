#include <bits/stdc++.h>
using namespace std;

string fizzbuzz[15] = {
"FizzBuzz",
"1",
"2",
"Fizz",
"4",
"Buzz",
"Fizz",
"7",
"8",
"Fizz",
"Buzz",
"11",
"Fizz",
"13",
"14"
};

bool isDigit(string& str)
{
	if (str[0] >= '0' && str[0] <= '9') return true;
	else return false;
}

int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int n1, o1;
	int offset;
	if (isDigit(s1) == true)
	{
		o1 = stoi(s1);
		n1 = o1 % 15;
		offset = o1 - n1;
		
		n1 += 3;
		n1 %= 15;
		if (isDigit(fizzbuzz[n1]) == true)
			cout << o1 + 3;
		else
			cout << fizzbuzz[n1];
	}
	else if (isDigit(s2) == true)
	{
		o1 = stoi(s2);
		n1 = o1 % 15;
		offset = o1 - n1;

		n1 += 2;
		n1 %= 15;
		if (isDigit(fizzbuzz[n1]) == true)
			cout << o1 + 2;
		else
			cout << fizzbuzz[n1];
	}
	else if (isDigit(s3) == true)
	{
		o1 = stoi(s3);
		n1 = o1 % 15;
		offset = o1 - n1;

		n1 += 1;
		n1 %= 15;
		if (isDigit(fizzbuzz[n1]) == true)
			cout << o1 + 1;
		else
			cout << fizzbuzz[n1];
	}
	
}