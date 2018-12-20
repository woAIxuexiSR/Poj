#include <iostream>
#include <vector>
#include <map>
using namespace std;

int a[100000], sum[100000];
int dp[100000], sumdp[100000];
int mod = 1000000007;
int main()
{
    int n;
    cin >> n;
    cin >> a[0]; sum[0] = a[0];
    for(int i = 1; i < n; ++i) {
        cin >> a[i];
        sum[i] = (sum[i - 1] + a[i]) % mod;
    }

    map<int, int> t;
    t.insert(make_pair(sum[0], 1));
    t.insert(make_pair(0, 1));
    dp[0] = 1; sumdp[0] = 1;
    for(int i = 1; i < n; ++i) {
        dp[i] = (sumdp[i - 1] - t[sum[i]] + mod + 1) % mod;
        sumdp[i] = (sumdp[i - 1] + dp[i]) % mod;
        t[sum[i]] = (t[sum[i]] + dp[i]) % mod;
    }
    cout << dp[n - 1] << endl;
    return 0;
}