#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double principal = 1000.0;
    double taxa = 0.05;
    double periodo = 2.0;

    double montante = principal * pow(1 + taxa, periodo);
    cout << "O montante eh: " << montante << endl;
}
