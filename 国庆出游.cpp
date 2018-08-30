#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
vector<int> e[101];
int num[101], minn[101], maxx[101];
bool dfs(int t, int k, int par)
{
    if(num[t] != -1 && num[t] < k) return false;
    int kk = k;
    if(num[t] != -1) kk = num[t];
    
    bool flag = 1;
    vector<int> p;
    for(int i = 0; i < e[t].size(); ++i) {
        if(e[t][i] == par) continue;
        if(!dfs(e[t][i], kk, t)) flag = 0;
        p.push_back(e[t][i]);
    }
    minn[t] = 1 << 20;
    for(int i = 0; i < p.size(); ++i) {
        for(int j = i + 1; j < p.size(); ++j) {
            if((minn[p[i]] - minn[p[j]]) * (maxx[p[i]] - maxx[p[j]]) < 0)
                flag = 0;
        }
        minn[t] = minn[p[i]] == -1 ? minn[t] : min(minn[p[i]], minn[t]);
        maxx[t] = maxx[p[i]] == -1 ? maxx[t] : max(maxx[p[i]], maxx[t]);
    }
    minn[t] = num[t] == -1 ? minn[t] : min(num[t], minn[t]);
    maxx[t] = num[t] == -1 ? maxx[t] : max(num[t], maxx[t]);
    if(minn[t] == 1 << 20) minn[t] = maxx[t] = -1;
    return flag;
}
int main()
{
    int t; cin >> t;
    while(t--) {
        for(int i = 0; i < 100; ++i) e[i].clear();

        cin >> n;
        int a, b;
        for(int i = 0; i < n - 1; ++i) {
            cin >> a >> b;
            e[a].push_back(b); e[b].push_back(a);
        }
        
        memset(num, -1, sizeof(num));
        memset(minn, -1, sizeof(minn));
        memset(maxx, -1, sizeof(maxx));
        cin >> m;
        for(int i = 0; i < m; ++i) {
            cin >> a;
            num[a] = i;
        }

        if(dfs(1, 0, -1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}