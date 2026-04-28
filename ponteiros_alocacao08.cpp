#include <iostream>
#include <ctime>

/*
Voce deve analisar este programa para verificar se ele contem erro ou nao.
Os erros que nos interessam sao exclusivamente os relacionados a ponteiros e
alocacao dinamica de memoria e nao eventuais problemas nos algoritmos do programa.
*/

using namespace std;

// Gera cadeias de caracteres aleatorios de tamanho crescente
// A cadeia aumenta de tamanho ateh que o usuario decida parar
int main(void)
{
  int N=0, i;
  char *cadeia = nullptr, opcao;

  srand(time(nullptr));

  do
  {
    N++;
    cadeia = new char[N+1]; // Um char a mais (N+1) para conter o \0 final
    for (i=0; i<N; ++i) cadeia[i] = 'A' + rand()%26;  // Gera de 'A' a 'Z'
    cadeia[N] = '\0';
    cout << "Cadeia = " << cadeia << endl;
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
