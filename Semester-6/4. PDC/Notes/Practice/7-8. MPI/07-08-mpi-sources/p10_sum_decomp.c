
#include <stdio.h>
#include <mpi.h>
int main(int argc,char**argv){
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    long long local=rank;
    long long global;
    MPI_Allreduce(&local,&global,1,MPI_LONG_LONG,MPI_SUM,MPI_COMM_WORLD);
    if(rank==0) printf("Sum=%lld\n",global);
    MPI_Finalize();
    return 0;
}
