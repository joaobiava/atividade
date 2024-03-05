#include <iostream>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

bool dataAntes(const Data& data1, const Data& data2) {
    if (data1.ano < data2.ano) return true;
    if (data1.ano == data2.ano && data1.mes < data2.mes) return true;
    if (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia < data2.dia) return true;
    return false;
}

int main() {
    Data data1, data2;

    cout << "Digite a primeira data (dia mes ano): ";
    cin >> data1.dia >> data1.mes >> data1.ano;
    cout << "Digite a segunda data (dia mes ano): ";
    cin >> data2.dia >> data2.mes >> data2.ano;

    if (dataAntes(data1, data2)) {
        cout << "A primeira data é anterior à segunda." << endl;
    } else {
        cout << "A primeira data não é anterior à segunda." << endl;
    }

    return 0;
}