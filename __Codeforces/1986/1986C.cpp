#include <bits/stdc++.h>

using namespace std;

void SortString(string &str)
{
    int cnt[30];

    memset(cnt, 0, sizeof cnt);

    string res = "";

    for (char key : str)
    {
        cnt[key - 'a']++;
    }

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            res += (char)(i + 'a');
        }
    }

    str = res;
}

int t;
int n;
int m;

string s;
string c;

set<int> ind;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        cin >> s;

        ind.clear();

        while (m--)
        {
            int index;
            cin >> index;
            ind.insert(index - 1);
        }

        cin >> c;

        SortString(c);

        int id = 0;

        for (auto index : ind)
        {
            s[index] = c[id];
            id++;
        }

        cout << s << '\n';
    }

    return 0;
}