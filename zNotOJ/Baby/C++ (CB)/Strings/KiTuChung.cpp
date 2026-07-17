#include <bits/stdc++.h>

std::string x;
std::string y;

char items[2][26];

int main()
{
    // freopen("KiTuChung.Inp", "r", stdin);
    // freopen("KiTuChung.Out", "w", stdout);

    getline(std::cin, x);
    getline(std::cin, y);

    for (int i = 0; i < std::max(x.length(), y.length()); i++)
    {
        if (i < std::min(x.length(), y.length()))
        {
            items[0][x[i] - 'a'] = x[i];
            items[1][y[i] - 'a'] = y[i];
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (items[0][i] + items[1][i] > items[0][i] && items[0][i] + items[1][i] > items[1][i])
        {
            std::cout << items[0][i] << '\n';
        }
    }
}

