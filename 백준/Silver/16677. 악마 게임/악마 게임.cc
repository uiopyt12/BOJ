#include <bits/stdc++.h>
using namespace std;


int main()
{
	string m;
	int n;
	cin >> m >> n;
	
	string w;
	int g;
	float effectiveScore = 0;
	string effectiveString;
	for (int rep=0; rep<n; rep++)
	{
		cin >> w >> g;

		int i=0, j=0;
		while (i<m.length() && j<w.length()) // 투포인터
		{
			if (m[i] == w[j]) i++;
			j++;
		}
		if (i == m.length())
		{
			if (effectiveString.length() == 0) // 가성비 단어가 없는 경우
			{
				effectiveString = w;
				effectiveScore = (float)g / (w.length() - m.length());
			}
			else if (effectiveScore < ((float)g / (w.length() - m.length()))) // 가성비 단어보다 가성비가 더 좋은 경우
			{
				effectiveString = w;
				effectiveScore = (float)g / (w.length() - m.length());
			}

		}
	}
	if (effectiveScore == 0)
		cout << "No Jam";
	else
		cout << effectiveString;
}