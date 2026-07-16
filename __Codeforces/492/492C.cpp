#include <bits/stdc++.h>

using namespace std;

struct Exam
{
    int a;
    int b;
};

bool cmp(Exam a, Exam b)
{
    return (a.b < b.b);
}

int n;
int r;
int avg;

Exam exams[(int)1e6 + 10];

long long sum = 0;
long long miss = 0;

long long res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> r >> avg;

    for (int i = 0; i < n; i++) 
    {
        cin >> exams[i].a >> exams[i].b;
        sum += 1LL * exams[i].a;
    }

    miss = 1LL * n * avg - sum;

    sort(exams, exams + n, cmp);

    for (int i = 0; i < n; i++)
    {
        if (miss < 0) break;
        
        long long t = r - exams[i].a;
        miss -= 1LL * t;
        if (miss < 0) t -= -1LL * miss;
        
        res += 1LL * (t) * exams[i].b;
    }

    cout << res;

    return 0;
}