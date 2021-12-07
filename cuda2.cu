#include <iostream>
#include <math.h>


// CUDA kernel function to add elements of an array on the GPU
__global__
void add(int n, float *x, float *y){

    int index = threadIdx.x;
    int stride = blockDim.x;

    for (int i = index; i < n; i+= stride){
        y[i] = x[i] + y[i];
    }
}

int main(void){

    float *x;
    float *y;
    int N = 1<<20; 

    // Allocating memory 
    cudaMallocManaged(&x, N*sizeof(float));
    cudaMallocManaged(&y, N*sizeof(float));

    // initializing arrays on host device
    for (int i = 0; i < N; i++){
        x[i] = 1.0f;
        y[i] = 2.0f;
    }

    // now running on 256 threads
    add<<< 1, 256>>>(N, x, y);

    // Waiting for GPU to finish
    cudaDeviceSynchronize();

    float mError = 0.0f;
    // Checking for errors 
    for (int i = 0; i < N; i++){
        mError = fmax(mError, fabs(y[i] -3.0f));
    }

    std::cout << "Max Error: " << mError << std::endl;

    // free memory 
    cudaFree(x);
    cudaFree(y);
    

    return 0;
}