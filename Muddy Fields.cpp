#include<iostream>
using namespace std;
int r,c;
int matrix[50][50];
int main()
{
    cin >> r >> c;
    char s;
    for(int i = 0;i < r;++i)
    {   
        cin.get();
        for(int j = 0;j < c;++j)
        {
           cin.get(s);
           if(s=='.') matrix[i][j] = 1;
           else matrix[i][j] = 0; 
        }
    }
    
    return 0;
}