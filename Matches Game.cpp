/* 尼姆博弈，所有堆的火柴数异或结果为0时，后手胜 */

#include<iostream>
using namespace std;
int main()
{
    int n, m;
    while(cin >> n)
    {
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> m;
            ans ^= m;
        }
        if(ans != 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}