#include <bits/stdc++.h>

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

using namespace std;

int t;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s;

        for (int i = 0; i < s.length(); i++)
        {
            int index = i;
            int maxDiff = 0;

            for (int j = i + 1; j <= i + 9 && j < s.length(); j++)
            {
                int diff = s[j] - (j - i);

                if (diff > maxDiff)
                {
                    maxDiff = diff;
                    index = j;
                }
                else if (diff == maxDiff)
                {
                    index = min(index, j);
                }
            }

            if (s[index] - (index - i) > s[i])
            {
                while (index > i)
                {
                    swap(s[index], s[index - 1]);
                    s[index - 1] -= 1;

                    index--;
                }
            }   
        }        

        cout << s << '\n';
    }

    return 0;
}