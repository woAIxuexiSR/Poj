#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int len[2000010];
int cal(string t) 
{
    int mid = 0, rg = 0;
    for(int i = 0; i < t.size(); ++i) {
        if(i >= rg) {
            int k = min(i, (int)t.size() - i - 1);
            len[i] = 0;
            for(int j = 0; j <= k; ++j) {
                if(t[i - j] == t[i + j]) len[i]++;
                else break;
            }
            mid = i; rg = i + len[i] - 1;
        }
        else {
            int k = 2 * mid - i;
            if(len[k] + i - 1 < rg) len[i] = len[k];
            else {
                int u = min(i, (int)t.size() - i - 1);
                len[i] = rg + 1 - i;
                for(int j = rg + 1 - i; j <= u; ++j) {
                    if(t[i - j] == t[i + j]) len[i]++;
                    else break;
                }
                mid = i; rg = i + len[i] - 1;
            }
        }
    }
    int maxx = 0;
    for(int i = 0; i < t.size(); ++i) {
        maxx = maxx > len[i] ? maxx : len[i];
    }
    return maxx - 1;
}
int main()
{
    int n; cin >> n;
    string str, sstr;
    while(n--) {
        cin >> str;
        sstr.clear();
        sstr.push_back(')');
        for(int i = 0; i < str.size(); ++i) {
            sstr.push_back(str[i]);
            sstr.push_back(')');
        }
        cout << cal(sstr) << endl;
    }
    return 0;
}