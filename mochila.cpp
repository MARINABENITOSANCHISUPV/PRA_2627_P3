
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int cambio(int M, const vector<int>& v, int n) {
    if (M == 0) {
        return 0;
    }

    if (M < 0 || n == 0) {
        return INF;
    }

    // Opción 1: no usar la moneda v[n-1]
    int sinUsar = cambio(M, v, n - 1);

    // Opción 2: usar la moneda v[n-1]
    int usando = INF;

    if (v[n - 1] <= M) {
        usando = 1 + cambio(M - v[n - 1], v, n);
    }

    return min(sinUsar, usando);
}

int main() {
    vector<int> v = {1, 4, 6};
    int M = 8;

    int resultado = cambio(M, v, v.size());

    if (resultado >= INF) {
        cout << "No existe solucion" << endl;
    } else {
        cout << "Minimo numero de monedas: "
             << resultado << endl;
    }

    return 0;
}

