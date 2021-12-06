#include <iostream>
#include <math.h>

// creating function to add elements of an array
void add(int n, float *x, float *y){
    
    for (int i = 0; i < n; i++){
        y[i] = x[i] + y[i];
    }
}