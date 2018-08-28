#include<iostream>
using namespace std;
int n, m;
int c[100000];
bool check(int t) {
    int cnt = 1, ex = t;
    for(int i = 0; i < n; ++i) {
        if(c[i] > t) return false;
        if(ex >= c[i]) ex -= c[i];
        else {
            ex = t - c[i];
            cnt++;
        }
    }
    return cnt <= m;
}
int main()
{
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
        sum += c[i];
    }

    int lf = 0, rg = sum;
    while(lf <= rg) {
        int mid = lf + (rg - lf) / 2;
        if(check(mid)) rg = mid - 1;
        else lf = mid + 1;
    }
    cout << lf << endl;
    return 0;
}