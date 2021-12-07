#include <iostream>
#include <math.h>


// CUDA kernel function to add elements of an array on the GPU
__global__
void add(int n, float *x, float *y){

    for (int i = 0; i < n; i++){
        y[i] = x[i] + y[i];
    }
}

int main(void){

    int N = 1<<20; 
    float *x = new float [N];
    float *y = new float [N];

    for (int i = 0; i < N; i++){
        x[i] = 1.0f;
        y[i] = 2.0f;
    }

    add (N, x, y);

    float mError = 0.0f;

    for (int i = 0; i < N; i++){
        mError = fmax(mError, fabs(y[i] -3.0f));
    }

    std::cout << "Max Error: " << mError << std::endl;

    delete [] x;
    delete [] y;

    return 0;


}