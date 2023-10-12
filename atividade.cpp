#include <iostream>
#include <cmath>

using namespace std;

void multiplo(int num){
    if(num%4==0){
        cout << "Este numero eh multiplo de 4" << endl;
    }
    else{
        cout << "este numero nao eh multiplo de 4" << endl;
    }
}

void parouimpar(int num){
    if(num%2==0){
        cout << "este numero eh par" << endl;
    }
    else{
        cout << "este numero eh impar" << endl;
    }
}

int somasequencia(int primeiro, int segundo){
    int soma=0;
    if(primeiro<segundo){
        for(primeiro; primeiro<=segundo; primeiro++){
            soma+=primeiro;
        }
        return soma;
    }
    else{
        for(segundo; segundo<=primeiro; segundo++){
            soma+=segundo;
        }
        return soma;
    }
}

int volume(double raio){
    double resultado, pi;
    pi=M_PI;
    resultado=(4*pi*(pow(raio,3)))/3;
    return resultado;
}

int fatorial(int num){
    int fatorial=1;
    if(num>0){
        for(num; num>0; num--){
            fatorial*=num;
        }
        return fatorial;
    }
}

int elevar(int num, int elevado){
    int total=1;
    for(elevado; elevado>0; elevado--){
        total*=num;
    }
    return total;
}

int main(){
    int num=0, primeiro, segundo, elevado;
    double raio;
    
    cout << "selecione um numero para verificar se ele eh multiplo de 4, se ele eh par ou impar, e para fazer seu fatorial" << endl;
    cin >> num;
    multiplo(num);
    parouimpar(num);
    cout << fatorial(num) << endl;
    
    cout << "escolha dois numeros para fazer a soma da sequancia entre ester numeros" << endl;
    cin >> primeiro >> segundo;
    cout << somasequencia(primeiro, segundo) << endl;
    
    cout << "escolha o raio para fazer o calculo do volume da esfera" << endl;
    cin >> raio;
    cout << volume(raio) << endl;
    
    cout << "escolha um numero para que aquele primeiro escolhido seja elevado" << endl;
    cin >> elevado;
    cout << elevar(num, elevado) << endl;
}

//1. Funções: é uma seção que independe do código, e tem como função resolver subproblemas.
//2. Argumento/parametros: Uma das formas de declaração de variável no escopo de uma função.
//3. Tipos de funções: são tipos de funções as que retornam um valor e as que não retornam. As que retonam valor devem
//   ser chamadas de int e ter return, já as que não tem retorno são chamadas de void.
//4. Void: Siginifica que esta função não tem retorno de algum valor
//5. Se a função retornar um valor por meio da instrução return, o valor de retorno deve ser especificado entre parênteses
//   (parâmetro da instrução) ou ser resultante de uma expressão (lógica ou aritmética) válida.
//6. O tipo de retono a uma função é o return.