#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    int n; string str;
    stack<int> s;
    while(cin >> n)
    {
        cin >> str;
        for(int i = 0; i < n; ++i)
        {
            if(str[i] == '1') s.push(i + 1);
            else{
                cout << s.top() << " ";
                s.pop();
            }
        }
        cout << endl;
    }
    return 0;
}