#include<iostream>
using namespace std;
int n;
int poww[5] = {10,100,1000,10000,100000};
int cnt[50] = {0};
int main()
{
    int ans = 0;
    cin >> n;

    for(int i = 0; i < poww[n/2 - 1]; ++i)
    {
        int t = 0, j = i;
        while(j != 0)
        {
            t += j%10;
            j /= 10;
        }
        cnt[t]++;
    }

    for(int i = 0; i <= 9*n/2; ++i)
    {
        ans += cnt[i]*cnt[i];
    }
    cout << ans << endl;
    return 0;
}