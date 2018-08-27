#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Node {
public:
    int lf, rg;
    string t;
    bool value;
    Node():lf(-1),rg(-1),t("") {}
};
int n;
int p[100];
string s[100];
Node tree[100];
void calvalue(int i) {
    if(tree[i].lf == -1) {
        tree[i].value = (tree[i].t == "TRUE");
        return;
    }
    calvalue(tree[i].lf); calvalue(tree[i].rg);
    if(tree[i].t == "OR")
        tree[i].value = tree[tree[i].lf].value | tree[tree[i].rg].value;
    else
        tree[i].value = tree[tree[i].lf].value & tree[tree[i].rg].value;
}
int minchange(int i) {
    if(tree[i].lf == -1) return 1;
    int lf = minchange(tree[i].lf), rg = minchange(tree[i].rg);
    int ans = 0;
    if(tree[i].t == "OR") {
        if(tree[i].value) {
            if(tree[tree[i].lf].value && tree[tree[i].rg].value) ans = min(lf, rg) + 1;
            else ans = 1;
        }
        else ans = min(lf, rg);
    }
    else {
        if(tree[i].value) ans = min(lf, rg);
        else {
            if(!tree[tree[i].lf].value && !tree[tree[i].rg].value) ans = min(lf, rg) + 1;
            else ans = 1;
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> p[i] >> s[i];
        tree[i].t = s[i];
        if(tree[p[i]].lf == -1) tree[p[i]].lf = i;
        else tree[p[i]].rg = i;
    }
    
    calvalue(0);
    cout << minchange(0) << endl;
    return 0;
}