#include <bits/stdc++.h>
using namespace std;

void input (vector <vector<char> > s, int m, int n);
bool bomb (char x);
int countBomb (vector <vector<char> > s, int a, int b);
void output (vector <vector <char> > s, int m, int n);

int main()
{
	const int m = 3, n = 5;
	vector <vector<char> > s(m);
	input (s, m, n);
	output (s, m, n);
	return 0;
}

void input (vector <vector<char> > s, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		s[i].resize(n);
		for (int j = 0; j < n; j++) cin >> s[i][j];
	}
}
bool bomb (char x)
{
	if (x == '*') return true;
	return false;
}
int countBomb (vector <vector<char> > s, int a, int b)
{
	int count = 0;
    if (a == 0)
    {
        for (int i = a; i <= a+1; i++)
            if (b == 0)
                {
                    for (int j = b; j <= b+1; j++)
                        if (bomb(s[i][j]) == true) count++;
                }
            else {
                for (int j = b-1; j <= b+1; j++)
                    if (bomb(s[i][j]) == true) count++;
            }
    }
    else {
        for (int i = a-1; i <= a+1; i++)
            if (b == 0)
                {
                    for (int j = b; j <= b+1; j++)
                        if (bomb(s[i][j]) == true) count++;
                }
            else {
                for (int j = b-1; j <= b+1; j++)
                    if (bomb(s[i][j]) == true) count++;
            }
    }
    return count;
}
void output (vector <vector <char> > s, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (bomb(s[i][j]) == false) s[i][j] = countBomb (s, i, j);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (s[i][j] != '*') cout << (char) s[i][j] << " ";
				else cout << s[i][j] << " ";
		cout << endl;
	}
}
