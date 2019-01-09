#include<iostream>
#include<vector>
using namespace std;
int n;
int lowbit(int x) { return x & (-x); }
vector<int> edge[100002];
int a[100002], s[100002];
int sum(int i) {
    int ans = 0;
    while(i > 0) {
        ans += s[i];
        i -= lowbit(i);
    }
    return ans;
}
void change(int i, int t) {
    while(i <= n) {
        s[i] += t;
        i += lowbit(i);
    }
}
int cnt = 0;
int dfsnum[100002], nextp[100002];
void dfs(int n, int pre) {
    ++cnt;
    dfsnum[n] = cnt;
    vector<int>::iterator p;
    for(p = edge[n].begin(); p != edge[n].end(); ++p)
        if((*p) == pre) {
            edge[n].erase(p);
            break;
        }

    for(int i = 0; i < edge[n].size(); ++i) {
        if(i != edge[n].size() - 1)
            nextp[edge[n][i]] = edge[n][i + 1];
        else nextp[edge[n][i]] = nextp[n];
        dfs(edge[n][i], n);
    }
}
int main() {
    cin >> n;
    int u, v;
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i) {
        a[i] = 1;
        s[i] = lowbit(i);
    }

    nextp[1] = n + 1;
    dfsnum[n + 1] = n + 1;
    dfs(1, 0);
    
    int m; cin >> m;
    char p;
    for(int i = 0; i < m; ++i) {
        scanf("\n%c %d", &p, &u);
        if(p == 'Q')
            cout << sum(dfsnum[nextp[u]] - 1) - sum(dfsnum[u] - 1) << endl;
        else {
            a[dfsnum[u]] = 1 - a[dfsnum[u]];
            change(dfsnum[u], 2 * a[dfsnum[u]] - 1);
        }
    }
    return 0;
}