#include <iostream>
using namespace std; 

int main(){
    double number = 1.0;
    double *nP = &number;
    double &nR = number;


    number = 5.0;
     cout << "Method 1 = " << number << endl;

    nR = 10.0;
    cout << "Method 2 = " << number << endl;

    *nP = 15.0;
    cout << "Method 3 = " << number << endl;

    return 0;
}