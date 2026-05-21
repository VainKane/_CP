// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Array to store segment-tree
int const N = 3e5 + 5;
int seg[4 * N];

int n;
int a[N];

// Function to build segment-tree to
// answer range GCD queries
int build(int l, int r, int in, int* arr)
{
    // Base-case
    if (l == r)
        return seg[in] = arr[l];

    // Mid element of the range
    int mid = (l + r) / 2;

    // Merging the result of left and right sub-tree
    return seg[in] = __gcd(build(l, mid, 2 * in + 1, arr),
                           build(mid + 1, r, 2 * in + 2, arr));
}

// Function to perform range GCD queries
int query(int l, int r, int l1, int r1, int in)
{
    // Base-cases
    if (l1 <= l and r <= r1)
        return seg[in];
    if (l > r1 or r < l1)
        return 0;

    // Mid-element
    int mid = (l + r) / 2;

    // Calling left and right child
    return __gcd(query(l, mid, l1, r1, 2 * in + 1),
                 query(mid + 1, r, l1, r1, 2 * in + 2));
}

// Function to find the required length
int findLen(int* arr, int n)
{
    // Building the segment tree
    build(0, n - 1, 0, arr);

    // Two pointer variables
    int i = 0, j = 0;

    // To store the final answer
    int ans = INT_MAX;

    // Looping
    while (i < n) {

        // Incrementing j till we don't get
        // a gcd value of 1
        while (j < n and query(0, n - 1, i, j, 0) != 1)
            j++;

        if (j == n)
            break;

        // Updating the final answer
        ans = min((j - i + 1), ans);

        // Incrementing i
        i++;

        // Updating j
        j = max(j, i);
    }

    // Returning the final answer
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}

// Driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << findLen(a, n);

    return 0;
}