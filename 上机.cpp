#include<iostream>
#include<algorithm>
using namespace std;
int a[10000], b[10000], c[10000];
int dpy[10000], dpn[10000];
int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    
    dpy[0] = b[0]; dpn[0] = a[0];
    for(int i = 1; i < n; ++i)
    {
        dpy[i] = max(dpn[i-1]+c[i],dpy[i-1]+b[i]);
        dpn[i] = max(dpn[i-1]+b[i],dpy[i-1]+a[i]);
    }
    cout << dpn[n-1] << endl;
    return 0;
}