#include <iostream>
#include <ctime>

/*
Voce deve analisar este programa para verificar se ele contem erro ou nao.
Os erros que nos interessam sao exclusivamente os relacionados a ponteiros e
alocacao dinamica de memoria e nao eventuais problemas nos algoritmos do programa.
*/

using namespace std;

// Acrescenta o caractere digitado a uma cadeia de caracteres
// ateh que o usuario decida parar digitando 'X'
int main(void)
{
  int N=0;
  char* cadeia = new char[N+1];
  char opcao;

  cadeia[N] = '\0'; // Ultima posicao tem que ser \0
  do
  {
    cout << "Cadeia atual = " << cadeia << endl;
    cout << "Proximo caractere [X para terminar]: ";
    cin >> opcao;
    if (opcao != 'X')
    {
      char* prov = new char[N+2];
      for (int i=0; i<N; ++i) prov[i] = cadeia[i]; // Copia os N caracteres
      prov[N] = opcao; // Acrescenta o caractere digitado na penultima posicao
      N++;
      prov[N] = '\0';  // Ultima posicao tem que ser \0
      delete[] cadeia;
      cadeia = prov;
    }
  } while (opcao!='X');

  delete[] cadeia;
  cadeia = nullptr;

  return 0;
}
