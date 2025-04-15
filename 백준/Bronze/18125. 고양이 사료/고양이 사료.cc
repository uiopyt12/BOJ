#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int b[100][100];

int main()
{
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			cin >> a[j][c-1-i];
	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> b[i][j];

	bool canEat = true;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] != b[i][j]) canEat = false;

	if (canEat == true)
	{
		printf("|>___/|        /}\n");
		printf("| O < |       / }\n");
		printf("(==0==)------/ }\n");
		printf("| ^  _____    |\n");
		printf("|_|_/     ||__|\n");
	}
	else
	{
		printf("|>___/|     /}\n");
		printf("| O O |    / }\n");
		printf("( =0= )\"\"\"\"  \\\n");
		printf("| ^  ____    |\n");
		printf("|_|_/    ||__|\n");
	}
}