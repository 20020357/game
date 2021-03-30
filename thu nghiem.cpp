#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void input (vector <vector <char> > arr);
void output (vector <vector <char> > arr);
int countBomb (vector <vector <char> > arr, int i, int j);

int main()
{
    const int size = 5;
    vector <vector <char> > screen(size);
    input(screen);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            if (screen[i][j] == '.') screen[i][j] = countBomb(screen, i, j);
    }
    output(screen);
    return 0;
}

void input (vector <vector <char> > arr)
{
    cerr << "input...\n";
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr.size(); j++)
        {
            char temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
}
int countBomb (vector <vector <char> > arr, int a, int b)
{
    cerr << "count\n";
    int count = 0;
    if (a == 0)
        {
            for (int i = a; i <= a+1; i++)
                if ( b == 0)
                    {
                        for (int j = b; j <= b+1; j++)
                            if (arr[i][j] == '*') count++;
                    }
                else {
                    for (int j = b-1; j <= b+1; j++)
                        if (arr[i][j] == '*') count++;
                }
        }
    else {
        for (int i = a-1; i <= a+1; i++)
            if ( b == 0)
                {
                    for (int j = b; j <= b+1; j++)
                        if (arr[i][j] == '*') count++;
                }
            else {
                for (int j = b-1; j <= b+1; j++)
                    if (arr[i][j] == '*') count++;
            }
    }
    return count;
}
void output (vector <vector <char> > arr)
{
    cerr << "output";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
/* 

***..
.*..*
.....
*...*
..*.. 

*/