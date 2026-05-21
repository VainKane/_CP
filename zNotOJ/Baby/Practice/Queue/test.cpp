#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main()
{
    q.push(1);
    q.push(2);

    cout << q.size();

    q.pop();
    
    cout << '\n' << q.front();

    return 0;
}