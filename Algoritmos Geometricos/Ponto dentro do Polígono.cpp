#include <iostream>
using namespace std;
 
// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 10000
 
struct Point
{
        int x;
        int y;
};
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

void descobre(Point forma[], Point descobrir, int cont)
{
    bool encontrou = false;

    for (int i = 0; i < cont; i++)
    {
        if (forma[i].x > descobrir.x && descobrir.x < forma[i].x && forma[i].y > descobrir.y < forma[i].y)
        {
            cout << "DENTRO" << endl;
            encontrou = true;
        }
    }

    if (encontrou == false)
    {
        cout << "!(DENTRO)" << endl;
    }
    
}
 
// Prints convex hull of a set of n points.
void gift_wraping(Point points[], int n, Point find)
{
    // There must be at least 3 points
    if (n < 3)
        return;
 
    // Initialize Result
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;
 
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
 
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again
    int p = l, q;
    do
    {
        // Search for a point 'q' such that orientation(p, i, q) is
        // counterclockwise for all points 'i'
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
 
        next[p] = q; // Add q to result as a next point of p
        p = q; // Set p as q for next iteration
    }
    while (p != l);
 
    // Print Result
    Point res[100];
    int cont = 0;

    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1) {
            cout << "(" << points[i].x << ", " << points[i].y << ")\n";
            res[cont] = {points[i].x, points[i].y};
            cont++;
        }
    }

    descobre(res, find, cont);
}
 
// Driver program to test above functions
int main()
{
    Point points[100];
    Point find;
    int nPontos;

    cin >> nPontos;

    for (int i = 0; i < nPontos; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    cin >> find.x >> find.y;

    gift_wraping(points, nPontos, find);



    return 0;
}