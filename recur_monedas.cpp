#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int monedasRec(int d, const vector<int>& m, int i,
               vector<int>& s) {
    if (d == 0) {
        return 0;
    }

    if (d < 0 || i < 0) {
        return INF;
    }

    // Opción 1: no usar la moneda m[i]
    vector<int> s1(m.size(), 0);
    int sinUsar = monedasRec(d, m, i - 1, s1);

    // Opción 2: usar la moneda m[i]
    int usando = INF;
    vector<int> s2(m.size(), 0);

    if (m[i] <= d) {
        usando = monedasRec(d - m[i], m, i, s2);

        if (usando < INF) {
            usando++;
            s2[i]++;
        }
    }

    if (sinUsar <= usando) {
        s = s1;
        return sinUsar;
    } else {
        s = s2;
        return usando;
    }
}

void monedas(int d, vector<int> m, vector<int>& s) {
    s.assign(m.size(), 0);

    if (d < 0 || m.empty()) {
        return;
    }

    int resultado = monedasRec(d, m, (int)m.size() - 1, s);

    if (resultado >= INF) {
        s.assign(m.size(), 0);
    }
}

int main() {
    vector<int> m = {2, 3, 5};
    vector<int> s;

    monedas(6, m, s);

    for (int i = 0; i < (int)s.size(); i++) {
        cout << "Monedas de " << m[i] << ": " << s[i] << '\n';
    }

    return 0;
}
