#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int n, k, a[1000], b[1000];
double c[1000];
bool check(double t)
{
    for(int i = 0; i < n; ++i)
        c[i] = a[i] - b[i] * t;
    sort(c, c + n);
    double ans = 0;
    for(int i = k; i < n; ++i)
        ans += c[i];
    if(ans > 0) return true;
    return false;
}
int main()
{
    while(cin >> n >> k) {
        if(n == 0 && k == 0) break;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];

        double lf = 0, rg = 1;
        while(rg - lf > 1e-6) {
            double mid = (lf + rg) / 2;
            if(check(mid)) lf = mid;
            else rg = mid;
        }
        cout << fixed << setprecision(0) << rg * 100 << endl;
    }
    return 0;
}