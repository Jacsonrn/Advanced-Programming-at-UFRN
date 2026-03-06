#include <iostream>
using namespace std;

int main(){
double numero = 0, soma = 0;
int contador = 1;

while(numero >=0){
    cout << "Digite o "<<contador<<"o"<< "numero:"<<endl;  
    cin >> numero;
if(numero >= 0){
    soma += numero;
    
}else{
double media = soma/(contador-1);
    cout << "A media eh:"<<media<<endl;
}
contador++;
}

return 0;    
}