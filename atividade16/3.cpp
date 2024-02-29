#include <iostream>

using namespace std;

#include <iostream>

void original(double preco, double desconto, double taxaEnvio){

    double precoFinal = preco - (preco * desconto) + (preco * taxaEnvio);
    cout << "Preco final do codigo original: " << precoFinal << endl;
}


int main(){
    double preco = 100.0;
    double desconto = 0.1;
    double taxaEnvio = 0.05;

    original(preco, desconto, taxaEnvio);

    double valorDesconto = preco * desconto;
    double valorTaxaEnvio = preco * taxaEnvio;
    double precoFinal = preco - valorDesconto + valorTaxaEnvio;
    cout << "Preco final do codigo refatorado: " << precoFinal << endl;
}