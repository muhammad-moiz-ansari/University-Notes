
#include <mpi.h>
#include <stdio.h>
int main(int argc,char**argv){
    int rank;
    MPI_Request req;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    long long local=rank,global;
    MPI_Ireduce(&local,&global,1,MPI_LONG_LONG,MPI_SUM,0,MPI_COMM_WORLD,&req);
    MPI_Wait(&req,MPI_STATUS_IGNORE);
    if(rank==0) printf("Ireduce sum=%lld\n",global);
    MPI_Finalize();
    return 0;
}
