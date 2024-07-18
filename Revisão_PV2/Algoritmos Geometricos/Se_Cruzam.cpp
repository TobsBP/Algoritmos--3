#include<iostream>
using namespace std;

struct Point {
	int x, y;
};

float area_trigulo(Point a, Point b, Point c){
	float area = a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x;
	area = area / 2;
	return area;
}

int posicao_relativa(Point a, Point b, Point p){
	float area = area_trigulo(a,b,p);
	if(area > 0) {
		return 1;
	} else if(area < 0) {
		return -1;
	} else {
		return 0;
	}
}

int main()
{
	Point p1, p2, p3, p4;

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> p4.x >> p4.y;
	
	int pos1 = posicao_relativa(p1,p2,p3);
	int pos2 = posicao_relativa(p2,p3,p4);
	int pos3 = posicao_relativa(p4,p3,p1);
	int pos4 = posicao_relativa(p3,p4,p1);

	if (pos1 != 0 && pos2 != 0 && pos3 != 0 && pos4 != 0)
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;
		
	return 0;
}