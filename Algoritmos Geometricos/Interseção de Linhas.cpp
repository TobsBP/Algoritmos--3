#include<iostream>
using namespace std;

struct Point {
    int x, y;
};

// Função para calcular a orientação de três pontos (a, b, c)
// Retorna:
// 0 -> a, b e c são colineares
// 1 -> Sentido horário
// -1 -> Sentido anti-horário
int orientacao(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

bool seCruzam(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientacao(p1, q1, p2);
    int o2 = orientacao(p1, q1, q2);
    int o3 = orientacao(p2, q2, p1);
    int o4 = orientacao(p2, q2, q1);

    if (o1 != o2 && o3 != o4) // Tem que ter a orientação diferente para se cruzarem
        return true;

    return false;
}

int main() {
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    if (seCruzam(p1, p2, p3, p4))
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;

    return 0;
}
