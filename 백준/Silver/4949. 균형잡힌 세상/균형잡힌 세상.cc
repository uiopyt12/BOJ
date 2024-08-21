#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string ln;
	do
	{
		getline(cin, ln, '\n');
		stack<char> st;
		while (!st.empty())
			st.pop();
		bool isBalanced = true;
		for (const auto& tmp : ln)
		{
			switch (tmp)
			{
			case '(':
				st.push(tmp);
				break;
			case '[':
				st.push(tmp);
				break;

			case ')':
				if (st.empty() == true)
					isBalanced = false;
				else if (st.top() == '(')
					st.pop();
				else {
					isBalanced = false;
					st.pop();
				}
				break;

			case ']':
				if (st.empty() == true)
					isBalanced = false;
				else if (st.top() == '[')
					st.pop();
				else {
					isBalanced = false;
					st.pop();
				}
				break;

			default:
				break;
			}
		}
		if (st.empty() == false) isBalanced = false;
		if (ln.length() == 1 && ln[0] == '.') break;
		else {
			if (isBalanced) cout << "yes\n";
			else cout << "no\n";
		}
	}
	while (true);
}