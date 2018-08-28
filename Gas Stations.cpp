#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;
class P {
public:
    int d, x;
    P(int dd, int xx):d(dd),x(xx) {}
    bool operator<(const P &a) const {
        return d * a.x < x * a.d;
    }
};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int t, pret; 
    cin >> pret;
    priority_queue<P> q;
    for(int i = 1; i < n; ++i) {
        cin >> t; q.push(P(t - pret, 1));
        pret = t;
    }
    while(k--) {
        P u = q.top(); q.pop();
        u.x++; q.push(u);
    }
    P u = q.top();
    cout << fixed << setprecision(1) << u.d / double(u.x) << endl;
    return 0;
}



 /******************
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n, m, k, d[1000];
bool check(double s)
{
    int cnt = 0;
    for(int i = 1; i < n; ++i) {
        cnt += ceil(d[i] / s) - 1;
    }
    if(cnt <= k) return true;
    else return false;
}
int main()
{
    cin >> n >> m >> k;
    int t, pret = 0, maxd = 0;
    for(int i = 0; i < n; ++i) {
        cin >> t; d[i] = t - pret;
        pret = t;
        maxd = maxd > d[i] ? maxd : d[i];
    }
    double lf = 0, rg = maxd;
    while(rg - lf > 1e-6) {
        double mid = (lf + rg) / 2;
        if(check(mid)) rg = mid;
        else lf = mid;
    }
    cout << fixed << setprecision(1) << rg << endl;
    return 0;
}
***********************/