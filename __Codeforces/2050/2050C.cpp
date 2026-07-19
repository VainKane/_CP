#include <bits/stdc++.h>

using namespace std;

bool Check(string n, int cnt2, int cnt3, int sum)
{
    while (sum % 3 && cnt2)
    {
        sum += 2;
        cnt2--;
    }

    if (sum % 3 != 0) return false;

    if (sum % 9 == 0) return true;

    else if (sum == 3)
    {
        if (cnt3 >= 1) return true;
    }
    else 
    {
        if (((sum / 3) + 2) % 3 == 0 && (cnt3 >= 1 || cnt2 >= 3)) return true;
        if (((sum / 3) + 4) % 3 == 0 && (cnt3 >= 2 || cnt2 >= 6|| (cnt2 >= 3 && cnt3 >= 1))) return true; 
    }

    return false;
}

int t;
string n;

int sum = 0;

int cnt2;
int cnt3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        sum = cnt2 = cnt3 = 0;

        for (char num : n)
        {
            if (num == '2') cnt2++;
            else if (num == '3') cnt3++;

            sum += num - '0';
        }

        if (Check(n, cnt2, cnt3, sum)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}