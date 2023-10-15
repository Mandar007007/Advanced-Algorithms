#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Point
{
public:
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};
Point p0(0, 0);

void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

Point nextToTop(stack<Point> &s)
{
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;
}

int distSq(Point p1, Point p2)
{
    return (((p1.x - p2.x) * (p1.x - p2.x)) +
            ((p1.y - p2.y) * (p1.y - p2.y)));
}

int orientation(Point p, Point q, Point r)
{
    int val = ((q.y - p.y) * (r.x - q.x)) -
              ((q.x - p.x) * (r.y - q.y));
    if (val == 0)
    {
        return 0;
    }
    return (val > 0) ? 1 : 2;
}

void grahamScan(vector<Point> &points, int n)
{
    int yMin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < yMin) || (yMin == y && points[i].x < points[min].x))
        {
            yMin = points[i].y;
            min = i;
        }
    }
    swap(points[0], points[min]);
    p0 = points[0];
    sort(points.begin() + 1, points.end(), [](Point p1, Point p2)
         {
        int o = orientation(p0, p1, p2);
        if(o == 0) {
            return (distSq(p0, p2) >= distSq(p0, p1)) ? false : true;
        }
        return (o == 2) ? true : false; });

    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
        {
            i++;
        }
        points[m] = points[i];
        m++;
    }
    if (m < 3)
    {
        return;
    }
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);
    for (int i = 3; i < m; i++)
    {
        while (orientation(nextToTop(s), s.top(), points[i]) != 2)
        {
            s.pop();
        }
        s.push(points[i]);
    }
    while (!s.empty())
    {
        Point p = s.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        s.pop();
    }
}

int main()
{
    int n = 8;
    vector<Point> points;
    points.push_back(Point(0, 3));
    points.push_back(Point(1, 1));
    points.push_back(Point(2, 2));
    points.push_back(Point(4, 4));
    points.push_back(Point(0, 0));
    points.push_back(Point(1, 2));
    points.push_back(Point(3, 1));
    points.push_back(Point(3, 3));
    grahamScan(points, n);
    return 0;
}

// Output

// (0, 3)
// (3, 1)
// (0, 0)