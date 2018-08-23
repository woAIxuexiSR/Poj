/* 枚举所有线段，将其当作正方形的对角线，
    求得该正方形的另外两点，二分查找是否在已有点集合中 */

#include<iostream>
#include<algorithm>
using namespace std;

int n;
class Point
{
public:
    int x, y;
    Point():x(0),y(0) {}
    Point(int xx, int yy):x(xx),y(yy) {}
    bool operator<(const Point &a) const
    {
        if(x < a.x) return true;
        else if(x > a.x) return false;
        return y < a.y;
    }
};
Point p[1000];

bool check(int x, int y)
{
    Point t(x,y);
    int lf = 0, rg = n - 1;
    while(lf <= rg)
    {
        int mid = (lf + rg) / 2;
        if(p[mid].x == x && p[mid].y == y) return true;
        if(t < p[mid]) rg = mid - 1;
        else lf = mid + 1;
    }
    return false;
}

int main()
{
    while(cin >> n)
    {
        if(n == 0) break;
        for(int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;
        
        sort(p, p + n);
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
            {
                int x1 = (p[i].x + p[j].x + p[i].y - p[j].y);
                int y1 = (p[i].y + p[j].y - p[i].x + p[j].x);
                int x2 = (p[i].x + p[j].x - p[i].y + p[j].y);
                int y2 = (p[i].y + p[j].y + p[i].x - p[j].x);
                if(x1%2 != 0 || y1%2 != 0 || x2%2 != 0 || y2%2 != 0) continue;
                if(check(x1/2, y1/2) && check(x2/2, y2/2)) ans++;
            }
        cout << ans / 2 << endl; 
    }
    return 0;
}