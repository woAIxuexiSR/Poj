#include<iostream>
using namespace std;
const int mod = 1000000007;
long long comb[1001][1001];
long long dp[1001];
int main()
{
    int n; cin >> n;

    comb[1][0] = comb[1][1] = 1;
    for(int i = 2; i <= n; ++i) {
        comb[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }

    long long tmp = 0;
    for(int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for(int j = 1; j < i; ++j)
            dp[i] = (dp[i] + comb[i][j] * dp[i - j]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}