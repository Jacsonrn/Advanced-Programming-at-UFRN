#include <iostream>


using namespace std;

int main(void)
{
  const int N=5;
  int i,j;
  double* x = new double[N];

  for (i=0; i<N; ++i)
  {
    cout << "Digite " << i+1 << " valores: ";
    {
      double* prov = new double[i+1];
      for (j=0; j<i+1; ++j) cin >> prov[j];
      double soma=0.0;
      for (j=0; j<i+1; ++j) soma += prov[j];
      x[i] = soma/(i+1);
      delete[] prov;
    }
  }
  cout << "Serie = ";
  for (i=0; i<N; ++i) cout << x[i] << ' ';
  cout << endl;

  delete[] x;
  x = nullptr;

  return 0;
}
