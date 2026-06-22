
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>
int main(int argc,char**argv){
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int N=1000000/size;
    double *a=malloc(N*sizeof(double));
    for(int i=0;i<N;i++) a[i]=1.0;
    double sum=0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<N;i++) sum+=a[i];
    double global;
    MPI_Allreduce(&sum,&global,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
    if(rank==0) printf("Hybrid sum=%f\n",global);
    MPI_Finalize();
    return 0;
}
