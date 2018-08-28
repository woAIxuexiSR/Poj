/* 哪错了 */


#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int m, n;
char matrix[102][102];
class Pos {
public:
    int x, y, t;
    int s, k;
    Pos(int xx, int yy, int tt, int ss, int kk):x(xx),y(yy),t(tt),s(ss),k(kk) {}
    Pos() {}
};
int sx[5], sy[5];
bool vis[102][102][32][10];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int getsnum(int x, int y)
{
    for(int i = 0; i < 5; ++i)
        if(sx[i] == x && sy[i] == y)
            return i;
    return -1;
}
int main()
{
    while(scanf("%d %d", &n, &m)) {
        if(n == 0 && m == 0) break;
        memset(vis, 0, sizeof(vis));
        char u; scanf("%c", &u);
        int startx, starty, endx, endy;
        int scnt = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%c", &matrix[i][j]);
                if(matrix[i][j] == 'K') {
                    startx = i; starty = j;
                    matrix[i][j] = '.';
                }
                if(matrix[i][j] == 'T') {
                    endx = i; endy = j;
                    matrix[i][j] = '.';
                }
                if(matrix[i][j] == 'S') {
                    sx[scnt] = i; sy[scnt] = j; scnt++;
                }
            }
            scanf("%c", &u);
        }
        for(int i = 0; i <= n + 1; ++i) matrix[i][0] = matrix[i][n + 1] = '#';
        for(int i = 0; i <= n + 1; ++i) matrix[0][i] = matrix[n + 1][i] = '#';

        queue<Pos> q;
        q.push(Pos(startx, starty, 0, 0, 0));
        vis[startx][starty][0][0] = 1;
        bool flag = 0;
        while(!q.empty()) {
            Pos t = q.front(); q.pop();
            if(t.x == endx && t.y == endy && t.k == m) {
                flag = 1;
                cout << t.t << endl; break;
            }

            if(matrix[t.x][t.y] == 'S') {
                int snum = getsnum(t.x,t.y);
                if( !(t.s & (1 << snum)) ) {
                    vis[t.x][t.y][t.s | (1 << snum)][t.k] = 1;
                    q.push(Pos(t.x, t.y, t.t + 1, t.s | (1 << snum), t.k));
                    continue;                
                }
            }
            for(int i = 0; i < 4; ++i) {
                int xx = t.x + dx[i], yy = t.y + dy[i];
                if(matrix[xx][yy] == '#') continue;
                if(matrix[xx][yy] == '.' || matrix[xx][yy] == 'S') {
                    if(!vis[xx][yy][t.s][t.k]) {
                        vis[xx][yy][t.s][t.k] = 1;
                        q.push(Pos(xx, yy, t.t + 1, t.s, t.k));
                    }
                }
                else {
                    if(matrix[xx][yy] - '0' == t.k + 1) {
                        if(!vis[xx][yy][t.s][t.k + 1]) {
                            vis[xx][yy][t.s][t.k + 1] = 1;
                            q.push(Pos(xx, yy, t.t + 1, t.s, t.k + 1));
                        }
                    }
                    else if(!vis[xx][yy][t.s][t.k]) {
                        vis[xx][yy][t.s][t.k] = 1;
                        q.push(Pos(xx, yy, t.t + 1, t.s, t.k));
                    }
                }
            }
        }
        if(!flag) cout << "impossible" << endl;
    }
    return 0;
}