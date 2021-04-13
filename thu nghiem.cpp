#include <bits/stdc++.h>
using namespace std;

void input (char x[][5], int m, int n);
bool bomb (char x);
int countBomb (char s[][5], int a, int b);
void output (char x[][5], int m, int n);

int main()
{
    const int m = 3, n = 5;
    char s[m][n];
    input (s, m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (bomb(s[i][j]) ==  false) s[i][j] = countBomb(s, i, j);
    output (s, m, n);
    return 0;
}

void input (char s[][5], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> s[i][j];
}
bool bomb (char x)
{
    if (x == '*') return true;
    return false;
}
int countBomb (char s[][5], int a, int b)
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
void output (char s[][5], int m, int n)
{
    for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (s[i][j] != '*') cout << (int) s[i][j] << " ";
                    else cout << s[i][j] << " ";
            cout << endl;
        }
}
/*
* * . . .
. . . . .
. * . . .
*/
