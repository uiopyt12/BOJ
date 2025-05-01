#include <bits/stdc++.h>
using namespace std;

typedef struct info
{
	int teamNumber;
	int score;
	int ranking;
};

bool compareByteamNumber(const info& a, const info& b){
	return a.teamNumber > b.teamNumber;
}
bool compareByscore(const info& a, const info& b) {
	return a.score > b.score;
}
bool compareByranking(const info& a, const info& b) {
	return a.ranking > b.ranking;
}

int main()
{
	int n;
	cin >> n;
	int a, b, c, d;
	vector<info> arr(n, { 0,0,0 });
	for (int i = 0; i < n; i++)
		arr[i].teamNumber = i + 1;

	for (int i = 0; i < n * (n - 1) / 2; i++)
	{
		cin >> a >> b >> c >> d;
		if (c > d)
			arr[a - 1].score += 3;
		else if (c == d)
			arr[a - 1].score++, arr[b - 1].score++;
		else
			arr[b - 1].score += 3;
	}

	sort(arr.begin(), arr.end(), compareByscore);
	arr[0].ranking = 1;
	for (int i = 1; i < n; i++)
	{
		int preScore = arr[i - 1].score;
		if (preScore == arr[i].score)
			arr[i].ranking = arr[i - 1].ranking;
		else
			arr[i].ranking = i + 1;
	}

	sort(arr.begin(), arr.end(), compareByteamNumber);
	reverse(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
		cout << arr[i].ranking << '\n';

}