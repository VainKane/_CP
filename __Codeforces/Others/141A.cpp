#include <bits/stdc++.h>

using namespace std;

bool Check(int cnt[], int cnt1[])
{
    for (int i = 0; i <= 26; i++)
    {
        if (cnt1[i] != cnt[i]) return false;
    }

    return true;
}

string name1;
string name2;
string str;

int cnt[30];

int cnt1[30];

int main()
{
    cin >> name1;
    cin >> name2;
    cin >> str;

    for (char key : name1)
    {
        cnt[key - 'A']++;
    }

    for (char key : name2)
    {
        cnt[key - 'A']++;
    }

    for (char key : str)
    {
        cnt1[key - 'A']++;
    }

    if (Check(cnt, cnt1)) cout << "YES";
    else cout << "NO";
}