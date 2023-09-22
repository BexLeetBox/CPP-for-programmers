#include <iostream>
using namespace std; 

int main(){
    int i = 3;
    int j = 5; 
    int *p = &i;
    int *q = &j;

    cout << "Address of i: " << &i << " Value of i: " << i << endl;
    cout << "Address of j: " << &j << " Value of j: " << j << endl;
    cout << "Address stored in p: " << p << " Value pointed by p: " << *p << endl;
    cout << "Address stored in q: " << q << " Value pointed by q: " << *q << endl;


    cout << "Oppgave 1 B)----------------------------------------------------" << endl;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << *p << " " << *q << endl;



    return 0;
}