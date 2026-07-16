#include <bits/stdc++.h>

using namespace std;

int n;
int t;
queue<string> q;

string res[(int)1e5 + 10];
int id = 0;

int main()
{
    cin >> t;

    q.push("1");

    for (int i = 0; i < 100000; i++)
    {
        q.push(q.front() + "0");
        q.push(q.front() + "1");

        res[id] = q.front();
        id++;

        q.pop();
    }

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << res[i] << ' ';
        }

        cout << '\n';
    }
    
    return 0;
}