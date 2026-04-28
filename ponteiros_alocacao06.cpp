#include <iostream>

/*
Voce deve analisar este programa para verificar se ele contem erro ou nao.
Os erros que nos interessam sao exclusivamente os relacionados a ponteiros e
alocacao dinamica de memoria e nao eventuais problemas nos algoritmos do programa.
*/

using namespace std;

// Gera os N primeiros termos da serie de Fibonacci (N >= 0)
// Os 2 primeiros sao 1, os demais sao a soma dos 2 anteriores
int main(void)
{
  int N,i;
  double* x = nullptr;

  do
  {
    cout << "Quantos numeros [>=0]? ";
    cin >> N;
  } while (N<0);

  x = new double[N];
  for (i=0; i<N; ++i)
  {
    if (i<2) x[i] = 1.0;
    else x[i] = x[i-1]+x[i-2];
  }
  cout << "Serie = ";
  for (i=0; i<N; ++i) cout << x[i] << ' ';
  cout << endl;

  delete[] x;
  x = nullptr;

  return 0;
}
