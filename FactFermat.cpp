#include <iostream>
#include <cmath>
using namespace std;

bool EstePrim(long long number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (long long i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

void FactorizareFermat(long long number) {
    if (EstePrim(number)) {
        cout << number << " este un numar prim." << endl;
        return;
    }

    long long x = ceil(sqrt(number));
    long long y2 = x * x - number;
    long long y = sqrt(y2);

    while (y * y != y2) {
        x += 1;
        y2 = x * x - number;
        y = sqrt(y2);
    }

    long long factor1 = x + y;
    long long factor2 = x - y;

    cout << "Factorii lui " << number << " sunt " << factor1 << " si " << factor2 << endl;
}

int main() {
    long long num;
    cout << "Introduceti un numar pentru factorizare: ";
    cin >> num;
    FactorizareFermat(num);
    return 0;
}
