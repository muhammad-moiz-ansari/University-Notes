
#include <stdio.h>
#include <mpi.h>
int main(int argc,char**argv){
    int rank; int x=5;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0) x=100;
    printf("[rank %d] x=%d\n",rank,x);
    MPI_Finalize();
    return 0;
}
