#include <bits/stdc++.h>

bool Check(int n);

int times;
int n;

int main()
{
    freopen("triangular.inp", "r", stdin);
    freopen("triangular.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> n;
        std::cout << Check(n) << '\n';
    }

    

}

bool Check(int n)
{
    int sum = 0;
    int count = 0;

    while(n > sum)
    {
        count += 1;
        sum += count;

        if (n == sum)
        {
            return true;
        }
    }

    return false;
}

