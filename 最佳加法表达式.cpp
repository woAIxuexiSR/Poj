/* 大整数加法，动态规划 */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class BigInt {
public:
    string num;
    BigInt() { num.clear(); }
    BigInt(const string &a, int start, int end) {
        num.clear();
        for(int i = start; i <= end; ++i) {
            num.push_back(a[i]);
        }
    }
    void set_to_max() {
         num = "1"; 
         for(int i = 0; i < 50; ++i) num.push_back('0');
    }
    BigInt operator+(const BigInt &a) const {
        string t;
        int p1 = num.size(), p2 = a.num.size();
        int len = min(p1, p2), extra = 0;
        while(len > 0) {
            p1--; p2--; len--;
            int u = (num[p1] - '0') + (a.num[p2] - '0') + extra;
            extra = u / 10; t.push_back('0' + u % 10);
        }
        string llong;
        if(p1 != 0) llong = num, len = p1; 
        else llong = a.num, len = p2;
        while(len > 0) {
            len--;
            int u = llong[len] - '0' + extra;
            extra = u / 10; t.push_back('0' + u % 10);
        }
        if(extra != 0) t.push_back('0' + extra);
        BigInt ans;
        for(int i = t.size() - 1; i >= 0; --i)
            ans.num.push_back(t[i]);
        return ans;
    }
    bool operator<(const BigInt &a) const {
        if(num.size() < a.num.size()) return true;
        if(num.size() > a.num.size()) return false;
        for(int i = 0; i < num.size(); ++i) {
            if(num[i] < a.num[i]) return true;
            if(num[i] > a.num[i]) return false;
        }
        return true;
    }
};
BigInt dp[50][50];
int main()
{
    int m; string n;
    while(cin >> m) {
        cin >> n;
        for(int i = 0; i < n.size(); ++i) {
            dp[i][0] = BigInt(n, 0, i);
        }
        for(int i = 1; i < n.size(); ++i) {
            for(int j = 1; j <= m; ++j) {
                if(j > i) break;
                dp[i][j].set_to_max();
                for(int k = j - 1; k < i; ++k) {
                    BigInt t = dp[k][j-1] + BigInt(n, k+1, i);
                    if(t < dp[i][j])
                        dp[i][j] = t;
                }
                //cout << i << " " << j << " " << dp[i][j].num << endl;
            }
        }
        cout << dp[n.size() - 1][m].num << endl;
    }
    return 0;
}