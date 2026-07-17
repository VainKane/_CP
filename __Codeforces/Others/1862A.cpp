#include <bits/stdc++.h>

using namespace std;

int t;

int n;
int m;

char matrix[29][29];

string word;
string tar = "vika";
int id;

string s;   

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> s;

            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = s[j];
            }
        }

        word = "";
        id = 0;

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][j] == tar[id] && id < 4)
                {
                    word += tar[id];
                    id++;     
                    break;
                }
            }
        }

        if (word == "vika") cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}