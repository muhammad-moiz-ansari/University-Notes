
#include <mpi.h>
#include <stdio.h>
int main(int argc,char**argv){
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    double t0=MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    double t1=MPI_Wtime();
    if(rank==0) printf("Barrier time=%f with %d ranks\n",t1-t0,size);
    MPI_Finalize();
    return 0;
}
