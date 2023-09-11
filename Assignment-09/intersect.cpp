#include<bits/stdc++.h>

using namespace std;

class Point {
public:
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {}

};

int direction(Point pi, Point pj, Point pk) {
    int D = ((pk.x-pi.x)*(pj.y-pi.y)) - ((pk.y-pi.y)*(pj.x-pi.x));
    if(D == 0)
        return 0;
    if(D > 0)
        return 1;
    return -1;
}

bool onSegment(Point pi, Point pj, Point pk) {
    if((pk.x >= min(pi.x, pj.x)) &&
        (pk.x <= max(pi.x, pj.x)) &&
        (pk.y >= min(pi.y, pj.y)) &&
        (pk.y <= max(pi.y, pj.y)))
        return true;
    return false;
}

bool intersect(Point p, Point q, Point r, Point s) {
    int d1 = direction(p,q,r);
    int d2 = direction(p,q,s);
    int d3 = direction(r,s,p);
    int d4 = direction(r,s,q);
    
    cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
    
    if((d1*d2) < 0 && (d3*d4) < 0) 
        return true;
    if(d1 == 0 && onSegment(p,q,r))
        return true;
    if(d2 == 0 && onSegment(p,q,s))
        return true;
    if(d3 == 0 && onSegment(r,s,p))
        return true;
    if(d4 == 0 && onSegment(r,s,q))
        return true;
    return false;
}

// int direction()

int main() {
    vector<Point> points;
     
    // intersecting points
    // points.push_back(Point(1, 1));
    // points.push_back(Point(4, 8));
    // points.push_back(Point(2, 6));
    // points.push_back(Point(6, 3));
    
    // not intersecting points
    // points.push_back(Point(1, 1));
    // points.push_back(Point(3, 3));
    // points.push_back(Point(5, 5));
    // points.push_back(Point(8, 8));
    
    
    // Onsegment example
    points.push_back(Point(1, 1));
    points.push_back(Point(8, 8));
    points.push_back(Point(3, 6));
    points.push_back(Point(5, 5));
    
    cout << intersect(points[0], points[1], points[2], points[3]);

    return 0;
}
