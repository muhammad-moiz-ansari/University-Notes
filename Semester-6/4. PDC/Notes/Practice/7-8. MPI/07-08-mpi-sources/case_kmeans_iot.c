
#include <mpi.h>
#include <stdio.h>
int main(int argc,char**argv){
    MPI_Init(&argc,&argv);
    int rank; MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0) printf("Distributed K-means placeholder\n");
    MPI_Finalize();
    return 0;
}
