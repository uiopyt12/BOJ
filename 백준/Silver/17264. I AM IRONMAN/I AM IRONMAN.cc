#include <bits/stdc++.h>
using namespace std;

vector <string> vicPlayer;

int main()
{
	int n, p, w, l, g;
	cin >> n >> p >> w >> l >> g;
	
	string tmp1;
	char tmp2;
	for (int i = 0; i < p; i++)
	{
		cin >> tmp1 >> tmp2;
		if (tmp2 == 'W')
			vicPlayer.push_back(tmp1);
	}

	int lp = 0;
	bool canWin;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp1;
		canWin = false;
		for (const auto it : vicPlayer)
		{
			if (it == tmp1)
			{
				canWin = true;
				break;
			}
		}
		
		if (canWin == true)
		{
			lp += w;
			if (lp >= g)
			{
				cout << "I AM NOT IRONMAN!!";
				return 0;
			}

		}
		else
		{
			lp -= l;
			lp = max(lp, 0);
		}
		
	}
	cout << "I AM IRONMAN!!";
}