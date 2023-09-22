#include <iostream>
using namespace std; 


int find_sum(const int *table, int length){
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum+= table[i];
    }
    return sum;
}

int main(){


     int ints[20]; 
     int numberOfElements = sizeof(ints) / sizeof(ints[0]);


    //populate ints with integers upto 20
    for (int i = 1; i < numberOfElements + 1; i++){
        ints[i-1] = i;
    }


    cout << "There are "<< numberOfElements<< " numbers generated "<< endl;

    // sum of the first 10 numbers
    cout << "The sum of the first 10 numbers = " << find_sum(ints, 10) << endl;
    cout << "The sum of the next 5 numbers = " <<   find_sum(&ints[10], 5) << endl;
    cout << "The sum of the last 5 numbers = " <<   find_sum(&ints[numberOfElements-5], 5) << endl;

    return 0;
}