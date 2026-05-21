#include <bits/stdc++.h>

using namespace std;

int Search(string name, string &c)
{
    string can[10]{"CANH", "TAN", "NHAM", "QUY", "GIAP", "AT", "BINH", "DINH", "MAU", "KY"};
    string chi[12]{"THAN", "DAU", "TUAT", "HOI", "TI", "SUU", "DAN", "MAO", "THIN", "TY", "NGO", "MUI"};

    for (int i = 0; i < 10; i++)
    {
        if (can[i] == name) 
        {
            c = "can";
            return i;
        }
    }
    for (int i = 0; i < 12; i++)
    {
        if (chi[i] == name) 
        {
            c = "chi";
            return i;
        }
    }

    return -1;
}



int n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;

    string c;

    int u = Search(s, c); // nam den 

    if (c == can)
    {
        int v = n % 10; // nam dang xet

        if ()
    }

    return 0;
}