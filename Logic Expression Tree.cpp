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
int p[101];
string s[101];
Node tree[101];
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
    if(tree[i].lf == -1) return -1;
    int lf = minchange(tree[i].lf), rg = minchange(tree[i].rg);
    int ans = 0;
    if(tree[i].t == "OR") {
        if(tree[i].value) {
            if(tree[tree[i].lf].value && tree[tree[i].rg].value) {
                if(lf != -1 && rg != -1) ans = min(lf, rg) + 1;
                else if(lf == -1 && rg == -1) ans = -1;
                else ans = max(lf, rg) + 1;
            }
            else ans = 1;
        }
        else {
            if(lf != -1 && rg != -1) ans = min(lf, rg);
            else ans = max(lf, rg);
        }
    }
    else {
        if(tree[i].value) {
            if(lf != -1 && rg != -1) ans = min(lf, rg);
            else ans = max(lf, rg);
        }
        else {
            if(!tree[tree[i].lf].value && !tree[tree[i].rg].value) {
                if(lf != -1 && rg != -1) ans = min(lf, rg) + 1;
                else if(lf == -1 && rg == -1) ans = -1;
                else ans = max(lf, rg) + 1;
            }
            else ans = 1;
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    int root;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i] >> s[i];
        if(p[i] == 0) root = i;
        tree[i].t = s[i];
        if(tree[p[i]].lf == -1) tree[p[i]].lf = i;
        else tree[p[i]].rg = i;
    }
    
    calvalue(root);
    cout << minchange(root) << endl;
    return 0;
}