#include <stdio.h>
#include <stdlib.h>
#define CL_TARGET_OPENCL_VERSION 200
#include <CL/cl.h>

#define N 1000000

const char* kernel_source = 
"__kernel void vector_add(__global const float* A,"
"                         __global const float* B,"
"                         __global float* C,"
"                         const int N)"
"{"
"    int gid = get_global_id(0);"
"    if (gid < N) {"
"        C[gid] = A[gid] + B[gid];"
"    }"
"}";

int main() {
    cl_int err;
    

    /////////////////////////////////////////////
    /////////// Create Data on CPU //////////////
    /////////////////////////////////////////////

    float *h_A = (float*)malloc(N * sizeof(float));
    float *h_B = (float*)malloc(N * sizeof(float));
    float *h_C = (float*)malloc(N * sizeof(float));
    
    for (int i = 0; i < N; i++) {
        h_A[i] = (float)i;
        h_B[i] = (float)i;
    }
    
    
    //////////////////////////////////////////////
    // OpenCL setup //////////////////////////////
    //////////////////////////////////////////////
    
    cl_platform_id platform;
    cl_device_id device;
    cl_context context;
    cl_command_queue queue;
    cl_program program;
    cl_kernel kernel;
    cl_mem d_A, d_B, d_C;
    

    ///////////////////////////////////////////////////////////////////////
    // Finds GPU platform and device, falls back to CPU if no GPU found ///
    ///////////////////////////////////////////////////////////////////////

    clGetPlatformIDs(1, &platform, NULL);
    
    // Get device
    if (clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL) != CL_SUCCESS) {
        clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &device, NULL);
        printf("Using CPU device\n");
    } else {
        printf("Using GPU device\n");
    }
    
    // A workspace that holds all your GPU resources
    context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
    
    // A FIFO line where you put commands in order
    queue = clCreateCommandQueue(context, device, 0, &err);
    
    ////////////////////////////////////////////////////////////////////////////
    // Create empty GPU memory /////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    d_A = clCreateBuffer(context, CL_MEM_READ_ONLY, N * sizeof(float), NULL, &err);
    d_B = clCreateBuffer(context, CL_MEM_READ_ONLY, N * sizeof(float), NULL, &err);
    d_C = clCreateBuffer(context, CL_MEM_WRITE_ONLY, N * sizeof(float), NULL, &err);


    ////////////////////////////////////////////////////////////////////////////
    // Copy data to device
    ////////////////////////////////////////////////////////////////////////////
    
    clEnqueueWriteBuffer(queue, d_A, CL_TRUE, 0, N * sizeof(float), h_A, 0, NULL, NULL);
    clEnqueueWriteBuffer(queue, d_B, CL_TRUE, 0, N * sizeof(float), h_B, 0, NULL, NULL);
    

    ////////////////////////////////////////////////////////////////////////////
    // Create and build program
    ////////////////////////////////////////////////////////////////////////////

    program = clCreateProgramWithSource(context, 1, &kernel_source, NULL, &err);
    clBuildProgram(program, 1, &device, NULL, NULL, NULL);
    
    // Create kernel
    kernel = clCreateKernel(program, "vector_add", &err);
    

    ////////////////////////////////////////////////////////////////////////////
    // Set kernel arguments
    ////////////////////////////////////////////////////////////////////////////

    int n = N;
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_A);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_B);
    clSetKernelArg(kernel, 2, sizeof(cl_mem), &d_C);
    clSetKernelArg(kernel, 3, sizeof(int), &n);
    
    ////////////////////////////////////////////////////////////////////////////
    // Execute kernel
    ////////////////////////////////////////////////////////////////////////////

    size_t global_size = N;
    size_t local_size = 256;
    
    clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &global_size, &local_size, 0, NULL, NULL);
    
    ////////////////////////////////////////////////////////////////////////////
    // Read result
    ////////////////////////////////////////////////////////////////////////////

    clEnqueueReadBuffer(queue, d_C, CL_TRUE, 0, N * sizeof(float), h_C, 0, NULL, NULL);
    


    // Verify (check first 10)
    printf("Verifying first 10 results:\n");
    for (int i = 0; i < 10; i++) {
        printf("C[%d] = %.0f + %.0f = %.0f\n", i, h_A[i], h_B[i], h_C[i]);
    }
    
    ////////////////////////////////////////////////////////////////////////////
    // Cleanup 
    ////////////////////////////////////////////////////////////////////////////

    clReleaseMemObject(d_A);
    clReleaseMemObject(d_B);
    clReleaseMemObject(d_C);
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);
    
    free(h_A);
    free(h_B);
    free(h_C);
    
    return 0;
}