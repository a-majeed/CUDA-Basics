# CUDA Basics

This program computes in parallel the addition of 2 arrays with one million elemnts each. The first iteration only uses a single CUDA thread. Afterwards, alterations are made in cuda2.cu and cuda3.cu in order to utilize a single CUDA block and multiple CUDA blocks. 

## Results

| Version | Time | Bandwidth |
| ------------- | ------------- | ------------- |
| 1 CUDA Thread  | 438ms | 32.8 MB/s  |
| 1 CUDA Block | 3.7ms  | 3.4 GB/s  |
| MUltiple CUDA Blocks | 0.8ms  | 17.6 GB/s |


### Summary

As a result, when utilizing more threads and blocks, performance increases exponentially. This is because the processor can process more instructions simultaneously. 
