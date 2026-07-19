#include <bits/stdc++.h>

bool Check(long long n);
void Find(int k);

int k;

long long PerfectNums[10001];

int main()
{
    freopen("PerfectNum.inp", "r", stdin);
    freopen("PerfectNum.out", "w", stdout);

    std::cin >> k;

    Find(k);

    std::cout << PerfectNums[k - 1];
}

bool Check(long long n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    if (sum == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Find(int k)
{
    int count = 0;
    long long num = 19;

    while (count < k)
    {
        bool check = Check(num);

        if (Check(num) == true)
        {
            PerfectNums[count] = num;
            count += 1;
        }

        num += 1;
    }
}