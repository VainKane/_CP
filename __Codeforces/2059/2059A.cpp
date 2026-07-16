#include <bits/stdc++.h>

using namespace std;

bool Check(map<int, int> cnta, map<int, int> cntb, int a[], int b[])
{
    if (cnta.size() >= 2 && cntb.size() >= 2) return true;
    if (cnta.size() >= 3 && cntb[b[0]] >= 3) return true;
    if (cntb.size() >= 3 && cnta[a[0]] >= 3) return true;

    return false;
}

int t;

int n;
int a[59];
int b[59];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        map<int, int> cnta;
        map<int, int> cntb;


        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnta[a[i]]++;
        } 
        for (int i = 0; i < n; i++) 
        {
            cin >> b[i];
            cntb[b[i]]++;
        }
        
        if (Check(cnta, cntb, a, b)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}