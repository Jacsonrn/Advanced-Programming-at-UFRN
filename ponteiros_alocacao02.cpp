#include <iostream>


using namespace std;


int main(void)
{
  int N,i;
  double* x(nullptr);

  do
  {
    cout << "Ateh qual termo [>=2]? ";
    cin >> N;
  } while (N<2);

  x = new double[N+1];
  for (i=0; i<=N; ++i)
  {
    if (i<2) x[i] = 1.0;
    else x[i] = x[i-1]+x[i-2];
  }
  cout << "Serie = ";
  for (i=0; i<=N; ++i) cout << x[i] << ' ';
  cout << endl;

  delete[] x;
  x = nullptr;

  return 0;
}
