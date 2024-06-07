#include <iostream>
#include <cmath>
using namespace std;

#define INF 10000

struct Point {
    int x;
    int y;
};

// To find the orientation of an ordered triplet (p, q, r).
// The function returns the following values:
// 0 --> p, q, and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclockwise
}

float calcularDistancia(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Prints the convex hull of a set of n points.
void gift_wrapping(Point points[], int n) {
    // There must be at least 3 points
    if (n < 3) return;

    // Initialize Result
    int next[n];
    for (int i = 0; i < n; i++) next[i] = -1;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from the leftmost point, keep moving counterclockwise
    // until reaching the start point again
    int p = l, q;
    do {
        // Search for a point 'q' such that orientation(p, i, q) is
        // counterclockwise for all points 'i'
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;

        next[p] = q; // Add q to the result as the next point of p
        p = q; // Set p as q for the next iteration
    } while (p != l);

    // Print Result
    float distance = 0.0; // Initialize distance
    Point res[100];
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (next[i] != -1) {
            cout << "(" << points[i].x << ", " << points[i].y << ")\n";
            res[cont] = {points[i].x, points[i].y};
            cont++;
        }
    }

    for (int i = 0; i < cont; i++) {
        distance += calcularDistancia(res[i].x, res[i].y, res[(i + 1) % cont].x, res[(i + 1) % cont].y);
    }

    cout << distance << endl;
}

// Driver program to test the above functions
int main() {
    Point points[100];
    int nPontos;

    cin >> nPontos;

    for (int i = 0; i < nPontos; i++) {
        cin >> points[i].x >> points[i].y;
    }

    gift_wrapping(points, nPontos);

    return 0;
}
