#include <iostream>
#include <ctime>

/*
Voce deve analisar este programa para verificar se ele contem erro ou nao.
Os erros que nos interessam sao exclusivamente os relacionados a ponteiros e
alocacao dinamica de memoria e nao eventuais problemas nos algoritmos do programa.
*/

using namespace std;

// Gera cadeias de inteiros aleatorios de tamanho crescente
// A cadeia aumenta de tamanho ateh que o usuario decida parar
int main(void)
{
  int N=0;
  int* cadeia = nullptr;
  int i;
  char opcao;

  srand(time(nullptr));

  do
  {
    {
      int* prov = new int[N+1];
      for (i=0; i<N; ++i) prov[i] = cadeia[i]; // Copia os N inteiros
      prov[N] = rand()%10;  // Gera de 0 a 9 no ultimo
      N++;
      cadeia = prov;
      delete[] prov;
    }
    cout << "Cadeia = ";
    for (i=0; i<N; i++) cout << cadeia[i];
    cout << endl;
    do
    {
      cout << "Deseja continuar [S/N]? ";
      cin >> opcao;
      opcao = toupper(opcao);
    } while (opcao!='S' && opcao!='N');
  } while (opcao=='S');

  delete[] cadeia;
  cadeia = nullptr;

  return 0;
}
