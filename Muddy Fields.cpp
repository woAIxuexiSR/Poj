/* 匈牙利算法，二部图 -> 最大点覆盖 = 最大匹配 */
#include<iostream>
#include<cstring>
using namespace std;
int r,c;
int matrix[50][50];
int rcnt,ccnt;
int rmat[50][50],cmat[50][50];
bool g[1025][1025];
bool visited[1025];
int cx[1025],cy[1025];

bool dfs(int u)
{
    for(int i = 0;i < ccnt; ++i)
    {
        if(g[u][i] && !visited[i])
        {
            visited[i] = 1;
            if(cy[i] == -1 || dfs(cy[i]))
            {
                cx[u] = i; cy[i] = u;
                return true;
            }
        }
    }
    return false;
}

int maxmatch()
{
    int ans = 0;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    for(int i = 0; i < rcnt; ++i)
        if(cx[i] == -1)
        {
            memset(visited,0,sizeof(visited));
            if(dfs(i)) ++ans;
        }
    return ans;
}

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

    rcnt = ccnt = 0;
    for(int i = 0;i < r;++i)
    {
        bool flag = 0;
        for(int j = 0;j < c;++j)
        {
            if(matrix[i][j] == 0 && !flag)
                flag = 1, rmat[i][j] = rcnt++;
            else if(matrix[i][j] == 0 && flag)
                rmat[i][j] = rcnt - 1;
            else
                flag = 0;
        }
    }

    for(int j = 0;j < c;++j)
    {
        bool flag = 0;
        for(int i = 0;i < r;++i)
        {
            if(matrix[i][j] == 0 && !flag)
                flag = 1, cmat[i][j] = ccnt++;
            else if(matrix[i][j] == 0 && flag)
                cmat[i][j] = ccnt - 1;
            else
                flag = 0;
        }
    }

    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            if(matrix[i][j]==0)
            {
                g[rmat[i][j]][cmat[i][j]] = 1;
            }

    cout << maxmatch() << endl;
    return 0;
}