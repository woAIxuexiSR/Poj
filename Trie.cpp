#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct T {
    int n; char c;
    T(int nn, int cc): n(nn), c(cc) {}
};
struct Node {
    int cnt;
    vector<T> child;
    Node():cnt(0) { child.clear(); }
};
int tot = 0;
Node tree[600000];
void add(int node, string t, int pos) {
    tree[node].cnt++;
    if(t.size() == pos) return;
    for(int i = 0; i < tree[node].child.size(); ++i) {
        if(tree[node].child[i].c == t[pos]) {
            add(tree[node].child[i].n, t, pos + 1);
            return;
        }
    }
    tree[node].child.push_back(T(++tot, t[pos]));
    add(tot, t, pos + 1);
}
int query(int node, string t, int pos) {
    if(t.size() == pos) return tree[node].cnt;
    for(int i = 0; i < tree[node].child.size(); ++i) {
        if(tree[node].child[i].c == t[pos])
            return query(tree[node].child[i].n, t, pos + 1);
    }
    return 0;
}
int main()
{
    int n, m; string t;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        add(0, t, 0);
    }
    cin >> m;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        cout << query(0, t, 0) << endl;
    }
    return 0;
}