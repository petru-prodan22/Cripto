#include <iostream>
#include <vector>
using namespace std;
bool verif(vector<int>& numere, int suma) {
    int n = numere.size();
    vector<bool> dp(suma + 1, false);
    dp[0] = true; 
    for (int numar : numere) {
        for (int s = suma; s >= numar; --s) {
            if (dp[s - numar]) {
                dp[s] = true;
            }
        }
    }

    return dp[suma];
}


vector<int> Form_sum(vector<int>& numere, int suma) {
    int n = numere.size();
    vector<vector<int>> dp(suma + 1);
    dp[0] = vector<int>(); 

    for (int numar : numere) {
        for (int s = suma; s >= numar; --s) {
            if (!dp[s - numar].empty() || s == numar) {
                auto vects = dp[s - numar];
                vects.push_back(numar);
                dp[s] = vects;
            }
        }
    }

    return dp[suma];
}

int main() {
    vector<int> numere = { 2, 3, 7, 8, 10 };
    int suma = 11;

    if (verif(numere, suma)) {
        cout << "Se poate forma suma " << suma << " cu următoarele numere:" << endl;
        auto vectafis = Form_sum(numere, suma);
        for (int numar : vectafis) {
            cout << numar << " ";
        }
        cout << endl;
    }
    else {
        cout << "Nu se poate forma suma " << suma << " cu elementele date." << endl;
    }

    return 0;
}
