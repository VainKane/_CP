#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

struct point { double x; double y; };
long n, sd;
point d[maxn], p[maxn];
double a, b, c, sa, sb, s;

void nhap()
{
    long i;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> d[i].x >> d[i].y;
}

void ptdt(point p1, point p2, double &a, double &b, double &c)
{
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = -(a * p1.x + b * p1.y);
}

double f(point m)
{
    return (a * m.x + b * m.y + c);
}

bool cut(point p1, point p2)
{
    double f1, f2;
    f1 = f(p1); f2 = f(p2);
    if ((f1 == 0) && (f2 == 0)) return 0;
    return (f1 * f2 <= 0);
}

void giao2dt(point p1, point p2, point &gd)
{
    double a1, b1, c1, dd, dx, dy;
    ptdt(p1, p2, a1, b1, c1);
    dd = a * b1 - a1 * b;
    dx = c1 * b - c * b1;
    dy = a1 * c - a * c1;
    if (dd != 0) {
        gd.x = dx / dd;
        gd.y = dy / dd;

        // cout << "Inter: " << gd.x << ' ' << gd.y << '\n';
    }
}

void dientich(long sd)
{
    long i;
    s = 0; p[sd + 1] = p[1];
    for (i = 1; i <= sd; i++) 
        s += ((p[i].y + p[i + 1].y) * (p[i].x - p[i + 1].x));
    s = abs(s) / 2;
}

int mien()
{
    long i;
    double f1;
    for (i = 2; i <= sd - 1; i++) {
        f1 = f(p[i]);
        if (f1 != 0) {
            if (f1 > 0) return 1;
            else return 2;
        }
    }
    return 0;
}

void dagiac()
{
    int k;
    dientich(sd);
    k = mien();
    if (k == 1) sa = sa + s;
    if (k == 2) sb = sb + s;
}

void xuli()
{
    point p1, p2, gd;
    long i;
    sa = 0; sb = 0; s = 0;
    ptdt(d[1], d[n], a, b, c);
    p[1] = d[1];
    sd = 1;

    for (i = 2; i < n; i++) {
        sd++;
        p[sd] = d[i];
        p1 = d[i]; p2 = d[i + 1];
        if (cut(p1, p2) == 1) {
            giao2dt(p1, p2, gd);
            sd++;
            p[sd] = gd;
            dagiac();
            sd = 1;
            p[1] = gd;
        }
    }

    sd++;
    p[sd] = d[n];
    dagiac();

    cout << setiosflags(ios::fixed) << setprecision(4);
    cout << sa << endl;
    cout << sb;
}

int main()
{
    // freopen("land.inp", "r", stdin);
    // freopen("land.out", "w", stdout);
    nhap();
    xuli();
    return 0;
}
