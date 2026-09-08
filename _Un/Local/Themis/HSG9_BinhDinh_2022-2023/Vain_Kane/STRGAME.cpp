#include <bits/stdc++.h>

using namespace std;

int n;
int k;

string str;

int chr[30];

bool isCase1 = false;
bool isCase3 = false;
string case4 = "..";

bool check = true;
bool minCheck = true;

int sum = 0;

int main()
{
    cin >> n >> k;
    cin.ignore();

    getline(cin, str);

    for (int i = 0; i < 26; i++)
    {
        chr[i] = 0;
    }


    for (int i = 0; i < str.length(); i++)
    {
        chr[str[i] - 'a'] += 1;
    }


    for (int i = 0; i < 26; i++)
    {
        int minValue = -1;
        if (chr[i] > 0 && minCheck == true)
        {
            minValue = i;
            minCheck = false;
        }

        if (chr[i] == k && check == true)
        {
            check = false;

            case4[0] = (char)('a' + i);
            int count = 0;

            for (int j = 0; j < 26; j++)
            {
                if (i != j && chr[j] > 0)
                {
                    case4[1] = (char)('a' + j);
                    count += 1;
                }
            }
            if (count != 1)
            {
                case4[1] = '.';

                if (i == minValue)
                {
                    chr[i] = chr[i] - (k - 1);
                    isCase1 = true;
                }

                break;
            }
            else
            {
                break;
            }
        }


        else if (chr[i] > k)
        {
            if (i == minValue)
            {
                chr[i] = chr[i] - (k - 1);
                isCase1 = true;
            }
            break;
        }
    }


    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (chr[i] == 0)
        {
            count += 1;
        }
    }

    if (count == 25)
    {
        isCase3 = true;
    }

    //-------------------------------

//    cout << isCase1 << '\n';
//    cout << isCase3 << '\n';
//    cout << case4 << '\n';

//    for (int i = 0; i < 26; i++)
//    {
//        cout << (char)(i + 'a') << chr[i] << '\n';
//    }

    //-------------------------------


    if (isCase3 == true)
    {
        int d;

        if (str.length() % k == 0)
        {
            d = 0;
        }
        else
        {
            d = 1;
        }

        for (int i = 0; i < (str.length() / k) + d; i++)
        {
            cout << str[0];
        }
    }
    else
    {
        if (case4[1] != '.')
        {
            cout << case4[0];
            int d;

            if (str.length() % k == 0)
            {
                d = 0;
            }
            else
            {
                d = 1;
            }

            for (int j = 0; j < (chr[case4[1] - 'a'] / k) + d; j++)
            {
                cout << case4[1];
            }
        }
        else
        {
            if (isCase1 == true)
            {
                for (int i = 0; i < 26; i++)
                {
                    for (int j = 0; j < chr[i]; j++)
                    {
                        cout << (char)('a' + i);
                    }
                }
            }
            else
            {
                for (int i = 0; i < 26; i++)
                {
                    sum += chr[i];
                    if (sum >= k)
                    {
                        cout << (char)('a' + i);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
