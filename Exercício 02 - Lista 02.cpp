#include <iostream>
using namespace std;

int main(){
    /* esse trecho de programa está errado */
int i, *p;
i = 10;
*p = i;
cout << *p;
return 0;
}