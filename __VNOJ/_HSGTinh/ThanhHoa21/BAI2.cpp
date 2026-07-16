#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define name "BAI2"

string s1;
string s2;

int n;

vector<string> str1;
vector<string> str2;

int res = 0;

void Spilt(string s, vector<string> &str)
{
    string word = "";
    for (auto ch : s)
    {
        word += ch;
        if (ch == ' ')
        {
            str.push_back(word);
            word = "";
        }
    }
}

void Count(string s, vector<pair<char, int>> &cnt)
{
    cnt.clear();
    int l = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            cnt.push_back({s[i - 1], l});
            l = 1;
        }
        else l++;
    }
}

bool Check(string s1, string s2)
{
    vector<pair<char, int>> cnt1;
    vector<pair<char, int>> cnt2;

    Count(s1, cnt1);
    Count(s2, cnt2);

    if (cnt1.size() != cnt2.size()) return false;

    for (int j = 0; j < cnt1.size(); j++)
    {
        if (cnt1[j].F != cnt2[j].F) return false;
        if (cnt1[j].S < cnt2[j].S) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    getline(cin, s1);
    getline(cin, s2);

    s1 = s1 + " ";
    s2 = s2 + " ";

    Spilt(s1, str1);
    Spilt(s2, str2);

    for (int i = 0; i < str1.size(); i++)
    {
        if (Check(str1[i], str2[i]))
        {
            res++;
        }
    }

    cout << res;
    
    return 0;
}