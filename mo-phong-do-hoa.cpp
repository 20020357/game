#include <iostream>
#include "font.h"
using namespace std;
void print(vector<string> s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }
}
int main()
{
    vector<vector<string>> sentence;
    string sent;
    cin >> sent;
    for (int i = 0; i < sent.length(); i++)
    {
        switch (sent[i])
        {
        case 'a':
        case 'A':
            sentence.push_back(a);
            break;
        case 'b':
        case 'B':
            sentence.push_back(b);
            break;
        case 'c':
        case 'C':
            sentence.push_back(c);
        default:
            break;
        }
    }


    //in ra man hinh
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < sentence.size(); j++)
            cout << sentence[j][i] << " ";
        cout << endl;
    }
}
