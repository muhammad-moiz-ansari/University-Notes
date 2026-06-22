
#include <mpi.h>
#include <stdio.h>
int main(int argc,char**argv){
    int rank;
    MPI_Request req;
    int buf[100000];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0){
        MPI_Isend(buf,100000,MPI_INT,1,0,MPI_COMM_WORLD,&req);
        MPI_Wait(&req,MPI_STATUS_IGNORE);
    } else {
        MPI_Irecv(buf,100000,MPI_INT,0,0,MPI_COMM_WORLD,&req);
        MPI_Wait(&req,MPI_STATUS_IGNORE);
    }
    MPI_Finalize();
    return 0;
}
