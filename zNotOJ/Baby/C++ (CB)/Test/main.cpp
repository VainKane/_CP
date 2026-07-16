#include <bits/stdc++.h>

using namespace std;

int a[1000];
int n;
int target;

bool BinarySearch(int a[], int l, int r, int target)
{
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (target == a[mid])
        {
            return true;
        }
        else if (target < a[mid])
        {
            r = mid - 1;
        }
        else if (target > a[mid])
        {
            l = mid + 1;
        }
    }

    return false;
}

bool RecursiveBinarySearch(int a[], int l, int r, int target)
{
    if (l > r)
    {
        return false;
    }
    else
    {
        int mid = (l + r) / 2;

        if (target == a[mid])
        {
            return true;
        }
        if (target < a[mid])
        {
            return RecursiveBinarySearch(a, l, mid - 1, target);
        }
        else
        {
            return RecursiveBinarySearch(a, mid + 1, r, target);
        }
    }
}

int FirstSearch(int a[], int l , int r, int target)
{
    int mid;
    int result = r + 1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (target == a[mid])
        {
            if (mid < result)
            {
                result = mid;
                r  = mid - 1;
            }
        }
        else if (target < a[mid])
        {
            r = mid - 1;
        }
        else if (target > a[mid])
        {
            l = mid + 1;
        }
    }

    return result;
}

int cnt[10];

int count1 = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        
    }

    cout << count1;
}


