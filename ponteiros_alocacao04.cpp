#include <iostream>
#include <ctime>

/*
Voce deve analisar este programa para verificar se ele contem erro ou nao.
Os erros que nos interessam sao exclusivamente os relacionados a ponteiros e
alocacao dinamica de memoria e nao eventuais problemas nos algoritmos do programa.
*/

using namespace std;

// Gera N (>=2) numeros aleatorios entre 0 e N-1
int main(void)
{
  int N, i;
  int* numeros(nullptr);

  srand(time(nullptr));

  do
  {
    cout << "Quantos numeros [>=2]? ";
    cin >> N;
  } while (N<2);

  numeros = new int[N];
  for (i=0; i<N; ++i)
  {
    numeros[i] = rand()%N;
  }

  cout << "Numeros = ";
  for (i=0; i<N; ++i) cout << numeros[i] << ' ';
  cout << endl;

  delete numeros;
  numeros = nullptr;

  return 0;
}
