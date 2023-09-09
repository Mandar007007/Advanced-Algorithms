#include <bits/stdc++.h>
using namespace std;

class point
{
public:
    int x;
    int y;
    point(int x, int y) : x(x), y(y) {}
};

int main()
{
    vector<point> points;
    points.push_back(point(0, 0));
    points.push_back(point(3, 3));
    points.push_back(point(-2, 10));

    int n = points.size();
    int x = 0, y = 0;
    double minDist = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double ans = sqrt(pow((points[i].x - points[j].x), 2) + pow((points[i].y - points[j].y), 2));
            if (minDist > ans)
            {
                minDist = ans;
                x = i;
                y = j;
            }
        }
    }

    cout << "The closest pair of points are: (" << points[x].x << ", " << points[x].y << ") and (" << points[y].x << ", " << points[y].y << ")" << endl;

    return 0;
}

// Output:
// The closest pair of points are: (0, 0) and (3, 3)