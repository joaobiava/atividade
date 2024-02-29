#include <iostream>

using namespace std;

bool isVeryHot(int temperatura);
bool isHot(int temperatura);
bool isCool(int temperatura);

void printtemperaturaMessage(int temperatura) {
    if (isVeryHot(temperatura))
        cout << "Muito quente!";
    else if (isHot(temperatura))
        cout << "Clima agradável.";
    else if (isCool(temperatura))
        cout << "Fresco.";
    else
        cout << "Muito frio!";
    
}

bool isVeryHot(int temperatura) {
    return temperatura > 100;
}

bool isHot(int temperatura) {
    return temperatura > 70;
}

bool isCool(int temperatura) {
    return temperatura > 50;
}

int main() {
    int temperatura;
    
    cin >> temperatura;
    printtemperaturaMessage(temperatura);
}
