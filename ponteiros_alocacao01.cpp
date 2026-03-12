#include <iostream>
#include <cmath>



using namespace std;

// Calcula a raiz quadrada de um numero inteiro
int main(void)
{
  int N;
  double* x = nullptr;

  do
  {
    cout << "Numero [>0]? ";
    cin >> N;
  } while (N<=0);

  x = new double;
  *x = sqrt(N);
  cout << "Raiz = " << *x << endl;

  delete x;
  return 0;
}
