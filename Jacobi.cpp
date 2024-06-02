#include <iostream>
using namespace std;

int modulo(int a, int n) {
    return a % n;
}

int SimbolulJacobi(int a, int n) {
    if (n <= 0 || n % 2 == 0) {
        cerr << "n trebuie sa fie un numar impar pozitiv." << endl;
        return 0;
    }
    a = modulo(a, n);
    int jac = 1;
    while (a != 0) {
        while (a % 2 == 0) {
            a /= 2;
            int n_mod_8 = n % 8;
            if (n_mod_8 == 3 || n_mod_8 == 5) {
                jac = -jac;
            }
        }
        swap(a, n);
        if (a % 4 == 3 && n % 4 == 3) {
            jac = -jac;
        }
        a = modulo(a, n);
    }
    return (n == 1) ? jac : 0;
}

int main() {
    int a, n;
    cout << "Introduceti valorile pentru a si n: ";
    cin >> a >> n;

    int simbol = SimbolulJacobi(a, n);
    cout << "Simbolul Jacobi (" << a << "/" << n << ") este " << simbol << endl;

    return 0;
}
