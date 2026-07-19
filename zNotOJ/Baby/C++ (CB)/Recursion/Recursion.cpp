#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int ToHop(int k, int n)
{
    if (k == n || k == 0)
    {
        return 1;
    }
    else
    {
        return ToHop(k - 1, n - 1) + ToHop(k, n - 1);
    }

}

int RecursiveGCD(int a, int b)
{
    if (b == 0)
    {
        return a + b;
    }
    else
    {
        return RecursiveGCD(b, a % b);
    }
}

int GCD(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (a * b == 0)
    {
        return a + b;
    }

	int r = a % b;

	if (r == 0)
	{
		return b;
	}
	else
	{
		while (r != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
}

int LuyThua(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        if (b % 2 == 0)
        {
            return LuyThua(a, b / 2) * LuyThua(a, b / 2);
        }
        else
        {
            return LuyThua(a, b / 2) * LuyThua(a, b / 2) * a;
        }
    }
}

int Count(int a)
{
    if (a / 10 == 0)
    {
        return 1;
    }
    else
    {
        return Count(a / 10) + 1;
    }
}

bool Check(int a[], int l, int r)
{
    if (l >= r)
    {
        return true;
    }
    else if (a[l] != a[r])
    {
        return false;
    }
    else
    {
        return Check(a, l + 1, r - 1);
    }
}

void Tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << '\n';
    }
    else
    {
        Tower(n - 1, a, c, b);
        cout << a << " -> " << c << '\n';
        Tower(n - 1, b, a, c);
    }
}



int a;
int b;

int n[7]{2, 3, 5, 3, 5, 3, 2};

int main()
{
    cout << "Nhap n = ";
    cin >> a;
    
    cout << "Cach giai:\n";
    Tower(a, 'A', 'B', 'C');

    cin >> b;
}
