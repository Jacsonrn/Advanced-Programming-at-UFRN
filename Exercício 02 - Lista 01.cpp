#include <iostream>
using namespace std;
double realizaoperacoes(double numero1, double numero2, char operacao);

int main(){
char operacao = '0';
double numero1 = 0, numero2 = 0, resultado = 0;
    cout << "Qual o primeiro numero:"<<endl;
    cin >> numero1;
    cout << "Qual o segundo numero:"<<endl;
    cin >> numero2;
    cout << "Qual a operacao?:"<<endl;
    cin >> operacao;
    resultado = realizaoperacoes(numero1, numero2, operacao);
    cout << resultado;

return 0;    
}

double realizaoperacoes(double numero1, double numero2, char operacao){
double soma = 0;
while(operacao == '+' || operacao == '-' || operacao == '*' || operacao == '/'){
    if(operacao == '+'){
    soma = (numero1 + numero2);
};
    if(operacao == '-'){
    soma = (numero1 - numero2);
};
    if(operacao == '*'){
    soma = (numero1 * numero2);
};
    if(operacao == '/'){
    soma = (numero1 / numero2);
};
return soma;
}
    
}