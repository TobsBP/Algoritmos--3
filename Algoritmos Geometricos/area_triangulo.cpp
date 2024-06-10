#include<iostream>
#include<iomanip>
using namespace std;

struct Point {
	int x, y;
};

float area_trigulo(Point a, Point b, Point c){
	float area = a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x;
	area = area / 2;
	return area;
}

int main()
{
	Point p1, p2, p3;

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    cout << setprecision(1) << fixed;
    cout << area_trigulo(p1, p2, p3);

	return 0;
}