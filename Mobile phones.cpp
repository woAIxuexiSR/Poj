#include<iostream>
using namespace std;
int n;
int tree[1025][1025];
int lowbit(int x) { return x & (-x); }
int sum(int x, int y) {
    int ans = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j)) {
            ans += tree[i][j];
        }
    return ans;
}
void tran(int x, int y, int k) {
    for(int i = x; i <= n; i += lowbit(i))
        for(int j = y; j <= n; j += lowbit(j)) {
            tree[i][j] += k;
        }
}
int main() {
    int ins;
    scanf("%d %d", &ins, &n);
    while(1) {
        scanf("%d", &ins);
        if(ins == 1) {
            int X, Y, A;
            scanf("%d %d %d", &X, &Y, &A);
            tran(X + 1, Y + 1, A);
        }
        else if(ins == 2) {
            int L, B, R, T;
            scanf("%d %d %d %d", &L, &B, &R, &T);
            printf("%d\n", sum(R + 1, T + 1) - sum(R + 1, B) - sum(L, T + 1) + sum(L, B));
        }
        else break;
    }
    return 0;
}