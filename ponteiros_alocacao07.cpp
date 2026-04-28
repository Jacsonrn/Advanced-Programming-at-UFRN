#include <iostream>

/*
Voce deve analisar este programa para verificar se ele contem erro ou nao.
Os erros que nos interessam sao exclusivamente os relacionados a ponteiros e
alocacao dinamica de memoria e nao eventuais problemas nos algoritmos do programa.
*/

using namespace std;

// Solicita ao usuario a digitacao de N numeros (N>=3) e armazena em "orig"
// Em seguida, calcula nova serie "media", na qual os elementos da extremidade
// de "media" sao iguais aos elementos correspondentes em "orig" e
// os demais elementos de "media" sao a media de 3 elementos em "orig": o
// correpondente, o anterior e o seguinte.
int main(void)
{
  int N,i;
  double *orig(nullptr), *media(nullptr);

  do
  {
    cout << "Quantos numeros [>=3]? ";
    cin >> N;
  } while (N<3);

  orig = new double[N];
  for (i=0; i<N; ++i)
  {
    cout << "Elemento indice " << i << ": ";
    cin >> orig[i];
  }

  media = orig;
  // Calcula apenas os elementos que nao sao das extremidades (de 1 a N-2)
  for (i=1; i<N-1; ++i)
  {
    media[i] = (orig[i-1]+orig[i]+orig[i+1])/3.0;
  }

  cout << "Media = ";
  for (i=0; i<N; ++i) cout << media[i] << ' ';
  cout << endl;

  delete[] orig;
  delete[] media;
  orig = media = nullptr;

  return 0;
}
