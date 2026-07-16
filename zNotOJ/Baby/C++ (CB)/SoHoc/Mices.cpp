#include <bits/stdc++.h>

void Sort(int nums[], int n);
void Input(int nums[], int n);


int mices[10000];
int nests[10000];
int maxDifference;

int times;
int n;

int main()
{
    freopen("Mices.inp", "r", stdin);
    freopen("Mices.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> n;

        Input(mices, n);
        Input(nests, n);

        Sort(mices, n);
        Sort(nests, n);

        maxDifference = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (maxDifference < abs(mices[i] - nests[i]))
            {
                maxDifference = abs(mices[i] - nests[i]);
            }
        }

        std::cout << maxDifference << '\n';
    }

    
}

void Input(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
}

void Sort(int nums[], int n)
{
    int minIndex;    

    for (int i = 0; i < n; i++)
    {
        minIndex = i;

        for (int j = i; j < n; j++)
        {
            if (nums[minIndex] > nums[j])
            {
                minIndex = j;
            }

        }
        
        std::swap(nums[minIndex], nums[i]);
    }
}