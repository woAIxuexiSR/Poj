#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n, k, turn = 0;
bool vis[5000];
bool check(int t)
{
    memset(vis, 0, sizeof(vis));
    vector<int> p;
    p.push_back(t); vis[t] = 1;
    for(int i = 0; i < turn; ++i) {
        int len = p.size();
        for(int j = 0; j < len; ++j) {
            int m = (p[j] - k) > 0 ? p[j] - k : 1;
            bool flag = 0;
            for(; m <= n; ++m) {
                if(!vis[m]) {
                    vis[m] = 1; p.push_back(m);
                    flag = 1; break;
                }
            }
            if(!flag) return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> k;
    int nn = n;
    while(nn != 1) { nn /= 2; turn++; }
    int lf = 1, rg = n;
    while(lf <= rg) {
        int mid = (lf + rg) / 2;
        if(check(mid)) lf = mid + 1;
        else rg = mid - 1;
    }
    cout << rg << endl;
    return 0;
}