#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int d = 2;   //for setting the address of b to an address that has the value 2
    int &b = d; //  Must initialize reference when declaring
    int *c; 


    c = &b;
    a = b + *c;  // a and b are integers and not pointers
    //&b = 2;  //address cannot be changed once initialized


    cout << "Value of a: " << a << endl;  // To get rid of the warning "variable ‘a’ set but not used "
    return 0;
}