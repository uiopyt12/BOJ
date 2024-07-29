#include <bits/stdc++.h>
#define row first
#define col second
using namespace std;

int board[50][50];
int arr[13];
pair <int, int> kfcCoord[13];
pair <int, int> houseCoord[100];
int n, m;
int minDstnc=INT_MAX, curDstnc;
int houseIDX, kfcIDX;

void calculateDstnc(int paramBoard[50][50])
{
	curDstnc = 0;
	for (int i = 0; i < houseIDX; i++)
	{
		int dstnc = INT_MAX;
		for (int j = 0; j < kfcIDX; j++)
		{
			if (arr[j] == 0) continue;
			dstnc = min(dstnc, abs(houseCoord[i].row - kfcCoord[j].row) + abs(houseCoord[i].col - kfcCoord[j].col));
		}
		curDstnc += dstnc;
	}
}

void updateKFC()
{
	int tempBoard[50][50];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		tempBoard[i][j] = board[i][j];

	for (int i = 0; i < kfcIDX; i++)
	{
		tempBoard[kfcCoord[i].row][kfcCoord[i].col] = arr[i];
	}

	calculateDstnc(tempBoard);

	minDstnc = min(minDstnc, curDstnc);
}


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				houseCoord[houseIDX].row = i, houseCoord[houseIDX].col = j;
				houseIDX++;
			}
			else if (board[i][j] == 2)
			{
				kfcCoord[kfcIDX].row = i, kfcCoord[kfcIDX].col = j;
				kfcIDX++;
			}
		}
	}

	
	for (int i = kfcIDX-m; i < kfcIDX; i++)
	{
		arr[i] = 2;
	}

	do
	{
		updateKFC();
		
	} while (next_permutation(arr, arr + kfcIDX));
	
	cout << minDstnc;
}