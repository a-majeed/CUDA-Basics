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

    float *x;
    float *y;
    int N = 1<<20; 

    // Allocate Unified Memory – accessible from CPU or GPU
    cudaMallocManaged(&x, N*sizeof(float));
    cudaMallocManaged(&y, N*sizeof(float));

    for (int i = 0; i < N; i++){
        x[i] = 1.0f;
        y[i] = 2.0f;
    }
    
    // Run kernel on 1M elements on GPU
    add<<< 1, 1>>>(N, x, y);

    float mError = 0.0f;
    // Checking for errors 
    for (int i = 0; i < N; i++){
        mError = fmax(mError, fabs(y[i] -3.0f));
    }

    std::cout << "Max Error: " << mError << std::endl;

    cudaFree(x);
    cudaFree(y);
    

    return 0;


}