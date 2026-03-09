#include <iostream>
using namespace std;

int main(){
int i, j, *p;
i = 4;
j = 7;
p = &j;
*p = 9;
cout << i << ' ' << j << ' ' << *p;
return 0;
}